#include <QDebug>
#include <QString>
#include "player.h"
#include "gameutil.h"
#include "constDef.h"
using namespace constDef;
//":imageRes/res/guangfa.jpg"
QRect Player::m_sLimit(Space, Space, RectWidth-CircleDiameter, RectHeight-CircleDiameter);
int Player::m_sSpeed = 1;

Player::Player(int x, int y, const QString& path)
    : m_dir(Direction::Left)
{
    m_image = GameUtil::loadPixmap(path);
    m_rect = QRect(x, y, CircleDiameter, CircleDiameter);
    if (x == m_sLimit.left())
        m_dir = Direction::Down;
    else if (y == m_sLimit.top())
        m_dir = Direction::Left;
    else if (x == m_sLimit.right()+1)
        m_dir = Direction::Up;
    else if (y == m_sLimit.bottom()+1)
        m_dir = Direction::Right;
}

void Player::moveNext()
{
    // 判断方向
    QPoint pos = m_rect.topLeft();
    if (pos == GameUtil::topLeft(m_sLimit))
        m_dir = Direction::Down;
    else if (pos == GameUtil::bottomLeft(m_sLimit))
        m_dir = Direction::Right;
    else if (pos == GameUtil::bottomRight(m_sLimit))
        m_dir = Direction::Up;
    else if (pos == GameUtil::topRight(m_sLimit))
        m_dir = Direction::Left;
    // 移动
    if (Direction::Left == m_dir)
        pos.rx() -= m_sSpeed;
    else if (Direction::Down == m_dir)
        pos.ry() += m_sSpeed;
    else if (Direction::Right == m_dir)
        pos.rx() += m_sSpeed;
    else if (Direction::Up == m_dir)
        pos.ry() -= m_sSpeed;
    m_rect.moveTo(pos);
}
