#include "humanplayer.h"
#include <QPainter>
#include "player.h"
#include "constDef.h"
using namespace constDef;

HumanPlayer::HumanPlayer(int x, int y, const QString& path)
    : Player(x, y, path)
    , m_nScore(0)
    , m_nBiliUID(0)
    , m_strBiliName()
    , m_status(PlayerStatus::NORMAL)
{
}

QPixmap HumanPlayer::getStatusPixmap() const
{
    // 绘制状态栏
    QPixmap pixmap(StatusWidth, StatusHeight);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
//    painter.setRenderHints(QPainter::Antialiasing |
//                           QPainter::SmoothPixmapTransform);
    painter.setPen(QPen(Qt::darkCyan,2,Qt::SolidLine));
    painter.setBrush(QBrush(QColor(255, 255, 255)));
    // 0.绘制矩形框
    if (PlayerStatus::DEFFEND == m_status)
        painter.setBrush(QBrush(QColor(255, 200, 200)));
    painter.drawRect(0, 0, StatusWidth, StatusHeight);
    // 1.绘制头像
    painter.drawPixmap((StatusWidth - CircleDiameter) / 2, Space,
                        getImage());
    // 2.绘制金币
    painter.setFont(QFont("simsun", 10, 500));
    painter.drawText(1, 65, "金币");
    painter.drawText(5, 85, QString::number(m_nScore));
    // 3.绘制状态
    painter.drawText(1, 110, "状态");
    QString strStatus("普通");
    if (PlayerStatus::DEFFEND == m_status)
        strStatus = "防御";
    painter.drawText(1, 130, strStatus);
    return pixmap;
}
