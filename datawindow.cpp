#include "datawindow.h"
#include "ui_datawindow.h"
#include <QScreen>
#include <QGraphicsDropShadowEffect>

DataWindow::DataWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataWindow)
{
    ui->setupUi(this);

    //设置窗口为最大，保留任务栏
    this->setMaximumSize(QGuiApplication::primaryScreen()->availableGeometry().size());

    //按钮设置阴影
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    //阴影颜色
    shadow_effect->setColor(QColor(38, 78, 119, 127));
    //阴影半径
    shadow_effect->setBlurRadius(22);
    //应用于login按钮
    ui->btn_add->setGraphicsEffect(shadow_effect);
    ui->btn_del->setGraphicsEffect(shadow_effect);
    ui->btn_mod->setGraphicsEffect(shadow_effect);
    ui->btn_find->setGraphicsEffect(shadow_effect);
    ui->btn_back->setGraphicsEffect(shadow_effect);
}

DataWindow::~DataWindow()
{
    delete ui;
}


void DataWindow::on_btn_back_clicked()
{
    this->hide();
    this->parentWidget()->show();
}
