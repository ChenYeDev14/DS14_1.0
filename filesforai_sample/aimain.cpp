/*
ѡ�ֶ˳��� ����  ��׼ͨ��������

     ����������������ƽ̨������
     ��������������ӽӿڵķ�ʽ
##�뱣�ִ�������Ϊû�о����κ��޸ĵ�ԭ���׼������##
     ��������AI����ƽ̨���Ӵ�������и�

ѡ��ֻ��Ҫ��дInit��PlayerRun
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
        cerr << "��ӭ�μӵ�ʮ�Ľ��ʽ������ƴ�����"<<endl << "��ʹ�ö�ʽƽ̨�򿪴˳���" << endl;
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