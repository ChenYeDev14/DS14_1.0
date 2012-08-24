#ifndef BEGINBOTTUM_H
#define BEGINBOTTUM_H

#include <QWidget>
#include "ui_beginbottum.h"

namespace Ui {
class BeginBottum;
}

class BeginBottum : public QWidget
{
    Q_OBJECT
    
public:
    explicit BeginBottum(QWidget *parent = 0);
    ~BeginBottum();
    Ui::BeginBottum* returnUi();
    
private:
    Ui::BeginBottum *ui;
};

#endif // BEGINBOTTUM_H
