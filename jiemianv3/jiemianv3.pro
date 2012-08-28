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
    platform/replayfile.h \
    platform/NormalBattle.h \
    platform/NetBattle.h \
    platform/Status.h \
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
    platform/replayfile.cpp \
    platform/NormalBattle.cpp \
    platform/NetBattle.cpp \
    platform/toPlayer.cpp \
    platform/Logic.cpp \
    platform/update.cpp

FORMS += \
    widgetssingle.ui \
    clickbottum.ui \
    beginbottum.ui \
    backwidget.ui \
    aivsai.ui

RESOURCES += \
    image.qrc
