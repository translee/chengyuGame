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

std::pair<int, int> GameUtil::getRotateOffset(int radius, int angle)
{
    int bigRadius = sqrt(2.0) * radius;
    int centerX = radius;
    int centerY = -radius;
    // 用圆的参数方程计算圆上点坐标
    int x = centerX + radius * cos(angle / 180.0 * PI);
    int y = centerY + radius * sin(angle / 180.0 * PI);
    return {x, y};
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
