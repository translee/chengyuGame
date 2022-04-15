#include "humanplayer.h"
#include <QPainter>
#include "player.h"
#include "constDef.h"
using namespace constDef;

HumanPlayer::HumanPlayer(int x, int y, const QString& path)
    : Player(x, y, path)
{
}

QPixmap HumanPlayer::getStatusImage() const
{
    QPixmap pixmap(StatusWidth, StatusHeight);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing |
                           QPainter::SmoothPixmapTransform);
    painter.setPen(QPen(Qt::darkCyan,1,Qt::SolidLine));
    painter.drawRect(0, 0, 18, 18);
    return pixmap;
}
