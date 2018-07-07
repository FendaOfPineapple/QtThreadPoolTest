#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/icon/title"));
    pathFile=new QFile("path.ini");
    pathFile->open(QIODevice::ReadOnly);
    QByteArray t = pathFile->readAll();
    eployqtName=QString(t);
    ui->eployqtPathEdit->setText(QString(t));
    pathFile->close();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openButton_clicked()
{

    fileName=QFileDialog::getOpenFileName(this,tr("Open exe"), "", tr("exe (*.exe)"));
    ui->pathEdit->setText(fileName);
}

void MainWindow::on_startButton_clicked()
{
    if(fileName.isEmpty()||eployqtName.isEmpty())
    {
        QMessageBox  box1;
        box1.setWindowIcon(QIcon(":/icon/title"));
        box1.setIcon(QMessageBox::Warning);
        box1.setText("<h2>Path is Empty!</h2>");
        box1.exec();
        return;
    }
    QProcess p(0);
    p.start(eployqtName,QStringList()<<fileName);
    p.waitForFinished();
    QMessageBox  box;
    box.setWindowIcon(QIcon(":/icon/title"));
    box.setIcon(QMessageBox::Information);
    box.setText("<h2>Build Finished!</h2>");
    box.exec();
}

void MainWindow::on_openButton2_clicked()
{
    eployqtName=QFileDialog::getOpenFileName(this,tr("Open exe"), "", tr("exe (*.exe)"));
    ui->eployqtPathEdit->setText(eployqtName);
    pathFile->open(QIODevice::WriteOnly | QIODevice::Text);
    pathFile->write(eployqtName.toUtf8());
    pathFile->close();


}
