#include "gameutil.h"
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>
#include "constDef.h"
using namespace constDef;

QPixmap GameUtil::loadPixmap(const QString& path)
{
    QSize RSize(CircleRadius * 2, CircleRadius * 2);
    QPixmap scaledPixmap = QPixmap(path).scaled(RSize, Qt::KeepAspectRatio);
    QPixmap circleImage = __pixmapToRound(path, CircleRadius);
    return circleImage;
}

QPixmap GameUtil::__pixmapToRound(const QPixmap& src, int radius)
{
    if (src.isNull()) {
        return QPixmap();
    }
    QPixmap pixmap(radius,radius);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPainterPath path;
    path.addEllipse(0, 0, radius, radius);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, radius, radius, src);
    return pixmap;
}
