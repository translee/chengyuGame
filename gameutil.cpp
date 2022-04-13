#include "gameutil.h"
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>
#include "constDef.h"
using namespace constDef;

QPixmap GameUtil::loadPixmap(const QString& path)
{
    QPixmap scaledPixmap = QPixmap(path).scaled(PicSize, PicSize,
        Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPixmap circleImage = __pixmapToRound(path, PicSize);
    return circleImage;
}

QPoint GameUtil::topLeft(const QRect& rect)
{
    return rect.topLeft();
}

QPoint GameUtil::bottomLeft(const QRect& rect)
{
    QPoint realBottomLeft = rect.bottomLeft();
    realBottomLeft.ry() += 1;
    return realBottomLeft;
}

QPoint GameUtil::bottomRight(const QRect& rect)
{
    QPoint realBottomRight = rect.bottomRight();
    realBottomRight.rx() += 1;
    realBottomRight.ry() += 1;
    return realBottomRight;
}

QPoint GameUtil::topRight(const QRect& rect)
{
    QPoint realTopRight = rect.topRight();
    realTopRight.rx() += 1;
    return realTopRight;
}

QPixmap GameUtil::__pixmapToRound(const QPixmap& src, int diameter)
{
    if (src.isNull()) {
        return QPixmap();
    }
    QPixmap pixmap(diameter, diameter);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing |
                           QPainter::SmoothPixmapTransform);
    QPainterPath path;
    path.addEllipse(0, 0, diameter, diameter);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, diameter, diameter, src);
    return pixmap;
}
