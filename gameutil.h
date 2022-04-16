/**
 * @class   GameUtil
 * @author  github.com/translee
 * @date    2022/04/16
 * @brief   游戏工具类
 * @note
 * @warning 均为静态成员函数
*/

#ifndef GAMEUTIL_H
#define GAMEUTIL_H
#include <vector>
class QPixmap;
class QString;
class QPoint;
class QRect;
class HumanPlayer;

class GameUtil
{
public:
    static QPixmap loadPixmap(const QString& path);
    static QPoint topLeft(const QRect& rect);
    static QPoint bottomLeft(const QRect& rect);
    static QPoint bottomRight(const QRect& rect);
    static QPoint topRight(const QRect& rect);
};

#endif // GAMEUTIL_H
