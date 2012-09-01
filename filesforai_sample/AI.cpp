#include "Basic.h"
#include <wchar.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctime>


using namespace std;
using namespace DS14;



/* 以下为aimain.cpp中提供的几个与平台交互的接口 */
GameInfo GetGameInfo();	//从平台获取当前游戏信息
void GiveCommand(const PlayerCommand &command); //向平台写入游戏指令，该指令将在最近的一个回合执行


void Init(PlayerInfo &playerInfo)
{
    //请在此给你的队伍以及英雄起一个名字，开始你的征程！

    wcscpy(playerInfo.teamName,L"myteam");//请输入队伍的名字，不超过20个字 不能为空！
    wcscpy(playerInfo.heroName[0],L"Hero1");//请在双引号内输入英雄1的名字，不超过9个字（可以输中文）
    wcscpy(playerInfo.heroName[1],L"Hero2");//请在双引号内输入英雄2的名字
    wcscpy(playerInfo.heroName[2],L"Hero3");//请在双引号内输入英雄3的名字

	//注意！不要删掉引号前的L
}

void PlayerRun()
{
	GameInfo gInfo;
	PlayerCommand command;
	ofstream file;
	
	srand(unsigned(time(NULL)));
	int x = rand();
	char *c = new char[20];
	itoa(x, c, 10);
	string s = c;
	s.append("a.txt");
	file.open(s ,ios::trunc);
	delete c;
	while (true)
	{
		gInfo = GetGameInfo();
		if (gInfo.roundNumber >= 2300) 
		{
			file.close();
			int a = 0;
			//int x = 100 / a;
		}
		else file << gInfo.roundNumber <<endl;
		//计算、策略、决策
		command.heroOrder[0] = walk;
		Coordinate t;
		t.x = 1; t.y = 1;
		command.target[0] = t;
		GiveCommand(command);
	}
}
