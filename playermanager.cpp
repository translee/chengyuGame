#include "playermanager.h"
#include <player.h>
#include "constDef.h"

PlayerManager& PlayerManager::getInstance()
{
    static PlayerManager sManager;
    return sManager;
}

PlayerManager::~PlayerManager()
{
    for (Player* pt : m_vecPlayers)
        delete pt;
}

bool PlayerManager::addRandomPlayer()
{
    return true;
}

bool PlayerManager::addPlayer(int x, int y)
{
    Player* newPlayer = new Player();
    Player* newPlayer2 = new Player(150, constDef::Space);
    m_vecPlayers.push_back(newPlayer);
    m_vecPlayers.push_back(newPlayer2);
    return true;
}

