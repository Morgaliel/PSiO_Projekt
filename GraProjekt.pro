TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG   += cmdline precompile_header

PRECOMPILED_HEADER  = includes.h


SOURCES += \
        animation.cpp \
        button.cpp \
        character.cpp \
        collider.cpp \
        enemy.cpp \
        game.cpp \
        goatman.cpp \
        gstate.cpp \
        hitbox.cpp \
        main.cpp \
        mainmenu.cpp \
        move.cpp \
        playergui.cpp \
        resources.cpp \
        tilemap.cpp \
        wall.cpp \
        player.cpp
INCLUDEPATH += "C:/SFML-2.5.1/include"

LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    animation.h \
    button.h \
    character.h \
    collider.h \
    enemy.h \
    game.h \
    goatman.h \
    gstate.h \
    hitbox.h \
    mainmenu.h \
    move.h \
    playergui.h \
    resources.h \
    tilemap.h \
    wall.h \
    player.h
