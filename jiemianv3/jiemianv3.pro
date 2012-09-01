QT      += core network
QT      += thread
OTHER_FILES += \
    jiemianv3.pro.user \
    jiemianv3.pro

HEADERS += \
    widgetssingle.h \
    ui_widgetssingle.h \
    ui_clickbottum.h \
    ui_beginbottum.h \
    ui_backwidget.h \
    ui_aivsai.h \
    rounditem.h \
    creator.h \
    clickbottum.h \
    beginbottum.h \
    backwidget.h \
    aivsai.h \
    platform/Status.h \
    platform/replayfile.h \
    platform/NormalBattle.h \
    platform/NetBattle.h \
    platform/Logic.h \
    platform/Basic.h

SOURCES += \
    widgetssingle.cpp \
    rounditem.cpp \
    main.cpp \
    creator.cpp \
    clickbottum.cpp \
    beginbottum.cpp \
    backwidget.cpp \
    aivsai.cpp \
    platform/update.cpp \
    platform/NormalBattle.cpp \
    platform/NetBattle.cpp \
    platform/Logic.cpp \
    platform/replayfile.cpp

FORMS += \
    widgetssingle.ui \
    clickbottum.ui \
    beginbottum.ui \
    backwidget.ui \
    aivsai.ui

RESOURCES += \
    image.qrc
