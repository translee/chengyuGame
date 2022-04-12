#ifndef GAMEUTIL_H
#define GAMEUTIL_H
#include <utility>
class QPixmap;
class QString;
class GameUtil
{
public:
    static QPixmap loadPixmap(const QString& path);
    static std::pair<int, int> getRotateOffset(int radius, int angle);
private:
    static QPixmap __pixmapToRound(const QPixmap& src, int diameter);
};

#endif // GAMEUTIL_H
