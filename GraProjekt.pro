TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        animation.cpp \
        button.cpp \
        character.cpp \
        collider.cpp \
        game.cpp \
        gstate.cpp \
        main.cpp \
        mainmenu.cpp \
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
    game.h \
    gstate.h \
    mainmenu.h \
    resources.h \
    tilemap.h \
    wall.h \
    player.h
