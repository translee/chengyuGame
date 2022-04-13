#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include <vector>

//class Player;
class PlayerManager final
{
public:
    static PlayerManager& getInstance();
    PlayerManager(const PlayerManager&)=delete;
    PlayerManager& operator=(const PlayerManager&)=delete;
    ~PlayerManager();
public:
    bool addHumanPlayer(int x, int y);
    bool addNPCPlayer(int x, int y);
    void initAllPosToNPC();
    std::vector<Player*> getAllPlayers() const;
private:
    PlayerManager()=default;
private:
    std::vector<Player*> m_vecNPCs;
    std::vector<Player*> m_vecHumans;
};

#endif // PLAYERMANAGER_H
