#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include "QRController.h"



string dec2hex(long a);
long hex2dec(const string & hexstr);
string hexadd(const string & hex1, const string & hex2);

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    string sumSoFar;
private slots:
    void on_generateButton_pressed();

    void on_saveFileButton_pressed();

    void on_comboBox_currentIndexChanged(const QString &arg1);


    void on_generateButton_clicked();

    void on_MergeButton_clicked();

    void on_SplitButton_clicked();

    void on_MergeButton_pressed();

    void on_SplitButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
