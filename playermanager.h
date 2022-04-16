/**
 * @class   PlayerManager
 * @author  github.com/translee
 * @date    2022/04/16
 * @brief   玩家管理类
 * @note
 * @warning 单例类
*/

#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include <vector>
#include "humanplayer.h"
class NPCPlayer;

class PlayerManager final
{
public:
    static PlayerManager& getInstance();
    PlayerManager(const PlayerManager&)=delete;
    PlayerManager& operator=(const PlayerManager&)=delete;
    ~PlayerManager();
public:
    bool addHumanPlayer(const QString& path);
    bool deleteHumanPlayer(size_t);
    void addNPCPlayer(int x, int y);
    void initAllPosToNPC();
    inline std::vector<NPCPlayer*> getAllNPCPlayers() const
                            { return m_vecNPCs; }
    inline std::vector<HumanPlayer*> getAllHumanPlayers() const
                            { return m_vecHumans; }
    HumanPlayer* getHumanPlayersByIndex(size_t i) const;
    QPixmap getALLPlayerStatusPixmap() const;
private:
    PlayerManager()=default;
private:
    std::vector<NPCPlayer*> m_vecNPCs;
    std::vector<HumanPlayer*> m_vecHumans;
    std::vector<QPoint> m_vecFreePos;
};

#endif // PLAYERMANAGER_H
