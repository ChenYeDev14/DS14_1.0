#ifndef LOGIC_H
#define LOGIC_H
#include <iostream>
#include "Status.h"

namespace DS14
{

class logic
{
private: 
	Status gameState;
	Names gameNames;
    bool FIRSTBLOOD;
public:
    logic() {FIRSTBLOOD = false;}
	void init(std::string dirctoryOfMap);//init from a map file.Liu Xiaoyu will do the job.
	GameInfo toPlayer(int side);//convert the status to send message to AIs.Wen Yuhao & Li Yudu will complete this function.
	void update (PlayerCommand * command1,PlayerCommand * command2);//update status using commands of AI.Zhou Erjin will complete this function.
    Status getStatus();

};

}

#endif
