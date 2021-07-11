QT += testlib
QT += gui
QT += widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  \
    ../src/canvas.cpp \
    ../src/simplecppmainwindow.cpp \
    tst_testsimplecpp.cpp

HEADERS += \
    ../include/canvas.h \
    ../include/simplecppmainwindow.h

INCLUDEPATH += ../include

