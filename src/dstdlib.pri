CONFIG += console c++11

INCLUDEPATH += $$PWD

SOURCES += \
    $$PWD/BigInt/bigint.cpp \
    $$PWD/Utilities/utilities.cpp \
    $$PWD/FFT/fft.cpp \
    $$PWD/UtilClasses/customsortable.cpp

HEADERS += \
    $$PWD/BigInt/bigint.h \
    $$PWD/Utilities/utilities.h \
    $$PWD/UtilClasses/customsortable.h \
    $$PWD/FFT/fft.h
