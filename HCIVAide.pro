QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
exists(/opt/kingsoft/wps-office/office6/libstdc++.so.6){
        system(ln -s /opt/kingsoft/wps-office/office6/libstdc++.so.6  libstdc++.so.6)
        LIBS += libstdc++.so.6
}

QMAKE_LFLAGS += -Wl,--rpath=\'\$\$ORIGIN\':$$[QT_INSTALL_LIBS]:/opt/kingsoft/wps-office/office6
QMAKE_LIBDIR =  ./ $$[QT_INSTALL_LIBS]  /opt/kingsoft/wps-office/office6

greaterThan(QT_MAJOR_VERSION, 4){
        LIBS += -lrpcwpsapi_sysqt5 -lrpcetapi_sysqt5 -lrpcwppapi_sysqt5
        exists(/opt/kingsoft/wps-office/office6/libc++abi.so.1){
                system(ln -sf /opt/kingsoft/wps-office/office6/libc++abi.so.1  libc++abi.so.1)
                LIBS += libc++abi.so.1
        }
}
else{
        LIBS += -lrpcwpsapi -lrpcetapi -lrpcwppapi
}


INCLUDEPATH =  ./include/common \
               ./include/wps

SOURCES += \
    main.cpp \
    mainwindows.cpp \
    tabwidget.cpp \
    taskwindow.cpp \
    wpswindow.cpp

HEADERS += \
    mainwindows.h \
    tabwidget.h \
    taskwindow.h \
    wpswindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
