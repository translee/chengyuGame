#ifndef PLAYERCIRCLE_H
#define PLAYERCIRCLE_H
#include <QPixmap>

class PlayerCircle
{
public:
    PlayerCircle();
private:
    QPixmap m_image;
    static int m_sSpeed;
};

#endif // PLAYERCIRCLE_H
