#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "displaywidget.h"
#include "statusshowwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_displayWidget(new DisplayWidget())
    , m_statusShowWidget(new StatusShowWidget())
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(m_displayWidget);
    ui->verticalLayout_status->addWidget(m_statusShowWidget);
    ui->statusBar->showMessage("状态栏");
    this->setWindowTitle("成语接龙");
    this->setFixedSize(this->width(),this->height());
    connect(ui->pushButton,&QPushButton::clicked,this,[this]{
        this->m_displayWidget->setText(this->ui->lineEdit->text());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_displayWidget;
}

