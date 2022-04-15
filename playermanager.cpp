#include "playermanager.h"
#include <npcplayer.h>
#include <humanplayer.h>
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

bool PlayerManager::addHumanPlayer()
{
    int nFreePos = static_cast<int>(m_vecFreePos.size());
    if (0 == nFreePos)
        return false;
    int pos = (rand() % (nFreePos));
    auto it = m_vecFreePos.begin() + pos;
    HumanPlayer* newPlayer = new HumanPlayer(it->x(),
            it->y(), ":imageRes/res/guangfa.jpg");
    m_vecFreePos.erase(it);
    m_vecHumans.push_back(newPlayer);
    return true;
}

void PlayerManager::addNPCPlayer(int x, int y)
{
    NPCPlayer* newPlayer = new NPCPlayer(x, y);
    m_vecNPCs.push_back(newPlayer);
    return;
}

void PlayerManager::initAllPosToNPC()
{
    int x = 0 + Space;
    int y = 0 + Space;
    for (int i = 0; i < ColNum - 1; i++)
    {
        addNPCPlayer(x, y);
        m_vecFreePos.push_back(QPoint(x, y));
        x += CircleDiameter;
    }
    for (int i = 0; i < RowNum - 1; i++)
    {
        addNPCPlayer(x, y);
        m_vecFreePos.push_back(QPoint(x, y));
        y += CircleDiameter;
    }
    for (int i = 0; i < ColNum - 1; i++)
    {
        addNPCPlayer(x, y);
        m_vecFreePos.push_back(QPoint(x, y));
        x -= CircleDiameter;
    }
    for (int i = 0; i < RowNum - 1; i++)
    {
        addNPCPlayer(x, y);
        m_vecFreePos.push_back(QPoint(x, y));
        y -= CircleDiameter;
    }
    return;
}

HumanPlayer PlayerManager::getHumanPlayersByIndex(size_t i) const
{
    if (i >= m_vecHumans.size())
        return HumanPlayer(0, 0, ":imageRes/res/npc.jpg");
    return *(m_vecHumans[i]);
}

bool PlayerManager::deleteHumanPlayer(size_t i)
{
    if (i >= m_vecHumans.size())
        return false;
    auto it = m_vecHumans.begin() + i;
    delete *it;
    m_vecHumans.erase(it);
    return true;
}
