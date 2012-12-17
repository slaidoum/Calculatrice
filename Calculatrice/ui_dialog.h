/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Tue Jun 19 01:16:57 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QListWidget *pile;
    QListWidget *history;
    QLabel *label;
    QLabel *label_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *butDQuit;
    QPushButton *butCleanHistory;
    QSpinBox *spinBox;
    QLabel *label_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(750, 420);
        Dialog->setMinimumSize(QSize(750, 420));
        Dialog->setMaximumSize(QSize(750, 420));
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 731, 331));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pile = new QListWidget(gridLayoutWidget);
        pile->setObjectName(QString::fromUtf8("pile"));

        gridLayout->addWidget(pile, 1, 0, 1, 1);

        history = new QListWidget(gridLayoutWidget);
        history->setObjectName(QString::fromUtf8("history"));

        gridLayout->addWidget(history, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(Dialog);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(380, 350, 361, 71));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        butDQuit = new QPushButton(gridLayoutWidget_2);
        butDQuit->setObjectName(QString::fromUtf8("butDQuit"));

        gridLayout_2->addWidget(butDQuit, 0, 1, 1, 1);

        butCleanHistory = new QPushButton(gridLayoutWidget_2);
        butCleanHistory->setObjectName(QString::fromUtf8("butCleanHistory"));

        gridLayout_2->addWidget(butCleanHistory, 0, 0, 1, 1);

        spinBox = new QSpinBox(Dialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(230, 372, 60, 27));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 370, 181, 31));

        retranslateUi(Dialog);
        QObject::connect(butDQuit, SIGNAL(clicked()), Dialog, SLOT(close()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Stack and History", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Stack", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "History", 0, QApplication::UnicodeUTF8));
        butDQuit->setText(QApplication::translate("Dialog", "Quit", 0, QApplication::UnicodeUTF8));
        butDQuit->setShortcut(QApplication::translate("Dialog", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        butCleanHistory->setText(QApplication::translate("Dialog", "Clear the history ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Stack number elements :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
