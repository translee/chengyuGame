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
    bool addHumanPlayer();
    bool deleteHumanPlayer(size_t);
    void addNPCPlayer(int x, int y);
    void initAllPosToNPC();
    std::vector<NPCPlayer*> getAllNPCPlayers() const { return m_vecNPCs; };
    std::vector<HumanPlayer*> getAllHumanPlayers() const { return m_vecHumans; };
    HumanPlayer getHumanPlayersByIndex(size_t i) const;
private:
    PlayerManager()=default;
private:
    std::vector<NPCPlayer*> m_vecNPCs;
    std::vector<HumanPlayer*> m_vecHumans;
    std::vector<QPoint> m_vecFreePos;
};

#endif // PLAYERMANAGER_H
