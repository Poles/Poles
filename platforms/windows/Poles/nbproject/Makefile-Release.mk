#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/608447161/Color.o \
	${OBJECTDIR}/_ext/608447161/GameObject.o \
	${OBJECTDIR}/_ext/608447161/ResourceManager.o \
	${OBJECTDIR}/_ext/608447161/SpriteAnimation.o \
	${OBJECTDIR}/_ext/608447161/SpriteSheet.o \
	${OBJECTDIR}/_ext/608447161/Vector2D.o \
	${OBJECTDIR}/_ext/957312044/Camera.o \
	${OBJECTDIR}/_ext/957312044/Position.o \
	${OBJECTDIR}/_ext/957312044/SpriteRenderer.o \
	${OBJECTDIR}/_ext/957312044/TextRenderer.o \
	${OBJECTDIR}/_ext/957312044/Velocity.o \
	${OBJECTDIR}/_ext/1430818098/MovementSystem.o \
	${OBJECTDIR}/_ext/1430818098/RenderingSystem.o \
	${OBJECTDIR}/_ext/1430818098/TextRenderingSystem.o \
	${OBJECTDIR}/_ext/608552716/EventListener.o \
	${OBJECTDIR}/_ext/608552716/Game.o \
	${OBJECTDIR}/_ext/608552716/GameState.o \
	${OBJECTDIR}/_ext/608552716/GameStateManager.o \
	${OBJECTDIR}/_ext/576904603/DebugState.o \
	${OBJECTDIR}/_ext/576904603/IntroState.o \
	${OBJECTDIR}/_ext/576904603/ParallaxTest.o \
	${OBJECTDIR}/_ext/1386528437/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Dmain=SDL_main
CXXFLAGS=-Dmain=SDL_main

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lmingw32 -lSDL2main -lSDL2 -lartemis -lSDL2_image

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poles.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poles.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poles ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/608447161/Color.o: ../../../src/core/Color.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/Color.o ../../../src/core/Color.cpp

${OBJECTDIR}/_ext/608447161/GameObject.o: ../../../src/core/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/GameObject.o ../../../src/core/GameObject.cpp

${OBJECTDIR}/_ext/608447161/ResourceManager.o: ../../../src/core/ResourceManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/ResourceManager.o ../../../src/core/ResourceManager.cpp

${OBJECTDIR}/_ext/608447161/SpriteAnimation.o: ../../../src/core/SpriteAnimation.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/SpriteAnimation.o ../../../src/core/SpriteAnimation.cpp

${OBJECTDIR}/_ext/608447161/SpriteSheet.o: ../../../src/core/SpriteSheet.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/SpriteSheet.o ../../../src/core/SpriteSheet.cpp

${OBJECTDIR}/_ext/608447161/Vector2D.o: ../../../src/core/Vector2D.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/Vector2D.o ../../../src/core/Vector2D.cpp

${OBJECTDIR}/_ext/957312044/Camera.o: ../../../src/core/components/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/957312044
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/957312044/Camera.o ../../../src/core/components/Camera.cpp

${OBJECTDIR}/_ext/957312044/Position.o: ../../../src/core/components/Position.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/957312044
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/957312044/Position.o ../../../src/core/components/Position.cpp

${OBJECTDIR}/_ext/957312044/SpriteRenderer.o: ../../../src/core/components/SpriteRenderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/957312044
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/957312044/SpriteRenderer.o ../../../src/core/components/SpriteRenderer.cpp

${OBJECTDIR}/_ext/957312044/TextRenderer.o: ../../../src/core/components/TextRenderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/957312044
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/957312044/TextRenderer.o ../../../src/core/components/TextRenderer.cpp

${OBJECTDIR}/_ext/957312044/Velocity.o: ../../../src/core/components/Velocity.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/957312044
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/957312044/Velocity.o ../../../src/core/components/Velocity.cpp

${OBJECTDIR}/_ext/1430818098/MovementSystem.o: ../../../src/core/systems/MovementSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1430818098
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1430818098/MovementSystem.o ../../../src/core/systems/MovementSystem.cpp

${OBJECTDIR}/_ext/1430818098/RenderingSystem.o: ../../../src/core/systems/RenderingSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1430818098
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1430818098/RenderingSystem.o ../../../src/core/systems/RenderingSystem.cpp

${OBJECTDIR}/_ext/1430818098/TextRenderingSystem.o: ../../../src/core/systems/TextRenderingSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1430818098
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1430818098/TextRenderingSystem.o ../../../src/core/systems/TextRenderingSystem.cpp

${OBJECTDIR}/_ext/608552716/EventListener.o: ../../../src/game/EventListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608552716
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608552716/EventListener.o ../../../src/game/EventListener.cpp

${OBJECTDIR}/_ext/608552716/Game.o: ../../../src/game/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608552716
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608552716/Game.o ../../../src/game/Game.cpp

${OBJECTDIR}/_ext/608552716/GameState.o: ../../../src/game/GameState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608552716
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608552716/GameState.o ../../../src/game/GameState.cpp

${OBJECTDIR}/_ext/608552716/GameStateManager.o: ../../../src/game/GameStateManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608552716
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608552716/GameStateManager.o ../../../src/game/GameStateManager.cpp

${OBJECTDIR}/_ext/576904603/DebugState.o: ../../../src/game/states/DebugState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/576904603
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/576904603/DebugState.o ../../../src/game/states/DebugState.cpp

${OBJECTDIR}/_ext/576904603/IntroState.o: ../../../src/game/states/IntroState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/576904603
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/576904603/IntroState.o ../../../src/game/states/IntroState.cpp

${OBJECTDIR}/_ext/576904603/ParallaxTest.o: ../../../src/game/states/ParallaxTest.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/576904603
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/576904603/ParallaxTest.o ../../../src/game/states/ParallaxTest.cpp

${OBJECTDIR}/_ext/1386528437/main.o: ../../../src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1386528437
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1386528437/main.o ../../../src/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poles.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
