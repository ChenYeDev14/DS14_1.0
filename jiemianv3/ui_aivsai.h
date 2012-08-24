/********************************************************************************
** Form generated from reading UI file 'aivsai.ui'
**
** Created: Sun Jul 15 15:57:35 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIVSAI_H
#define UI_AIVSAI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AIvsAI
{
public:
    QProgressBar *progressBar;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Start;
    QPushButton *ReturnPre;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *AI1;
    QLineEdit *LineEditAI1;
    QLineEdit *LineEditMap;
    QLineEdit *LineEditAI2;
    QPushButton *Map;
    QPushButton *AI2;

    void setupUi(QWidget *AIvsAI)
    {
        if (AIvsAI->objectName().isEmpty())
            AIvsAI->setObjectName(QString::fromUtf8("AIvsAI"));
        AIvsAI->resize(880, 620);
        progressBar = new QProgressBar(AIvsAI);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(60, 510, 371, 20));
        progressBar->setValue(24);
        layoutWidget = new QWidget(AIvsAI);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(660, 460, 131, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Start = new QPushButton(layoutWidget);
        Start->setObjectName(QString::fromUtf8("Start"));

        verticalLayout->addWidget(Start);

        ReturnPre = new QPushButton(layoutWidget);
        ReturnPre->setObjectName(QString::fromUtf8("ReturnPre"));

        verticalLayout->addWidget(ReturnPre);

        widget = new QWidget(AIvsAI);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 50, 299, 301));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(12);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        AI1 = new QPushButton(widget);
        AI1->setObjectName(QString::fromUtf8("AI1"));

        gridLayout->addWidget(AI1, 0, 0, 1, 1);

        LineEditAI1 = new QLineEdit(widget);
        LineEditAI1->setObjectName(QString::fromUtf8("LineEditAI1"));

        gridLayout->addWidget(LineEditAI1, 0, 1, 1, 1);

        LineEditMap = new QLineEdit(widget);
        LineEditMap->setObjectName(QString::fromUtf8("LineEditMap"));

        gridLayout->addWidget(LineEditMap, 2, 1, 1, 1);

        LineEditAI2 = new QLineEdit(widget);
        LineEditAI2->setObjectName(QString::fromUtf8("LineEditAI2"));

        gridLayout->addWidget(LineEditAI2, 1, 1, 1, 1);

        Map = new QPushButton(widget);
        Map->setObjectName(QString::fromUtf8("Map"));

        gridLayout->addWidget(Map, 2, 0, 1, 1);

        AI2 = new QPushButton(widget);
        AI2->setObjectName(QString::fromUtf8("AI2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AI2->sizePolicy().hasHeightForWidth());
        AI2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(AI2, 1, 0, 1, 1);


        retranslateUi(AIvsAI);

        QMetaObject::connectSlotsByName(AIvsAI);
    } // setupUi

    void retranslateUi(QWidget *AIvsAI)
    {
        AIvsAI->setWindowTitle(QApplication::translate("AIvsAI", "Form", 0, QApplication::UnicodeUTF8));
        Start->setText(QApplication::translate("AIvsAI", "\345\274\200\345\247\213\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        ReturnPre->setText(QApplication::translate("AIvsAI", "\350\277\224\345\233\236\344\270\212\347\272\247", 0, QApplication::UnicodeUTF8));
        AI1->setText(QApplication::translate("AIvsAI", "\350\275\275\345\205\245AI1", 0, QApplication::UnicodeUTF8));
        Map->setText(QApplication::translate("AIvsAI", "\350\275\275\345\205\245\345\234\260\345\233\276", 0, QApplication::UnicodeUTF8));
        AI2->setText(QApplication::translate("AIvsAI", "\350\275\275\345\205\245AI2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AIvsAI: public Ui_AIvsAI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIVSAI_H
