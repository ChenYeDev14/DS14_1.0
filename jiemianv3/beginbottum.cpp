#include "beginbottum.h"
#include "ui_beginbottum.h"

BeginBottum::BeginBottum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BeginBottum)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);

    ui->startsingle->setDisabled(false);
    ui->webfight->setDisabled(true);
    ui->website->setDisabled(true);
    ui->team->setDisabled(true);
    ui->exitmain->setDisabled(false);
}

BeginBottum::~BeginBottum()
{
    delete ui;
}

Ui::BeginBottum* BeginBottum::returnUi()
{
    return ui;
}
