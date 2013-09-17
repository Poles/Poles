cmake_minimum_required (VERSION 2.6)
project (Poles)

# version number
set (Poles_VERSION_MAJOR 0)
set (Poles_VERSION_MINOR 1)

# Specify include paths
set (PROJECT_SOURCE_DIR "${PROJECT_BINARY_DIR}/src")
set (SOURCE_DIR "${PROJECT_BINARY_DIR}/src")

# Specify build paths
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

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

message ("Compiling project for ${OPERATING_SYSTEM} system.")
#
#----------------------------------------------------------------#

# Add executable
add_executable(Poles "${PROJECT_SOURCE_DIR}/main.cpp")

#----------------------------------------------------------------#
# Source files to link against executable
# Note: Add here any .cpp file created
set (POLES_SOURCE_FILES
	"${SOURCE_DIR}/core/Color.cpp"
	"${SOURCE_DIR}/core/GameObject.cpp"
	"${SOURCE_DIR}/core/ResourceManager.cpp"
	"${SOURCE_DIR}/core/SpriteAnimation.cpp"
	"${SOURCE_DIR}/core/SpriteSheet.cpp"
	"${SOURCE_DIR}/core/Vector2D"
	"${SOURCE_DIR}/core/components/PositionComponent.cpp"
	"${SOURCE_DIR}/core/components/SpriteSheetRendererComponent.cpp"
	"${SOURCE_DIR}/core/components/TextRendererComponent.cpp"
	"${SOURCE_DIR}/core/systems/MovementSystem.cpp"
	"${SOURCE_DIR}/core/systems/RenderingSystem.cpp"
	"${SOURCE_DIR}/core/systems/TextRenderingSystem.cpp"
	"${SOURCE_DIR}/game/Event.cpp"
	"${SOURCE_DIR}/game/Game.cpp"
	"${SOURCE_DIR}/game/GameState.cpp"
	"${SOURCE_DIR}/game/GameStateManager.cpp"
	"${SOURCE_DIR}/game/states/DebugState.cpp"
	"${SOURCE_DIR}/game/states/IntroState.cpp"
)
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
link_directories (/usr/local/lib)
include_directories (/usr/local/include)

target_link_libraries (Poles SDL2)
target_link_libraries (Poles SDL2_image)
target_link_libraries (Poles SDL2_ttf)
target_link_libraries (Poles artemis)
target_link_libraries (Poles json_linux-gcc-4.6_libmt)

