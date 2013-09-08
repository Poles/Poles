#-------------------------------------------------
#
# Project created by QtCreator 2013-09-08T16:07:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = poles-editor
TEMPLATE = app


SOURCES += main.cpp\
    ../src/core/components/TextRendererComponent.cpp \
    ../src/core/components/SpriteRendererComponent.cpp \
    ../src/core/components/PositionComponent.cpp \
    ../src/core/systems/TextRenderingSystem.cpp \
    ../src/core/systems/RenderingSystem.cpp \
    ../src/core/systems/MovementSystem.cpp \
    ../src/core/Vector2D.cpp \
    ../src/core/Sprite.cpp \
    ../src/core/ResourceManager.cpp \
    ../src/core/GameObject.cpp \
    ../src/core/Color.cpp \
    ../src/game/states/IntroState.cpp \
    ../src/game/states/DebugState.cpp \
    ../src/game/GameStateManager.cpp \
    ../src/game/GameState.cpp \
    ../src/game/Game.cpp \
    ../src/game/Event.cpp \
    editor/GameRendererWidget.cpp \
    editor/GameThread.cpp \
    editor/EditorWindow.cpp

HEADERS  += \
    ../src/core/components/VelocityComponent.h \
    ../src/core/components/TextRendererComponent.h \
    ../src/core/components/SpriteRendererComponent.h \
    ../src/core/components/PositionComponent.h \
    ../src/core/components/Components.h \
    ../src/core/systems/TextRenderingSystem.h \
    ../src/core/systems/RenderingSystem.h \
    ../src/core/systems/MovementSystem.h \
    ../src/core/Vector2D.h \
    ../src/core/Sprite.h \
    ../src/core/ResourceManager.h \
    ../src/core/GameObject.h \
    ../src/core/ExtraTools.h \
    ../src/core/Color.h \
    ../src/game/states/IntroState.h \
    ../src/game/states/DebugState.h \
    ../src/game/GameStateManager.h \
    ../src/game/GameState.h \
    ../src/game/Game.h \
    ../src/game/Event.h \
    editor/GameRendererWidget.h \
    editor/GameThread.h \
    editor/EditorWindow.h

FORMS    += \
    editor/GameRendererWidget.ui \
    editor/EditorWindow.ui

# Artemis-Cpp

win32:      LIBS += -L$$PWD/../platforms/windows/Artemis-Cpp/lib -lartemis
win32:      INCLUDEPATH += $$PWD/../platforms/windows/Artemis-Cpp/include
unix:!macx: LIBS += -L$$PWD/../platforms/linux/Artemis-Cpp/lib -lartemis
unix:!macx: INCLUDEPATH += $$PWD/../platforms/linux/Artemis-Cpp/include
mac:        LIBS += -L$$PWD/../platforms/macosx/Artemis-Cpp/lib -lartemis
mac:        INCLUDEPATH += $$PWD/../platforms/macosx/Artemis-Cpp/include

# SDL2

win32:      INCLUDEPATH += $$PWD/../platforms/windows/SDL2/include
win32:      INCLUDEPATH += $$PWD/../platforms/windows/SDL2/include/SDL2 # Fixs wrong include in SDL2_image that searchs for SDL.h instead of SDL2/SDL.h
win32:      LIBS += -L$$PWD/../platforms/windows/SDL2/lib -lSDL2

# SDL2_image

win32:      LIBS += -L$$PWD/../platforms/windows/SDL2_image-2.0.0/i686-w64-mingw32/lib -lSDL2_image
win32:      INCLUDEPATH += $$PWD/../platforms/windows/SDL2_image-2.0.0/i686-w64-mingw32/include

# SDL2_ttf

win32:      LIBS += -L$$PWD/../platforms/windows/SDL2_ttf-2.0.12/i686-w64-mingw32/lib -lSDL2_ttf
win32:      INCLUDEPATH += $$PWD/../platforms/windows/SDL2_ttf-2.0.12/i686-w64-mingw32/include
