#include "aivsai.h"
#include "ui_aivsai.h"
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
class QTextEdit;


AIvsAI::AIvsAI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AIvsAI)
{
    ui->setupUi(this);
    ui->progressBar->setRange(0, 2400);

    connect(ui->AI1,SIGNAL(clicked()),this,SLOT(AI1()));
    connect(ui->AI2,SIGNAL(clicked()),this,SLOT(AI2()));
    connect(ui->Start,SIGNAL(clicked()),this,SLOT(StartGame()));
    connect(ui->Map,SIGNAL(clicked()),this,SLOT(Map()));

    connect(&battle, SIGNAL(connect_error(int)),this,SLOT(connectError(int)));
    connect(&battle,SIGNAL(init_error(int)),this,SLOT(initError(int)));
    connect(&battle,SIGNAL(path_error(int)),this,SLOT(pathError(int)));
    connect(&battle,SIGNAL(send_winner(int)),this,SLOT(sendWinner(int)));
    connect(&battle,SIGNAL(round(int)),this,SLOT(round(int)));

    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);

//    ui->Start->setDisabled(true);
    ui->progressBar->setValue(0);


    ui->LineEditAI1->setText("C:/Users/ChenYe/Documents/Visual Studio 2010/Projects/DS14_AI/Release/DS14_AI.exe");
    ui->LineEditAI2->setText("C:/Users/ChenYe/Documents/Visual Studio 2010/Projects/DS14_AI/Debug/DS14_AI.exe");
    ui->LineEditMap->setText("C:/Users/ChenYe/Documents/Visual Studio 2010/Projects/DS14_AI/Release/DS14_AI.exe");



}

void AIvsAI::AI1()
{
    QString fileName = QFileDialog::getOpenFileName(
                        this,
                        tr("打开文件"),
                        "/home",
                        tr("任何文件(*.*)"";;文本文件(*.txt)"));
    ui->LineEditAI1->setText(fileName);

}

void AIvsAI::AI2()
{
    QString fileName = QFileDialog::getOpenFileName(
                        this,
                        tr("打开文件"),
                        "/home",
                        tr("任何文件(*.*)"";;文本文件(*.txt)"));
    ui->LineEditAI2->setText(fileName);
}

void AIvsAI::StartGame(){}

void AIvsAI::Map()
{
    QString fileName = QFileDialog::getOpenFileName(
                        this,
                        tr("打开文件"),
                        "/home",
                        tr("任何文件(*.*)"";;文本文件(*.txt)"));
    ui->LineEditMap->setText(fileName);
}

AIvsAI::~AIvsAI()
{
    delete ui;
}




void AIvsAI::on_Start_clicked()
{
    ui->Start->setEnabled(false);
    battle.StartNormalBattle(ui->LineEditAI1->text(), ui->LineEditAI2->text(), ui->LineEditMap->text());
}


void AIvsAI::connectError(int i)
{
    QString string;
    if ( i == 1 ) string = tr("AI1连接出错");
            else string = tr("AI2连接出错");
    QMessageBox::warning(this, QString(tr("连接错误")), string);
    ui->Start->setEnabled(true);
}


void AIvsAI::initError(int i)
{
    QString string;
    if ( i == 1 ) string = tr("AI1初始化出错");
            else string = tr("AI2初始化出错");
    QMessageBox::warning(this, QString(tr("初始化错误")), string);
    ui->Start->setEnabled(true);
}

void AIvsAI::pathError(int i)
{
    QString string;
    if ( i == 1 ) string = tr("AI1路径出错");
            else if ( i == 2 )string = tr("AI2路径出错");
    if ( i == 3 ) string =  tr("地图路径出错");
    QMessageBox::warning(this, QString(tr("路径错误")), string);
    ui->Start->setEnabled(true);
}

void AIvsAI::sendWinner(int i)
{
    QString string;
    if ( i == 1 ) string = tr("AI1获胜");
    else if ( i == 2 ) string = tr("AI2获胜");
    else if (i == 3) string = tr("平局");
    QMessageBox::information(this, QString(tr("结果")), string);
    ui->Start->setEnabled(true);
}

void AIvsAI::round(int i)
{
    ui->progressBar->setValue(i);
}
