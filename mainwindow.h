#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QFileDialog>
#include<QProcess>
#include<QMessageBox>
#include<QFile>
#include<QTextCodec>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openButton_clicked();

    void on_startButton_clicked();

    void on_openButton2_clicked();

private:
    Ui::MainWindow *ui;
    QString eployqtName;
    QString fileName;
    QFile *pathFile;
};

#endif // MAINWINDOW_H
