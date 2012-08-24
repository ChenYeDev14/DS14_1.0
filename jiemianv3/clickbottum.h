#ifndef CLICKBOTTUM_H
#define CLICKBOTTUM_H

#include <QWidget>
#include "ui_clickbottum.h"

namespace Ui {
class ClickBottum;
}

class ClickBottum : public QWidget
{
    Q_OBJECT
    
public:
    explicit ClickBottum(QWidget *parent = 0);
    ~ClickBottum();
    
private:
    Ui::ClickBottum *ui;
};

#endif // CLICKBOTTUM_H
