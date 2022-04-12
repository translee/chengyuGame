#ifndef PLAYERCIRCLE_H
#define PLAYERCIRCLE_H
#include <QPixmap>

class PlayerCircle
{
public:
    PlayerCircle();
    QPixmap getImage() const {return m_image;};
    void setPos(int x, int y);
    QPixmap increaseAngle();
    int getAngle() const {return m_rotateAngle;};
//    static int m_sSpeed;
private:
    QPixmap m_image;
    double m_rotateAngle;
};

#endif // PLAYERCIRCLE_H
