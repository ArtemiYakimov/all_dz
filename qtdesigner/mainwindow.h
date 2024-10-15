#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DatabaseConnectionDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked() // Создайте этот слот в `mainwindow.ui`
{
    DatabaseConnectionDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString host = dialog.getHostName();
        QString dbname = dialog.getDatabaseName();
        QString username = dialog.getUsername();
        QString password = dialog.getPassword();
        uint protocol = dialog.getProtocol();

        // Здесь переменные можно использовать для подключения к БД
    }
}
