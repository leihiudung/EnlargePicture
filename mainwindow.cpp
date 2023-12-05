#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QImageReader>
#include <QPixmap>

#include <QDebug>
#include <QHBoxLayout>
#include <QPainter>
#include <QEvent>
#include <Dwmapi.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint);
    setWindowFlags(Qt::CustomizeWindowHint);
    HWND hwnd = (HWND)winId();

    SetRectEmpty(&border_thickness);
    if (GetWindowLongPtr(hwnd, GWL_STYLE) & WS_THICKFRAME)
    {
        AdjustWindowRectEx(&border_thickness, GetWindowLongPtr(hwnd, GWL_STYLE) & ~WS_CAPTION, FALSE, NULL);
        border_thickness.left *= -1;
        border_thickness.top *= -1;
    }
    else if (GetWindowLongPtr(hwnd, GWL_STYLE) & WS_BORDER)
    {
        SetRect(&border_thickness, 1, 1, 1, 1);
    }

    MARGINS margins = { 1, 1, 1, 1 };
    DwmExtendFrameIntoClientArea(hwnd, &margins);
    SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);


    ui->frame->setHidden(true);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::getPicture);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getPicture()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("选择文件保存路径"), "./", tr("图片(*.png* *.jpg*)"));

    if (imagePath.length() > 0) {
        QImageReader imageReader;
        imageReader.setFileName(imagePath);
        imageReader.setAutoTransform(true);

        auto oriImageSize = imageReader.size();
        //    auto targetImageSize = oriImageSize.scaled(imageSize, Qt::AspectRatioMode::KeepAspectRatio);
        auto targetImageSize = oriImageSize.scaled(ui->label_5->size(), Qt::AspectRatioMode::KeepAspectRatio);
        imageReader.setScaledSize(targetImageSize);
        QPixmap scalePixmap = QPixmap::fromImageReader(&imageReader);
        ui->label_5->setPixmap(scalePixmap);
        ui->frame->setHidden(false);

    }

}

bool MainWindow::nativeEventFilter(const QByteArray &eventType, void *message, long *result)
{
    if (eventType != "windows_generic_MSG")
        return false;

    MSG* msg = static_cast<MSG*>(message);
    QWidget* widget = QWidget::find(reinterpret_cast<WId>(msg->hwnd));
    if (!widget)
        return false;

    switch (msg->message) {
    case WM_NCCALCSIZE: {
        //*result = 0;
        if (msg->lParam)
        {
            qDebug()<<"border nccalcsize"<<border_thickness.left<<";"
                     <<border_thickness.top<<";"
                     <<border_thickness.right<<";"
                     <<border_thickness.bottom<<";";

            NCCALCSIZE_PARAMS* sz = (NCCALCSIZE_PARAMS*)msg->lParam;
            //            sz->rgrc[0].left += border_thickness.left;
            sz->rgrc[0].top -= border_thickness.top;
            //            sz->rgrc[0].right -= border_thickness.right;
            //            sz->rgrc[0].bottom -= border_thickness.bottom;
            return 0;
        }
        return false;
    }

    case WM_NCHITTEST: {
        const LONG borderWidth = 1;
        RECT winrect;
        GetWindowRect(msg->hwnd, &winrect);
        long x = GET_X_LPARAM(msg->lParam);
        long y = GET_Y_LPARAM(msg->lParam);

        // bottom left
        if (x >= winrect.left && x < winrect.left + borderWidth &&
            y < winrect.bottom && y >= winrect.bottom - borderWidth)
        {
            *result = HTBOTTOMLEFT;
            return true;
        }

        // bottom right
        if (x < winrect.right && x >= winrect.right - borderWidth &&
            y < winrect.bottom && y >= winrect.bottom - borderWidth)
        {
            *result = HTBOTTOMRIGHT;
            return true;
        }

        // top left
        if (x >= winrect.left && x < winrect.left + borderWidth &&
            y >= winrect.top && y < winrect.top + borderWidth)
        {
            *result = HTTOPLEFT;
            return true;
        }

        // top right
        if (x < winrect.right && x >= winrect.right - borderWidth &&
            y >= winrect.top && y < winrect.top + borderWidth)
        {
            *result = HTTOPRIGHT;
            return true;
        }

        // left
        if (x >= winrect.left && x < winrect.left + borderWidth)
        {
            *result = HTLEFT;
            return true;
        }

        // right
        if (x < winrect.right && x >= winrect.right - borderWidth)
        {
            *result = HTRIGHT;
            return true;
        }

        // bottom
        if (y < winrect.bottom && y >= winrect.bottom - borderWidth)
        {
            *result = HTBOTTOM;
            return true;
        }

        // top
        if (y >= winrect.top && y < winrect.top + borderWidth)
        {
            *result = HTTOP;
            return true;
        }

        if(y >= winrect.top + borderWidth && y < winrect.top + borderWidth + 30){
            *result = HTCAPTION;
            return true;
        }

        return false;
    }
    default:
        break;
    }

    return false;
}
