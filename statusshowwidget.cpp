#include "statusshowwidget.h"
#include <QPainter>
#include "constDef.h"
#include "gameutil.h"
#include "playermanager.h"
using namespace constDef;

StatusShowWidget::StatusShowWidget(QWidget *parent)
    : QWidget{parent}
{
}

void StatusShowWidget::paintEvent(QPaintEvent*)
{
    QPainter paint(this);
    paint.setPen(QPen(Qt::darkGray,2,Qt::SolidLine));
    paint.drawRect(Space,Space,300,150);
    QRect rt(0, 0, StatusWidth, StatusHeight);
    //paint.drawPixmap(rt, GameUtil::loadPixmap(":imageRes/res/guangfa.jpg"));
    auto pls = PlayerManager::getInstance().getHumanPlayersByIndex(0);
    paint.drawPixmap(rt, pls.getStatusImage());
}
