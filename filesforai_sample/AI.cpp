#include "Basic.h"
#include <wchar.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctime>


using namespace std;
using namespace DS14;



/* ����Ϊaimain.cpp���ṩ�ļ�����ƽ̨�����Ľӿ� */
GameInfo GetGameInfo();	//��ƽ̨��ȡ��ǰ��Ϸ��Ϣ
void GiveCommand(const PlayerCommand &command); //��ƽ̨д����Ϸָ���ָ��������һ���غ�ִ��


void Init(PlayerInfo &playerInfo)
{
    //���ڴ˸���Ķ����Լ�Ӣ����һ�����֣���ʼ������̣�

    wcscpy(playerInfo.teamName,L"myteam");//�������������֣�������20���� ����Ϊ�գ�
    wcscpy(playerInfo.heroName[0],L"Hero1");//����˫����������Ӣ��1�����֣�������9���֣����������ģ�
    wcscpy(playerInfo.heroName[1],L"Hero2");//����˫����������Ӣ��2������
    wcscpy(playerInfo.heroName[2],L"Hero3");//����˫����������Ӣ��3������

	//ע�⣡��Ҫɾ������ǰ��L
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
		//���㡢���ԡ�����
		command.heroOrder[0] = walk;
		Coordinate t;
		t.x = 1; t.y = 1;
		command.target[0] = t;
		GiveCommand(command);
	}
}
