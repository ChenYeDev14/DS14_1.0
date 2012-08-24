#ifndef CREATOR_H
#define CREATOR_H

#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QWidget>
#include <QGraphicsScene>
#include <QWindowsXPStyle>
#include <QApplication>
#include <QObject>
#include <QPushButton>

#include "rounditem.h"
#include "backwidget.h"
#include "beginbottum.h"
#include "clickbottum.h"
#include "aivsai.h"
#include "widgetssingle.h"

class Creator : public QGraphicsView
{
    Q_OBJECT

public:
    Creator(QApplication &);


private:
    RoundRectItem* pad;

    QGraphicsProxyWidget* backWindow;
    QGraphicsProxyWidget* beginWindow;
    QGraphicsProxyWidget* musicWindow;
    QGraphicsProxyWidget* aiWindow;
    QGraphicsProxyWidget* singleWindow;

    BackWidget* backWidget;
    BeginBottum* beginWidget;
    ClickBottum* musicWidget;
    AIvsAI* aiWidget;
    widgetssingle* singleWidget;

private slots:
    void BeginToSingle();
    void SingleToBegin();
    void SingleToAi();
    void AiToSingle();

};

#endif // CREATOR_H
