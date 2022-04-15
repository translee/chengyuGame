#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "player.h"
class HumanPlayer : public Player
{
public:
    enum class Status {NORMAL, DEFFEND};
    HumanPlayer(int x, int y, const QString& path);
    QPixmap getStatusImage() const;
    static QRect getStatusRect() { return QRect(); };
private:
    int m_nScore;
    Status m_status;
};

#endif // HUMANPLAYER_H
