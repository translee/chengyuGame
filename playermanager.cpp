#include <npcplayer.h>
#include <humanplayer.h>
#include "playermanager.h"
#include "constDef.h"
using namespace constDef;

PlayerManager& PlayerManager::getInstance()
{
    static PlayerManager sManager;
    return sManager;
}

PlayerManager::~PlayerManager()
{
    for (Player* pt : m_vecHumans)
        delete pt;
    for (Player* pt : m_vecNPCs)
        delete pt;
}

bool PlayerManager::addHumanPlayer(int x, int y)
{
    Player* newPlayer = new HumanPlayer(x,
            y, ":imageRes/res/guangfa.jpg");
    m_vecHumans.push_back(newPlayer);
    return true;
}

bool PlayerManager::addNPCPlayer(int x, int y)
{
    Player* newPlayer = new NPCPlayer(x, y);
    m_vecNPCs.push_back(newPlayer);
    return true;
}

std::vector<Player*> PlayerManager::getAllPlayers() const
{
    std::vector<Player*> allPlayers(m_vecNPCs);
    allPlayers.insert(allPlayers.end(), m_vecHumans.begin(),
                      m_vecHumans.end());
    return allPlayers;
}

void PlayerManager::initAllPosToNPC()
{
    int x = 0 + Space;
    int y = 0 + Space;
    for (int i = 0; i < ColNum - 1; i++)
    {
        addNPCPlayer(x, y);
        x += CircleDiameter;
    }
    for (int i = 0; i < RowNum - 1; i++)
    {
        addNPCPlayer(x, y);
        y += CircleDiameter;
    }
    for (int i = 0; i < ColNum - 1; i++)
    {
        addNPCPlayer(x, y);
        x -= CircleDiameter;
    }
    for (int i = 0; i < RowNum - 1; i++)
    {
        addNPCPlayer(x, y);
        y -= CircleDiameter;
    }
    return;
}
