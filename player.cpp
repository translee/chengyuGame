#include "player.h"
#include "gameutil.h"
#include <QDebug>
#include "constDef.h"
using namespace constDef;

QRect Player::m_sLimit(Space, Space, RectWidth-CircleDiameter, RectHeight-CircleDiameter);
int Player::m_sSpeed = 1;

Player::Player()
    : m_dir(Direction::Left)
{
    m_image = GameUtil::loadPixmap(":imageRes/res/guangfa.jpg");
    m_rect = QRect(200, Space, CircleDiameter, CircleDiameter);
}

Player::Player(int x, int y)
    : m_dir(Direction::Left)
{
    m_image = GameUtil::loadPixmap(":imageRes/res/guangfa.jpg");
    m_rect = QRect(x, y, CircleDiameter, CircleDiameter);
}

void Player::moveNext()
{
    QPoint pos = m_rect.topLeft();
    if (pos == m_sLimit.topLeft())
        m_dir = Direction::Down;
    else if (pos == m_sLimit.bottomLeft())
        m_dir = Direction::Right;
    else if (pos == m_sLimit.bottomRight())
        m_dir = Direction::Up;
    else if (pos == m_sLimit.topRight())
        m_dir = Direction::Left;
    __doMove();
}

void Player::__doMove()
{
    QPoint pos = m_rect.topLeft();
    if (Direction::Left == m_dir)
        pos.rx() -= m_sSpeed;
    else if (Direction::Down == m_dir)
        pos.ry() += m_sSpeed;
    else if (Direction::Right == m_dir)
        pos.rx() += m_sSpeed;
    else if (Direction::Up == m_dir)
        pos.ry() -= m_sSpeed;
    m_rect.moveTo(pos);
    qDebug() << m_rect.topLeft().x() << "---" << m_rect.topLeft().y() << Qt::endl;
}
