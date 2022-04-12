#include "playercircle.h"
#include "gameutil.h"
#include <QDebug>

//int PlayerCircle::m_sSpeed = 10;

PlayerCircle::PlayerCircle()
{
    m_image = GameUtil::loadPixmap(":imageRes/res/guangfa.jpg");
//    QMatrix matrix;
//    matrix.rotate(45);
//    QTransform trans;
//    trans.rotate(45);
//    m_image = m_image.transformed(trans);
}

QPixmap PlayerCircle::increaseAngle()
{
    if (m_rotateAngle == 360)
        m_rotateAngle = 0;
    m_rotateAngle += 10;
    QMatrix matrix;
    matrix.rotate(m_rotateAngle);
    return m_image.transformed(matrix, Qt::SmoothTransformation);
}
