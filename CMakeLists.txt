cmake_minimum_required (VERSION 2.6)
project (Poles)

# version number
set (Poles_VERSION_MAJOR 0)
set (Poles_VERSION_MINOR 1)

# Specify include paths
set (PROJECT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set (SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

# Specify build paths
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add executable
set (POLES_MAIN "${SOURCE_DIR}/main.cpp")
add_executable (Poles ${POLES_MAIN})

#----------------------------------------------------------------#
# Detect current Operating System
#
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set (OPERATING_SYSTEM "Linux")
endif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set (OPERATING_SYSTEM "Mac OS X")
endif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set (OPERATING_SYSTEM "Windows")
endif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")

message ("Compiling ${PROJECT_NAME} for ${OPERATING_SYSTEM} system.")
#
#----------------------------------------------------------------#

#----------------------------------------------------------------#
# Source files to link against executable
file (GLOB_RECURSE POLES_SOURCE_FILES ${SOURCE_DIR}/*.cpp)
list (REMOVE_ITEM POLES_SOURCE_FILES ${POLES_MAIN})
add_library (PolesEngine ${POLES_SOURCE_FILES})
target_link_libraries (Poles PolesEngine)
#
#-----------------------------------------------------------------#

#-----------------------------------------------------------------#
# Source directories where binary tree should look for .h files.
# Note: If you create a new directory for source code, add it here.
set (POLES_SOURCE_DIRECTORIES
    "${SOURCE_DIR}"
	"${SOURCE_DIR}/core"
	"${SOURCE_DIR}/core/component"
	"${SOURCE_DIR}/core/systems"
	"${SOURCE_DIR}/game"
	"${SOURCE_DIR}/game/states"
)
include_directories (${POLES_SOURCE_DIRECTORIES})
#
#-----------------------------------------------------------------#

# Libraries (temporal, this should be changed to link against the project's libraries in /platforms)
# link_directories (/usr/local/lib)
# include_directories (/usr/local/include)
link_directories (/Libraries/Frameworks)
include_directories (/Libraries/Frameworks)

# Windows MinGW only
if (${OPERATING_SYSTEM} MATCHES "Windows")
	target_link_libraries (Poles mingw32)
	target_link_libraries (Poles SDL2main)
endif (${OPERATING_SYSTEM} MATCHES "Windows")

target_link_libraries (Poles SDL2)
target_link_libraries (Poles SDL2_image)
target_link_libraries (Poles SDL2_ttf)
target_link_libraries (Poles artemis)
target_link_libraries (Poles json)


