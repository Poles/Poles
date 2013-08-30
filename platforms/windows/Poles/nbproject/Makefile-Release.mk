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
	${OBJECTDIR}/_ext/608447161/Circle.o \
	${OBJECTDIR}/_ext/608447161/Color.o \
	${OBJECTDIR}/_ext/608447161/GameObject.o \
	${OBJECTDIR}/_ext/608447161/Line.o \
	${OBJECTDIR}/_ext/608447161/ResourceManager.o \
	${OBJECTDIR}/_ext/608447161/Vector2D.o \
	${OBJECTDIR}/_ext/1430818098/MovementSystem.o \
	${OBJECTDIR}/_ext/608552716/Game.o \
	${OBJECTDIR}/_ext/608552716/GameStateManager.o \
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
LDLIBSOPTIONS=-lmingw32 -lSDL2main -lSDL2 -lartemis

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poles.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poles.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poles ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/608447161/Circle.o: ../../../src/core/Circle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -Dmain=SDL_main -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/Circle.o ../../../src/core/Circle.cpp

${OBJECTDIR}/_ext/608447161/Color.o: ../../../src/core/Color.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -Dmain=SDL_main -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/Color.o ../../../src/core/Color.cpp

${OBJECTDIR}/_ext/608447161/GameObject.o: ../../../src/core/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -Dmain=SDL_main -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/GameObject.o ../../../src/core/GameObject.cpp

${OBJECTDIR}/_ext/608447161/Line.o: ../../../src/core/Line.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -Dmain=SDL_main -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/Line.o ../../../src/core/Line.cpp

${OBJECTDIR}/_ext/608447161/ResourceManager.o: ../../../src/core/ResourceManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -Dmain=SDL_main -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/ResourceManager.o ../../../src/core/ResourceManager.cpp

${OBJECTDIR}/_ext/608447161/Vector2D.o: ../../../src/core/Vector2D.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -Dmain=SDL_main -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/Vector2D.o ../../../src/core/Vector2D.cpp

${OBJECTDIR}/_ext/1430818098/MovementSystem.o: ../../../src/core/systems/MovementSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1430818098
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -Dmain=SDL_main -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1430818098/MovementSystem.o ../../../src/core/systems/MovementSystem.cpp

${OBJECTDIR}/_ext/608552716/Game.o: ../../../src/game/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608552716
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -Dmain=SDL_main -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608552716/Game.o ../../../src/game/Game.cpp

${OBJECTDIR}/_ext/608552716/GameStateManager.o: ../../../src/game/GameStateManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608552716
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -Dmain=SDL_main -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608552716/GameStateManager.o ../../../src/game/GameStateManager.cpp

${OBJECTDIR}/_ext/1386528437/main.o: ../../../src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1386528437
	${RM} $@.d
	$(COMPILE.cc) -O2 -I../Artemis-Cpp/include -Dmain=SDL_main -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1386528437/main.o ../../../src/main.cpp

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
