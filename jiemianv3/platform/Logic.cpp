#include "Logic.h"

using namespace DS14;

void logic::init(std::string dirctoryOfMap)
{
    gameState.roundNumber = 0;
    gameState.potInfo.AI1PotNumber = 1;
    gameState.potInfo.AI2PotNumber = 1;
}

Status logic::getStatus(){return gameState;}
