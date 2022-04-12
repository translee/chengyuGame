#ifndef GAMEUTIL_H
#define GAMEUTIL_H
class QPixmap;
class QString;
class GameUtil
{
public:
    static QPixmap loadPixmap(const QString& path);
private:
    static QPixmap __pixmapToRound(const QPixmap& src, int radius);
};

#endif // GAMEUTIL_H
