TEMPLATE = app
LIBS += -L"/usr/local/lib/"
CONFIG(release, debug|release): LIBS += -lsfml-audio.2.1 -lsfml-graphics.2.1 -lsfml-network.2.1 -lsfml-window.2.1 -lsfml-system.2.1
CONFIG(debug, debug|release): LIBS += -lsfml-audio.2.1 -lsfml-graphics.2.1 -lsfml-network.2.1 -lsfml-window.2.1 -lsfml-system.2.1

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

#LIBS += -lsfml-graphics \   -lsfml-window \ -lsfml-system


SOURCES += main.cpp \
    enemy.cpp \
    game_model.cpp \
    game_object.cpp \
    key_handler.cpp \
    level_view.cpp \
    mouse_handler.cpp \
    player.cpp \
    portal.cpp \
    world.cpp

HEADERS += \
    enemy.h \
    game_model.h \
    game_object.h \
    key_handler.h \
    level_view.h \
    mouse_handler.h \
    player.h \
    portal.h \
    world.h \
    PortalTestSuite.hpp
