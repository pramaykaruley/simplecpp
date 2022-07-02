QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += debug c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \    
    canvas.cpp \
    main.cpp \
    turtleSim.cpp \
    turtle.cpp \
    sprite.cpp \
    polygon.cpp \
    commondefs.cpp \
    composite.cpp \
    line.cpp \

HEADERS += \
    ../include/canvas.h \
    ../include/turtleSim.h \
    ../include/turtle.h \
    ../include/sprite.h \
    ../include/spriteInterface.h \
    ../include/commondefs.h \
    ../include/polygon.h \
    ../include/composite.h \
    ../include/line.h \

INCLUDEPATH = ../include

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
