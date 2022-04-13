#include "displaywidget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_displayWidget(new DisplayWidget())
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(m_displayWidget);
    setFixedSize(this->width(),this->height());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_displayWidget;
}

