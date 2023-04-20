TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    GenerateConfig.cpp \
    TryConfig.cpp

HEADERS += \
    GenerateConfig.h \
    TryConfig.h
