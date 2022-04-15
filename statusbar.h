#ifndef STATUSBAR_H
#define STATUSBAR_H
#include <QPixmap>

class StatusBar
{
public:
    StatusBar();
    int getBarWidth() const { return m_sWidth; };
    int getBarHeight() const { return m_sHeight; };
    QPixmap getImage();
private:
    static int m_sWidth;
    static int m_sHeight;
};

#endif // STATUSBAR_H
