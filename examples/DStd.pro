# DStd Example QMakefile

QT = core
TEMPLATE = app
CONFIG += console
TARGET = dstdExample

include(../src/dstdlib.pri)

SOURCES += main.cpp
