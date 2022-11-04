QT += \
    websockets \
    core

INCLUDEPATH += include

HEADERS += \
    include/server.h \
    include/tokenizer.h

SOURCES += \
    src/main.cpp \
    src/server.cpp \
    src/tokenizer.cpp

LIBS += \
    -L /usr/lib64/ -lboost_wave
