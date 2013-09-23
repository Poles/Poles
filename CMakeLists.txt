# CMake minimun version required to compile
cmake_minimum_required(VERSION 2.6)

# =================================================================
# Project variables
# =================================================================
# Setup these variables and the rest of the CMakeLists.txt won't need more changes.
set(PROJECT_NAME "Poles")
set(PROJECT_EXECUTABLE_NAME "Poles")
set(PROJECT_LIBRARY_NAME "PolesEngine")
set(PROJECT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(PROJECT_HEADERS_DIR "${CMAKE_SOURCE_DIR}/include")
set(PROJECT_MAIN_FILE "${PROJECT_SOURCE_DIR}/main.cpp")
set(PROJECT_RESOURCES_DIR "${CMAKE_SOURCE_DIR}/platforms")

# =================================================================
# Project properties
# =================================================================
project("${PROJECT_NAME}")

# Specify build output directories
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Define executable to be created
add_executable(${PROJECT_EXECUTABLE_NAME} ${PROJECT_MAIN_FILE})

# =================================================================
# Detect platform
# =================================================================
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set (OPERATING_SYSTEM "Linux")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set (OPERATING_SYSTEM "Mac OS X")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set (OPERATING_SYSTEM "Windows")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

# =================================================================
# Macros
# =================================================================
# Check cmake was not run from the source folder
MACRO(MACRO_ENSURE_OUT_OF_SOURCE_BUILD MSG)
    STRING(COMPARE EQUAL "${CMAKE_SOURCE_DIR}"
"${CMAKE_BINARY_DIR}" insource)
    GET_FILENAME_COMPONENT(PARENTDIR ${CMAKE_SOURCE_DIR} PATH)
    STRING(COMPARE EQUAL "${CMAKE_SOURCE_DIR}"
"${PARENTDIR}" insourcesubdir)
    IF(insource OR insourcesubdir)
        MESSAGE(FATAL_ERROR "${MSG}")
    ENDIF(insource OR insourcesubdir)
ENDMACRO(MACRO_ENSURE_OUT_OF_SOURCE_BUILD)

# Find all directories inside a given directory
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
        SET(dirlist ${dirlist} ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()


# =================================================================
# Source Files
# =================================================================
cmake_policy( SET CMP0009 NEW)      # Prevents cmake from following symbolic links using GLOB
file(GLOB_RECURSE PROJECT_SOURCE_FILES "${PROJECT_SOURCE_DIR}/*.cpp")
list(REMOVE_ITEM PROJECT_SOURCE_FILES ${PROJECT_MAIN_FILE})

# =================================================================
# Include directories
# =================================================================
SUBDIRLIST(PROJECT_INCLUDE_DIRECTORIES ${PROJECT_HEADERS_DIR})
include_directories(${PROJECT_HEADERS_DIR} ${PROJECT_INCLUDE_DIRECTORIES})
file(GLOB_RECURSE PROJECT_HEADER_FILES "${PROJECT_HEADERS_DIR}/*.h")
set(PROJECT_SOURCE_FILES ${PROJECT_SOURCE_FILES} ${PROJECT_HEADER_FILES})

# =================================================================
# Link sources
# =================================================================
add_library(${PROJECT_LIBRARY_NAME} ${PROJECT_SOURCE_FILES})
target_link_libraries(${PROJECT_EXECUTABLE_NAME} ${PROJECT_LIBRARY_NAME})


# =================================================================
# Libraries
# =================================================================
if(${OPERATING_SYSTEM} MATCHES "Linux")
        set(PROJECT_LIBRARIES_FOLDER "${PROJECT_RESOURCES_DIR}/linux/lib")
        set(PROJECT_LIBRARIES_INCLUDES_FOLDER "${PROJECT_RESOURCES_DIR}/linux/include")
endif(${OPERATING_SYSTEM} MATCHES "Linux")

if(${OPERATING_SYSTEM} MATCHES "Windows")
        set(PROJECT_LIBRARIES_FOLDER "${PROJECT_RESOURCES_DIR}/win32/lib")
        set(PROJECT_LIBRARIES_INCLUDES_FOLDER "${PROJECT_RESOURCES_DIR}/win32/include")
endif(${OPERATING_SYSTEM} MATCHES "Windows")

if(${OPERATING_SYSTEM} MATCHES "Mac OS X")
	set (PROJECT_LIBRARIES_FOLDER "${PROJECT_RESOURCES_DIR}/osx/lib")
	set (PROJECT_LIBRARIES_INCLUDES_FOLDER "${PROJECT_RESOURCES_DIR}/osx/include")
endif(${OPERATING_SYSTEM} MATCHES "Mac OS X")

message("Linking libraries from folder ${PROJECT_LIBRARIES_FOLDER}")

link_directories(${PROJECT_LIBRARIES_FOLDER})
include_directories(${PROJECT_LIBRARIES_INCLUDES_FOLDER})

target_link_libraries(${PROJECT_EXECUTABLE_NAME} SDL2)
target_link_libraries(${PROJECT_EXECUTABLE_NAME} SDL2_image)
target_link_libraries(${PROJECT_EXECUTABLE_NAME} SDL2_ttf)
target_link_libraries(${PROJECT_EXECUTABLE_NAME} artemis)
target_link_libraries(${PROJECT_EXECUTABLE_NAME} json)

# =================================================================
# Post scripts
# =================================================================
# Create symbolic link to assets folder
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ln -sf ${CMAKE_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/bin/assets
)
