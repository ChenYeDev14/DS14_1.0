#include "creator.h"
#include <QtGui>
#include <QDebug>

Creator::Creator(QApplication &app)
{
    //建立pad
    pad = new RoundRectItem(QRectF(QPointF(0,0),QPointF(0,0)),QColor(0,0,255,0));
    pad->setZValue(0);

    //设置backwindow
    backWindow = new QGraphicsProxyWidget(pad);
    backWidget = new BackWidget();
    backWindow->setX(0);
    backWindow->setY(0);
 //   backWindow->widget()->setWindowOpacity(1);
    backWindow->setWidget(backWidget);
    backWindow->setZValue(0);


    //设置开始窗口按钮
    beginWindow = new QGraphicsProxyWidget(pad);
    beginWidget = new BeginBottum;
    beginWindow->setWidget(beginWidget);
    beginWindow->setX(backWindow->x()+320);
    beginWindow->setY(backWindow->y()+150);
    beginWindow->widget()->setWindowOpacity(1);
    beginWindow->setZValue(0.5);

    //设置音乐按键
    musicWindow = new QGraphicsProxyWidget(pad);
    musicWidget = new ClickBottum;
    musicWindow->setWidget(musicWidget);
    musicWindow->setX(backWindow->widget()->width()-120);
    musicWindow->setY(backWindow->y());
    musicWindow->widget()->setWindowOpacity(1);
    musicWindow->setZValue(0.9);


    //设置AI对战窗口
    aiWindow = new QGraphicsProxyWidget(pad);
    aiWidget = new AIvsAI();
    aiWindow->setWidget(aiWidget);
    aiWindow->setX(backWindow->x()+50);
    aiWindow->setY(backWindow->y()+50);
    aiWindow->widget()->setWindowOpacity(1);
    aiWindow->setZValue(0.5);

    singleWindow = new QGraphicsProxyWidget(pad);
    singleWidget = new widgetssingle;
    singleWindow->setWidget(singleWidget);
    singleWindow->setX(backWindow->x()+320);
    singleWindow->setY(backWindow->y()+150);
    singleWindow->widget()->setWindowOpacity(1);
    singleWindow->setZValue(0.5);

//  beginWindow->close();
    aiWindow->close();
    singleWindow->close();

    QObject::connect(beginWidget->returnUi()->exitmain,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(beginWidget->returnUi()->startsingle,SIGNAL(clicked()),this,SLOT(BeginToSingle()));
    connect(this->singleWidget->ui->returnpre,SIGNAL(clicked()),this,SLOT(SingleToBegin()));
    connect(this->singleWidget->ui->aivsai,SIGNAL(clicked()),this,SLOT(SingleToAi()));
    connect(this->aiWidget->ui->ReturnPre,SIGNAL(clicked()),this,SLOT(AiToSingle()));

    //设置界面背景
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addItem(pad);
    scene->setBackgroundBrush(QBrush(QColor(0,0,0,255)));
    scene->setSceneRect(scene->itemsBoundingRect());

    setScene(scene);
    showFullScreen();
}


void Creator::BeginToSingle()
{
    singleWindow->show();
    beginWindow->close();
 //   qDebug() << "lalala";
}


void Creator::SingleToBegin()
{
    singleWindow->close();
    beginWindow->show();
}

void Creator::SingleToAi()
{
    singleWindow->close();
    aiWindow->show();
}

void Creator::AiToSingle()
{
    aiWindow->close();
    singleWindow->show();
}
