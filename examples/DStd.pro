# DStd Example QMakefile

QT = core
TEMPLATE = app
CONFIG += console
TARGET = dstdExample

VERSION =  1.0.0
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

include(../src/dstdlib.pri)

SOURCES += main.cpp
