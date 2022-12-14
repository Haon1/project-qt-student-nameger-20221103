#ifndef DATAWINDOW_H
#define DATAWINDOW_H

#include <QMainWindow>

namespace Ui {
class DataWindow;
}

class DataWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataWindow(QWidget *parent = nullptr);
    ~DataWindow();

    void loadQss();

private slots:
    void on_btn_back_clicked();

private:
    Ui::DataWindow *ui;
};

#endif // DATAWINDOW_H
