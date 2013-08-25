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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
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
	${OBJECTDIR}/_ext/608447161/Line.o \
	${OBJECTDIR}/_ext/608447161/ResourcesManager.o \
	${OBJECTDIR}/_ext/608447161/Vector2D.o \
	${OBJECTDIR}/_ext/957312044/PositionComponent.o \
	${OBJECTDIR}/_ext/608552716/Game.o \
	${OBJECTDIR}/_ext/608552716/GameStateManager.o \
	${OBJECTDIR}/_ext/1386528437/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lSDL2 -lartemis

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poles

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poles: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poles ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/608447161/Circle.o: ../../../src/core/Circle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/Circle.o ../../../src/core/Circle.cpp

${OBJECTDIR}/_ext/608447161/Color.o: ../../../src/core/Color.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/Color.o ../../../src/core/Color.cpp

${OBJECTDIR}/_ext/608447161/Line.o: ../../../src/core/Line.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/Line.o ../../../src/core/Line.cpp

${OBJECTDIR}/_ext/608447161/ResourcesManager.o: ../../../src/core/ResourcesManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/ResourcesManager.o ../../../src/core/ResourcesManager.cpp

${OBJECTDIR}/_ext/608447161/Vector2D.o: ../../../src/core/Vector2D.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608447161
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608447161/Vector2D.o ../../../src/core/Vector2D.cpp

${OBJECTDIR}/_ext/957312044/PositionComponent.o: ../../../src/core/components/PositionComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/957312044
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/957312044/PositionComponent.o ../../../src/core/components/PositionComponent.cpp

${OBJECTDIR}/_ext/608552716/Game.o: ../../../src/game/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608552716
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608552716/Game.o ../../../src/game/Game.cpp

${OBJECTDIR}/_ext/608552716/GameStateManager.o: ../../../src/game/GameStateManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/608552716
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/608552716/GameStateManager.o ../../../src/game/GameStateManager.cpp

${OBJECTDIR}/_ext/1386528437/main.o: ../../../src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1386528437
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1386528437/main.o ../../../src/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/poles

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
