#-------------------------------------------------
#
# Project created by QtCreator 2019-03-08T14:15:18
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Converter
TEMPLATE = app


SOURCES += main.cpp\
        converter.cpp \
    editor.cpp \
    conver_10_p.cpp \
    convert_p_10.cpp \
    control.cpp \
    testeditor.cpp \
    testconver_10_p.cpp \
    testconvert_p_10.cpp

HEADERS  += converter.h \
    editor.h \
    conver_10_p.h \
    convert_p_10.h \
    control.h \
    testeditor.h \
    testconver_10_p.h \
    testconvert_p_10.h

FORMS    += converter.ui
