TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    BigInt/bigint.cpp \
    Utilities/utilities.cpp \
    FFT/fft.cpp

HEADERS += \
    BigInt/bigint.h \
    Utilities/utilities.h \
    UtilClasses/customsortable.h \
    FFT/fft.h
