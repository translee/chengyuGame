#include <QPainter>
#include <QTimer>
#include "constDef.h"
#include "displaywidget.h"
#include "player.h"
#include "playermanager.h"
using namespace constDef;

DisplayWidget::DisplayWidget()
    : m_timer(new QTimer())
{
    connect(m_timer,&QTimer::timeout,this,&DisplayWidget::__refreshWidget);
    m_timer->start(20);
    PlayerManager::getInstance().initAllPosToNPC();
    PlayerManager::getInstance().addHumanPlayer(0+Space, Space);
}

DisplayWidget::~DisplayWidget()
{
}

void DisplayWidget::paintEvent(QPaintEvent*)
{
    QPainter paint(this);
    __createRect(&paint);
    __createPlayerImage(&paint);
}

void DisplayWidget::__createRect(QPainter* paint)
{
    paint->setPen(QPen(Qt::darkGray,2,Qt::SolidLine));
    paint->drawRect(Space,Space,RectWidth,RectHeight);
}

void DisplayWidget::__createPlayerImage(QPainter* paint)
{
    auto playerList = PlayerManager::getInstance().getAllPlayers();
    for (auto pl : playerList)
    {
        pl->moveNext();
        paint->drawPixmap(pl->getRect(), pl->getImage());
    }
}

void DisplayWidget::__refreshWidget()
{
    update();
}
