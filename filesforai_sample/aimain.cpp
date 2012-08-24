/*
选手端程序 ——  标准通信主函数

     此主函数建立了与平台的连接
     采用随机命名连接接口的方式
##请保持此主函数为没有经过任何修改的原版标准主函数##
     否则您的AI将与平台连接错误而被判负

选手只需要编写Init和PlayerRun
*/


#pragma once



#include <cwchar>
#include <windows.h>
#include <iostream>
#include <ctime>
#include "Basic.h"
#include <string.h>

using namespace DS14;
using namespace std;


void Init(PlayerInfo &playerInfo);
void PlayerRun();

HANDLE hcontestt;
wchar_t *ff;
int wmain(int argc, wchar_t * argv[])
{
    PlayerInfo playerInfo;
	LPWSTR lpFileName = new wchar_t [100];
    wcscpy(lpFileName, L"\\\\.\\pipe\\DS14") ;
	if (argc==2)
	{
		ff = argv[2];
		wcscat(lpFileName,argv[1]);
		wcscat(lpFileName,L"\\");
	}
    hcontestt = CreateFileW(lpFileName, GENERIC_WRITE|GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if( hcontestt == INVALID_HANDLE_VALUE )
	{
        cerr << "欢迎参加第十四届队式程序设计大赛！"<<endl << "请使用队式平台打开此程序！" << endl;
	}
	else 
	{
	    DWORD dwRead = 0, dwWritten = 0;
        Init(playerInfo);
        WriteFile(hcontestt, (char*)&playerInfo, sizeof(playerInfo), &dwWritten, NULL);
        PlayerRun();
	}
	return 0;
}

GameInfo GetGameInfo()
{
	DWORD dwRead = 0, dwWritten = 0;
	char f = 'r';
	WriteFile(hcontestt, &f, sizeof(f), &dwWritten, NULL);
	GameInfo gInfo;
	
	while (!ReadFile(hcontestt, (char*)&gInfo, sizeof(gInfo), &dwRead, NULL));
	return gInfo;
}

void GiveCommand(const PlayerCommand &command)
{
	DWORD dwWritten = 0;
	char f = 'w';
	WriteFile(hcontestt, &f, sizeof(f), &dwWritten, NULL);
	WriteFile(hcontestt, (char*)&command, sizeof(command), &dwWritten, NULL);
}