#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constDef.h"
#include <QLayout>
#include <QPushButton>
#include <QPainter>
#include <QPainterPath>
#include <QTimer>
#include "playercircle.h"
#include "gameutil.h"

using namespace constDef;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_player1(new PlayerCircle())
{
    ui->setupUi(this);
    m_widget = new QWidget();
    ui->verticalLayout->addWidget(m_widget);
    connect(&timer,&QTimer::timeout,[this]
        {
            update();
        });
    timer.start(100);
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
    QPixmap temp = m_player1->increaseAngle();
    //paint->rotate(10);
    auto pr = GameUtil::getRotateOffset(30, m_player1->getAngle());
    //paint->drawRect(300 - pr.first, 100 - pr.second,60, 60);
    paint->drawPixmap(300 - pr.first, 100 - pr.second, temp);
    paint->end();
    return;
}

void MainWindow::__createRect(QPainter* paint)
{
    int winW = m_widget->width();
    int winH = m_widget->height();
    paint->setPen(QPen(Qt::black,2,Qt::SolidLine));
    paint->drawRect(10,10,RectWidth,RectHeight);
}


