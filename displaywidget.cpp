#include "displaywidget.h"
#include <QPainter>
#include <QTimer>
#include "constDef.h"
#include "player.h"
#include "npcplayer.h"
#include "playermanager.h"
using namespace constDef;

DisplayWidget::DisplayWidget(QWidget *parent)
    : QWidget{parent}
    , m_timer(new QTimer())
    , m_text(new QString("成语接龙"))
{
    connect(m_timer,&QTimer::timeout,this,&DisplayWidget::__refreshWidget);
    m_timer->start(20);
    PlayerManager::getInstance().initAllPosToNPC();
    PlayerManager::getInstance().addHumanPlayer();
    PlayerManager::getInstance().addHumanPlayer();
    PlayerManager::getInstance().addHumanPlayer();
    PlayerManager::getInstance().deleteHumanPlayer(0);
}

DisplayWidget::~DisplayWidget()
{
    delete m_timer;
    delete m_text;
}

void DisplayWidget::paintEvent(QPaintEvent*)
{
    QPainter paint(this);
    __createBombLine(&paint);
    __createRect(&paint);
    __createPlayerImage(&paint);
    __createIdiomImage(&paint);
}

void DisplayWidget::__createRect(QPainter* paint)
{
    paint->setPen(QPen(Qt::darkGray,2,Qt::SolidLine));
    paint->drawRect(Space,Space,RectWidth,RectHeight);
}

void DisplayWidget::__createPlayerImage(QPainter* paint)
{
    auto playerList = PlayerManager::getInstance().getAllNPCPlayers();
    auto humanPlayerList = PlayerManager::getInstance().getAllHumanPlayers();
    for (auto pl : playerList)
    {
        pl->moveNext();
        paint->drawPixmap(pl->getRect(), pl->getImage());
    }
    for (auto pl : humanPlayerList)
    {
        pl->moveNext();
        paint->drawPixmap(pl->getRect(), pl->getImage());
    }
}

void DisplayWidget::__createIdiomImage(QPainter* paint)
{
    paint->setPen(QPen(Qt::darkCyan,2,Qt::SolidLine));
    QBrush brush(Qt::darkCyan);
    paint->setBrush(brush);
    paint->drawRect(IdiomAreaX,IdiomAreaY,IdiomAreaWidth,IdiomAreaHeight);
    paint->setPen(QPen(Qt::white,2,Qt::SolidLine));
    QFont font("FongSun", TextSize);
    font.setBold(true);
    paint->setFont(font);
    paint->drawText(IdiomTextX, IdiomTextY,*m_text);
}

void DisplayWidget::__createBombLine(QPainter* paint)
{
    paint->setPen(QPen(Qt::darkCyan,2,Qt::DashLine));
    paint->drawLine(Space, FocusY, RectWidth, FocusY);
    paint->drawLine(FocusX, Space, FocusX, RectHeight);
}

void DisplayWidget::__refreshWidget()
{
    update();
}
