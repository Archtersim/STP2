#-------------------------------------------------
#
# Project created by QtCreator 2019-03-30T01:06:42
#
#-------------------------------------------------

QT       += core gui
QT       += testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app

INCLUDEPATH += D:/boost

SOURCES += main.cpp\
        calculator.cpp \
    tpnumber.cpp \
    pnumbereditor.cpp \
    tctrl.cpp \
    tproc.cpp \
    tmemory.cpp \
    tfrac.cpp \
    fraceditor.cpp \
    tcomplex.cpp \
    complexeditor.cpp \
    testtfrac.cpp \
    testfraceditor.cpp \
    testmemory.cpp \
    testproc.cpp \
    testtpnumber.cpp \
    testtpnumbereditor.cpp \
    testtcomplex.cpp \
    testcomplexeditor.cpp

HEADERS  += calculator.h \
    aeditor.h \
    anumber.h \
    tpnumber.h \
    pnumbereditor.h \
    tctrl.h \
    tproc.h \
    tmemory.h \
    enums.h \
    tfrac.h \
    fraceditor.h \
    tcomplex.h \
    complexeditor.h \
    testfrac.h \
    testfraceditor.h \
    testmemory.h \
    testproc.h \
    testtpnumber.h \
    testtpnumbereditor.h \
    testtcomplex.h \
    testcomplexeditor.h

FORMS    += calculator.ui
