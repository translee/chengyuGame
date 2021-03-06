/**
 * @class   Player
 * @author  github.com/translee
 * @date    2022/04/16
 * @brief   玩家基类
 * @note
*/

#ifndef PLAYER_H
#define PLAYER_H
#include <QPixmap>

class Player
{
public:
    enum class Direction {Left, Down, Right, Up};
public:
    Player(int x, int y, const QString& path);
    virtual ~Player();
    inline const QPixmap& getImage() const { return m_image; }
    inline const QRect& getRect() const { return m_rect; }
    inline int getX() const { return m_rect.x(); }
    inline int getY() const { return m_rect.y(); }
    void moveNext();
private:
    static QRect m_sLimit;
    static int m_sSpeed;
    QPixmap m_image;
    QRect m_rect;
    Direction m_dir;
};

#endif // PLAYER_H
