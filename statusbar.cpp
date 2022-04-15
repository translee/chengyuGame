#include "statusbar.h"
#include <QPainter>
#include "constDef.h"
using namespace constDef;

int StatusBar::m_sWidth = StatusWidth;
int StatusBar::m_sHeight = StatusHeight;

StatusBar::StatusBar()
{

}

QPixmap StatusBar::getImage()
{
    QPixmap pixmap(m_sWidth, m_sHeight);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing |
                           QPainter::SmoothPixmapTransform);
    painter.setPen(QPen(Qt::darkCyan,1,Qt::SolidLine));
    painter.drawRect(0, 0, m_sWidth, m_sWidth);
    return pixmap;
}
