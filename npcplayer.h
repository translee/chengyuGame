/**
 * @class   NPCPlayer
 * @author  github.com/translee
 * @date    2022/04/16
 * @brief   NPC玩家
 * @note:
*/

#ifndef NPCPLAYER_H
#define NPCPLAYER_H
#include "player.h"

class NPCPlayer : public Player
{
public:
    NPCPlayer(int x, int y);
};

#endif // NPCPLAYER_H
