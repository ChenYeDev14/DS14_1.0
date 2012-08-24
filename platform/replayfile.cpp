#include "replayfile.h"
#include <QFile>
#include <QDateTime>

using namespace DS14;

ReplayFile::ReplayFile() {}

void ReplayFile::NewFile(QString playerName1, QString playerName2, QString mapName)
{
    QDateTime temptime=QDateTime::currentDateTime();
    file=new QFile(playerName1+"_vs_"+playerName2+"_inMap_"+mapName+"_atTime_"+temptime.toString("yyyy.MM.dd hh:mm:ss")+".rep");
}

void ReplayFile::WriteInitialInfo(const PlayerInfo &playerInfo1, const PlayerInfo &playerInfo2, const StatusMapInfo &mapInfo)
{
    if(file->open(QIODevice::ReadOnly))
    {
        int heronum;
        int lengthside1,lengthhero1[3],lengthside2,lengthhero2[3];
        //写玩家信息
        lengthside1=wcslen(playerInfo1.teamName)+1;
        lengthside2=wcslen(playerInfo2.teamName)+1;
        for(heronum=0;heronum<3;heronum++)
        {
            lengthhero1[heronum]=wcslen(playerInfo1.heroName[heronum])+1;
            lengthhero2[heronum]=wcslen(playerInfo2.heroName[heronum])+1;
        }

        file->write((const char*)(&lengthside1),sizeof(lengthside1));
        file->write((const char*)(playerInfo1.teamName),lengthside1*sizeof(wchar_t));
        for(heronum=0;heronum<3;heronum++)
        {
            file->write((const char*)(&lengthhero1[heronum]),sizeof(lengthhero1[heronum]));
            file->write((const char*)(playerInfo1.heroName[heronum]),lengthhero1[heronum]*sizeof(wchar_t));
        }

        file->write((const char*)(&lengthside2),sizeof(lengthside2));
        file->write((const char*)(playerInfo2.teamName),lengthside2*sizeof(wchar_t));
        for(heronum=0;heronum<3;heronum++)
        {
            file->write((const char*)(&lengthhero2[heronum]),sizeof(lengthhero2[heronum]));
            file->write((const char*)(playerInfo2.heroName[heronum]),lengthhero2[heronum]*sizeof(wchar_t));
        }
        //写地图信息
        file->write((const char*)(&mapInfo),sizeof(mapInfo));
    }
}

void ReplayFile::WriteRoundInfo(const Status &roundStatus)
{
    if(file->open(QIODevice::ReadOnly))
        file->write((const char*)(&roundStatus),sizeof(roundStatus));
}

void ReplayFile::WriteWinner(int winSide)
{
     if(file->open(QIODevice::ReadOnly))
        file->write((const char*)(&winSide),sizeof(winSide));
}

bool ReplayFile::OpenFile(QString path)
{
    file=new QFile(path);
    return file->open(QIODevice::ReadOnly);
}

void ReplayFile::ReadInitialInfo(PlayerInfo &playerInfo1, PlayerInfo &playerInfo2, StatusMapInfo &mapInfo)
{
    int heronum;
    //读玩家信息
    int lengthside1,lengthhero1[3],lengthside2,lengthhero2[3];

    file->read((char*)(&lengthside1),sizeof(lengthside1));
    wchar_t tempchar1[20];
    file->read((char*)tempchar1,lengthside1*sizeof(wchar_t));
    wcscpy(playerInfo1.teamName,tempchar1);
    for(heronum=0;heronum<3;heronum++)
    {
        file->read((char*)(&lengthhero1[heronum]),sizeof(lengthhero1[heronum]));
        wchar_t tempcharhero1[20];
        file->read((char*)tempcharhero1,lengthhero1[heronum]*sizeof(wchar_t));
        wcscpy(playerInfo1.heroName[heronum],tempcharhero1);
    }

    file->read((char*)(&lengthside2),sizeof(lengthside2));
    wchar_t tempchar2[20];
    file->read((char*)tempchar2,lengthside2*sizeof(wchar_t));
    wcscpy(playerInfo2.teamName,tempchar2);
    for(heronum=0;heronum<3;heronum++)
    {
        file->read((char*)(&lengthhero2[heronum]),sizeof(lengthhero2[heronum]));
        wchar_t tempcharhero2[20];
        file->read((char*)tempcharhero2,lengthhero2[heronum]*sizeof(wchar_t));
        wcscpy(playerInfo2.heroName[heronum],tempcharhero2);
    }
    //读地图信息
    file->read((char*)(&mapInfo),sizeof(mapInfo));
}


void ReplayFile::ReadAllRoundInfo(int &roundNum, Status *statusList[])
{
    int round=0;
    while(!file->atEnd())
    {
        statusList[round]=new Status;
        file->read((char*)statusList[round],sizeof(Status));
        round++;
    }
    roundNum=round;
}

void ReplayFile::ReadWinner(int &winSide)
{
    file->read((char*)(&winSide),sizeof(winSide));
}
