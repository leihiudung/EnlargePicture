#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QAbstractNativeEventFilter>
#include <Windows.h>
#include <windowsx.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public QAbstractNativeEventFilter
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    RECT border_thickness;
protected:
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *result) override;
private:
    Ui::MainWindow *ui;

private slots:
    void getPicture();
};
#endif // MAINWINDOW_H
