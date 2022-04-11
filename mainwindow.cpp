#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->graphicsView->setStyleSheet("background: rgb(200,200,255);");
    QWidget w;
    ui->verticalLayout->addWidget(&w);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void __createCircle()
{

}
