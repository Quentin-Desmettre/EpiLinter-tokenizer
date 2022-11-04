QT += \
    websockets \
    core \
    widgets

HEADERS += \
    server.h \
    tokenizer.h

SOURCES += \
    main.cpp \
    server.cpp \
    tokenizer.cpp

LIBS += \
    -L /usr/lib64/ -lboost_wave
