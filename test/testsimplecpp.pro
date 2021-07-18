QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  \
    ../src/canvas.cpp \
    ../src/commondefs.cpp \
    ../src/composite.cpp \
    ../src/line.cpp \
    ../src/polygon.cpp \
    ../src/simplecppmainwindow.cpp \
    ../src/sprite.cpp \
    ../src/turtle.cpp \
    ../src/turtleSim.cpp \
    tst_testsimplecpp.cpp

HEADERS += \
    ../include/canvas.h \
    ../include/commondefs.h \
    ../include/composite.h \
    ../include/line.h \
    ../include/polygon.h \
    ../include/simplecppmainwindow.h \
    ../include/sprite.h \
    ../include/turtle.h \
    ../include/turtleSim.h

INCLUDEPATH += ../include

