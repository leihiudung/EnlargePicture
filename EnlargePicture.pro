QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
win32: {
LIBS += -lDwmapi -lUxTheme -lUser32
}
msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

SOURCES += \
    accountdetailwidget.cpp \
    accountwidget.cpp \
    enlargedetailitemwidget.cpp \
    enlargeparamselectwidget.cpp \
    enlargewidget.cpp \
    main.cpp \
    mainwindow.cpp \
    menberwidget.cpp \
    paymentwidget.cpp \
    resetpasswordwidget.cpp \
    retrievepasswordwidget.cpp \
    selectedpicitemwidget.cpp \
    settingwidget.cpp \
    widget.cpp

HEADERS += \
    accountdetailwidget.h \
    accountwidget.h \
    enlargedetailitemwidget.h \
    enlargeparamselectwidget.h \
    enlargewidget.h \
    mainwindow.h \
    menberwidget.h \
    paymentwidget.h \
    resetpasswordwidget.h \
    retrievepasswordwidget.h \
    selectedpicitemwidget.h \
    settingwidget.h \
    widget.h

FORMS += \
    accountdetailwidget.ui \
    accountwidget.ui \
    enlargedetailitemwidget.ui \
    enlargeparamselectwidget.ui \
    enlargewidget.ui \
    mainwindow.ui \
    menberwidget.ui \
    paymentwidget.ui \
    resetpasswordwidget.ui \
    retrievepasswordwidget.ui \
    selectedpicitemwidget.ui \
    settingwidget.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    main.qrc
