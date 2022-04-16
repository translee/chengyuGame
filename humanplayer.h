/**
 * @class   HumanPlayer
 * @author  github.com/translee
 * @date    2022/04/16
 * @brief   真实玩家
 * @note
*/

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "player.h"

class HumanPlayer : public Player
{
public:
    enum class PlayerStatus {NORMAL, DEFFEND};
    HumanPlayer(int x, int y, const QString& path);
    inline int getScore() const {return m_nScore;}
    inline PlayerStatus getStatus() const { return m_status; }
    inline void setStatus(PlayerStatus st) { m_status = st; }
    QPixmap getStatusPixmap() const;
private:
    int m_nScore;
    int m_nBiliUID;
    QString m_strBiliName;
    PlayerStatus m_status;
};

#endif // HUMANPLAYER_H
