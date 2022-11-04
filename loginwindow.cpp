#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QFile>
#include <QGraphicsDropShadowEffect>

#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    widgetInit();

    dataWindow = new DataWindow(this);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::widgetInit()
{
    setEditIcon();      //设置输入框图标
    loadQss();          //设置样式表

    //按钮设置阴影
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    //阴影颜色
    shadow_effect->setColor(QColor(38, 78, 119, 127));
    //阴影半径
    shadow_effect->setBlurRadius(22);
    //应用于login按钮
    ui->btn_login->setGraphicsEffect(shadow_effect);
}

/**
 * @brief 设置输入框图案
 */
void LoginWindow::setEditIcon()
{
    //1.新建action
    QAction* userAction = new QAction(ui->le_name);
    QAction* passwordAction = new QAction(ui->le_pwd);
    //2.给action添加icon
    userAction->setIcon(QIcon(":/res/icon/acc.png"));
    passwordAction->setIcon(QIcon(":/res/icon/pwd.png"));
    //3.给空间添加action
    ui->le_name->addAction(userAction,QLineEdit::LeadingPosition);
    ui->le_pwd->addAction(passwordAction,QLineEdit::LeadingPosition);
}

/**
 * @brief 设置style
 */
void LoginWindow::loadQss()
{
    QFile qssfile(":/res/style/login.qss");
    bool ret = qssfile.open(QIODevice::ReadOnly);
    if(ret == false)
    {
        qDebug()<< "open failed";
        return ;
    }

    QString  style = qssfile.readAll();
    this->setStyleSheet(style);
    qssfile.close();
}

/**
 * @brief 登录按钮槽函数
 */
void LoginWindow::on_btn_login_clicked()
{
    this->hide();
    dataWindow->show();
}
