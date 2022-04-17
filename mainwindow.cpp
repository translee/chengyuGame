#include "mainwindow.h"
#include <QTimer>
#include <QDir>
#include "ui_mainwindow.h"
#include "displaywidget.h"
#include "statusshowwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_displayWidget(new DisplayWidget())
    , m_statusShowWidget(new StatusShowWidget())
    , m_testTimer(new QTimer)
{
    ui->setupUi(this);
    ui->verticalLayout->addWidget(m_displayWidget);
    ui->verticalLayout_status->addWidget(m_statusShowWidget);
    ui->statusBar->showMessage("状态栏");
    ui->textBrowser->moveCursor(QTextCursor::End);
    this->setWindowTitle("成语接龙");
    this->setFixedSize(this->width(),this->height());
    connect(ui->pushButton,&QPushButton::clicked,this,[this]{
        this->m_displayWidget->setText(this->ui->lineEdit->text());
    });
    connect(ui->pushButton,&QPushButton::clicked,this,[this]{
        this->ui->textBrowser->append("sdsadadsadasda");
    });
    m_testTimer->start(1000);
    connect(m_testTimer, &QTimer::timeout, this, &MainWindow::addDanmuText);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_displayWidget;
    delete m_statusShowWidget;
}

void MainWindow::addDanmuText()
{
    QDir dir(QDir::currentPath() + "/needSolve");
    QStringList nameFilters;
    nameFilters << "*.txt";
    QStringList paths = dir.entryList(nameFilters);
    for (const auto& path : paths)
    {
        QFile file(QDir::currentPath() + "/needSolve/" + path);
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QByteArray array = file.readAll();
        this->ui->textBrowser->append(QString(array));
        file.remove();
    }
}

