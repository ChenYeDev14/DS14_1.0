#include <QApplication>
#include <QtGui>
#include "creator.h"



int main(int argc, char*argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));
    Creator* creator = new Creator(app);
    creator->show();

    return app.exec();
}
