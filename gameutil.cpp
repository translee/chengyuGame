#include "gameutil.h"
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>
#include "constDef.h"
#include "humanplayer.h"
using namespace constDef;

QPixmap GameUtil::loadPixmap(const QString& path)
{
    QPixmap rawPixmap(path);
    if (rawPixmap.isNull())
        return QPixmap();

    QPixmap pixmap(CircleDiameter, CircleDiameter);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing |
                           QPainter::SmoothPixmapTransform);
    QRect rect(0, 0, CircleDiameter, CircleDiameter);
    QPainterPath paintPath;
    paintPath.addEllipse(0, 0, CircleDiameter, CircleDiameter);
    painter.setClipPath(paintPath);
    painter.drawPixmap(rect, rawPixmap.scaled(CircleDiameter,
                       CircleDiameter, Qt::IgnoreAspectRatio,
                                       Qt::SmoothTransformation));
    return pixmap;
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
