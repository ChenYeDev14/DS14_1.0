#include "platform/Logic.h"
using namespace DS14;

void logic::init(std::string dirctoryOfMap)
{
    gameState.roundNumber = 0;
    gameState.potInfo.AI1PotNumber = 1;
    gameState.potInfo.AI2PotNumber = 1;
}
GameInfo logic::toPlayer(int side){ GameInfo info; info.roundNumber = gameState.roundNumber; return info;}
void logic::update (PlayerCommand * command1,PlayerCommand * command2){ gameState.roundNumber ++;}
void logic::toReplay(std::string directory, Status * statusToFile, Names * namesToFile){}
Status logic::getStatus(){return gameState;}
