#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include <vector>

class Player;
class PlayerManager final
{
public:
    static PlayerManager& getInstance();
    PlayerManager(const PlayerManager&)=delete;
    PlayerManager& operator=(const PlayerManager&)=delete;
    ~PlayerManager();
public:
    bool addRandomPlayer();
    bool addPlayer(int x, int y);
    auto getAllPlayers() const {return m_vecPlayers;};
private:
    PlayerManager()=default;
private:
    std::vector<Player*> m_vecPlayers;
};

#endif // PLAYERMANAGER_H
