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
    paint.drawRect(Space,Space,StatusWidthTotal,StatusHeightTotal);
    QPixmap statusPixmap = PlayerManager::getInstance().
            getALLPlayerStatusPixmap();
    paint.drawPixmap(Space, Space, statusPixmap);
}
