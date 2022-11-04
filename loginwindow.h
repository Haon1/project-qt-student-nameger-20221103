#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "datawindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    void widgetInit();      //控件初始化
    void setEditIcon();     //设置输入框图案
    void loadQss();        //设置StyleSheet

private slots:
    void on_btn_login_clicked();

private:
    Ui::LoginWindow *ui;

    DataWindow *dataWindow;
};
#endif // LOGINWINDOW_H
