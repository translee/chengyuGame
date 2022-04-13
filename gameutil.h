#ifndef GAMEUTIL_H
#define GAMEUTIL_H
#include <vector>
class QPixmap;
class QString;
class QPoint;
class QRect;
class GameUtil
{
public:
    static QPixmap loadPixmap(const QString& path);
    static QPoint topLeft(const QRect& rect);
    static QPoint bottomLeft(const QRect& rect);
    static QPoint bottomRight(const QRect& rect);
    static QPoint topRight(const QRect& rect);
private:
    static QPixmap __pixmapToRound(const QPixmap& src, int diameter);
};

#endif // GAMEUTIL_H
