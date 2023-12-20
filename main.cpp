//#include "mainwindow.h"
#include "widget.h"
#include <QApplication>
#include <QTextCodec>
#include <Windows.h>
#include <WinUser.h>
#include <wingdi.h>

int main(int argc, char *argv[])
{

    double dScaleFactor = 1.0;
    //应用开启DPI感知
    SetProcessDPIAware();
    //计算当前屏幕的DPI
    HDC desktopDc = GetDC(NULL);
    float horizontal_dpi = GetDeviceCaps(desktopDc, LOGPIXELSX);
    float vrtical_dpi = GetDeviceCaps(desktopDc, LOGPIXELSY);
    int hv_dpi = (horizontal_dpi+vrtical_dpi)/2;
    //计算DPI的缩放系数设置全局的QT缩放系数
    dScaleFactor = static_cast<double>(hv_dpi)/96.0;
    qputenv("QT_SCALE_FACTOR", QString::number(dScaleFactor).toUtf8());

    QApplication a(argc, argv);
    QApplication::setFont(QFont("微软雅黑", 12)); // 设置全局字体为微软雅黑
    widget w;
//    widget w;
//    MainWindow w;
//    a.installNativeEventFilter(&w);
#if (QT_VERSION < QT_VERSION_CHECK(5,0,0))
#if _MSC_VER
    QTextCodec *codec = QTextCodec::codecForName("gbk");
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
#endif
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
#endif


    w.show();
    return a.exec();
}
