#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constDef.h"
#include <QLayout>
#include <QPushButton>
#include <QPainter>
#include <QPainterPath>

using namespace constDef;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->graphicsView->setStyleSheet("background: rgb(200,200,255);");
    m_widget = new QWidget();
    ui->verticalLayout->addWidget(m_widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* pe)
{

    QPainter* paint=new QPainter(m_widget);
    paint->begin(this);
    __createRect(paint);
    QSize picSize(30,30);
    QPixmap image(":imageRes/res/img.jpg");
    QPixmap scaledPixmap = image.scaled(picSize, Qt::KeepAspectRatio);
    QBrush brush;

    brush.setTexture(scaledPixmap);
    paint->setBrush(brush);
    paint->drawEllipse(QRect(20,20,30,30));


//    QRect rect = QRect(20,20,50,50);
    //paint->drawPixmap(rect,QPixmap(":imageRes/res/img.jpg"));

    paint->end();

    return;
}

void MainWindow::__createCircle(QPainter*)
{

}

void MainWindow::__createRect(QPainter* paint)
{
    int winW = m_widget->width();
    int winH = m_widget->height();
    paint->setPen(QPen(Qt::black,2,Qt::SolidLine));
    paint->drawRect(10,10,winW,winH);
}


