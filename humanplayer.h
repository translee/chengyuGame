#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "player.h"
class HumanPlayer : public Player
{
public:
    HumanPlayer(int x, int y, const QString& path);
};

#endif // HUMANPLAYER_H
