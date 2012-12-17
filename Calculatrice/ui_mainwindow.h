/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Jun 19 01:28:16 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAide;
    QAction *actionQuitter;
    QAction *actionAnnuler;
    QAction *actionRetablir;
    QAction *actionKeyboard;
    QAction *actionDialog_Windows;
    QAction *actionParameters;
    QAction *actionComplex_Mode;
    QAction *actionRadians;
    QAction *actionDegrees;
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *butmod;
    QPushButton *butcube;
    QPushButton *buttanh;
    QPushButton *butcos;
    QPushButton *butinv;
    QPushButton *butcosh;
    QPushButton *buttan;
    QPushButton *butfact;
    QPushButton *butsin;
    QPushButton *butsinh;
    QPushButton *butsqr;
    QPushButton *butsqrt;
    QPushButton *butlog;
    QPushButton *butln;
    QPushButton *butpow;
    QPushButton *butsign;
    QPushButton *butdel;
    QPushButton *butRandomCmd;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *butpoint;
    QPushButton *butsoustraction;
    QPushButton *but5;
    QPushButton *but1;
    QPushButton *but6;
    QPushButton *but7;
    QPushButton *but9;
    QPushButton *but8;
    QPushButton *but2;
    QPushButton *but3;
    QPushButton *but0;
    QPushButton *butCote;
    QPushButton *butBackspace;
    QPushButton *butdivision;
    QPushButton *butespace;
    QPushButton *butdollar;
    QPushButton *butmultiplication;
    QPushButton *butenter;
    QPushButton *buteval;
    QPushButton *butaddition;
    QPushButton *but4;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QPushButton *butclear;
    QPushButton *butdup;
    QPushButton *butdrop;
    QPushButton *butsum;
    QPushButton *butswap;
    QPushButton *butmean;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *messagesCalculette;
    QFrame *line_5;
    QLabel *label;
    QFrame *line_6;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioRadians;
    QRadioButton *radioDegres;
    QCheckBox *checkBoxComplex;
    QLabel *lastPile;
    QFrame *line;
    QMenuBar *menuBar;
    QMenu *menuApplication;
    QMenu *menuEdition;
    QMenu *menuOptions;
    QMenu *menuOptions_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(830, 420);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(830, 420));
        MainWindow->setMaximumSize(QSize(830, 420));
        actionAide = new QAction(MainWindow);
        actionAide->setObjectName(QString::fromUtf8("actionAide"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionAnnuler = new QAction(MainWindow);
        actionAnnuler->setObjectName(QString::fromUtf8("actionAnnuler"));
        actionRetablir = new QAction(MainWindow);
        actionRetablir->setObjectName(QString::fromUtf8("actionRetablir"));
        actionKeyboard = new QAction(MainWindow);
        actionKeyboard->setObjectName(QString::fromUtf8("actionKeyboard"));
        actionKeyboard->setCheckable(true);
        actionKeyboard->setChecked(true);
        actionDialog_Windows = new QAction(MainWindow);
        actionDialog_Windows->setObjectName(QString::fromUtf8("actionDialog_Windows"));
        actionDialog_Windows->setCheckable(true);
        actionDialog_Windows->setChecked(true);
        actionParameters = new QAction(MainWindow);
        actionParameters->setObjectName(QString::fromUtf8("actionParameters"));
        actionComplex_Mode = new QAction(MainWindow);
        actionComplex_Mode->setObjectName(QString::fromUtf8("actionComplex_Mode"));
        actionComplex_Mode->setCheckable(true);
        actionRadians = new QAction(MainWindow);
        actionRadians->setObjectName(QString::fromUtf8("actionRadians"));
        actionRadians->setCheckable(true);
        actionDegrees = new QAction(MainWindow);
        actionDegrees->setObjectName(QString::fromUtf8("actionDegrees"));
        actionDegrees->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 0, 801, 71));
        QPalette palette;
        QBrush brush(QColor(0, 0, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(31, 16, 242, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(134, 125, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(82, 70, 248, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(15, 8, 121, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(20, 10, 161, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        QBrush brush8(QColor(143, 135, 248, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        QBrush brush9(QColor(255, 255, 220, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        lineEdit->setPalette(palette);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        lineEdit->setFont(font);
        lineEdit->setDragEnabled(true);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(270, 150, 281, 201));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        butmod = new QPushButton(gridLayoutWidget);
        butmod->setObjectName(QString::fromUtf8("butmod"));

        gridLayout->addWidget(butmod, 0, 0, 1, 1);

        butcube = new QPushButton(gridLayoutWidget);
        butcube->setObjectName(QString::fromUtf8("butcube"));

        gridLayout->addWidget(butcube, 6, 2, 1, 1);

        buttanh = new QPushButton(gridLayoutWidget);
        buttanh->setObjectName(QString::fromUtf8("buttanh"));

        gridLayout->addWidget(buttanh, 4, 2, 1, 1);

        butcos = new QPushButton(gridLayoutWidget);
        butcos->setObjectName(QString::fromUtf8("butcos"));

        gridLayout->addWidget(butcos, 3, 1, 1, 1);

        butinv = new QPushButton(gridLayoutWidget);
        butinv->setObjectName(QString::fromUtf8("butinv"));

        gridLayout->addWidget(butinv, 5, 2, 1, 1);

        butcosh = new QPushButton(gridLayoutWidget);
        butcosh->setObjectName(QString::fromUtf8("butcosh"));

        gridLayout->addWidget(butcosh, 4, 1, 1, 1);

        buttan = new QPushButton(gridLayoutWidget);
        buttan->setObjectName(QString::fromUtf8("buttan"));

        gridLayout->addWidget(buttan, 3, 2, 1, 1);

        butfact = new QPushButton(gridLayoutWidget);
        butfact->setObjectName(QString::fromUtf8("butfact"));

        gridLayout->addWidget(butfact, 7, 0, 1, 1);

        butsin = new QPushButton(gridLayoutWidget);
        butsin->setObjectName(QString::fromUtf8("butsin"));

        gridLayout->addWidget(butsin, 3, 0, 1, 1);

        butsinh = new QPushButton(gridLayoutWidget);
        butsinh->setObjectName(QString::fromUtf8("butsinh"));

        gridLayout->addWidget(butsinh, 4, 0, 1, 1);

        butsqr = new QPushButton(gridLayoutWidget);
        butsqr->setObjectName(QString::fromUtf8("butsqr"));

        gridLayout->addWidget(butsqr, 6, 1, 1, 1);

        butsqrt = new QPushButton(gridLayoutWidget);
        butsqrt->setObjectName(QString::fromUtf8("butsqrt"));

        gridLayout->addWidget(butsqrt, 6, 0, 1, 1);

        butlog = new QPushButton(gridLayoutWidget);
        butlog->setObjectName(QString::fromUtf8("butlog"));

        gridLayout->addWidget(butlog, 5, 1, 1, 1);

        butln = new QPushButton(gridLayoutWidget);
        butln->setObjectName(QString::fromUtf8("butln"));

        gridLayout->addWidget(butln, 5, 0, 1, 1);

        butpow = new QPushButton(gridLayoutWidget);
        butpow->setObjectName(QString::fromUtf8("butpow"));

        gridLayout->addWidget(butpow, 0, 1, 1, 1);

        butsign = new QPushButton(gridLayoutWidget);
        butsign->setObjectName(QString::fromUtf8("butsign"));

        gridLayout->addWidget(butsign, 0, 2, 1, 1);

        butdel = new QPushButton(gridLayoutWidget);
        butdel->setObjectName(QString::fromUtf8("butdel"));

        gridLayout->addWidget(butdel, 7, 2, 1, 1);

        butRandomCmd = new QPushButton(gridLayoutWidget);
        butRandomCmd->setObjectName(QString::fromUtf8("butRandomCmd"));

        gridLayout->addWidget(butRandomCmd, 7, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(570, 150, 251, 201));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        butpoint = new QPushButton(gridLayoutWidget_2);
        butpoint->setObjectName(QString::fromUtf8("butpoint"));

        gridLayout_2->addWidget(butpoint, 1, 4, 1, 1);

        butsoustraction = new QPushButton(gridLayoutWidget_2);
        butsoustraction->setObjectName(QString::fromUtf8("butsoustraction"));

        gridLayout_2->addWidget(butsoustraction, 0, 3, 1, 1);

        but5 = new QPushButton(gridLayoutWidget_2);
        but5->setObjectName(QString::fromUtf8("but5"));

        gridLayout_2->addWidget(but5, 3, 2, 1, 1);

        but1 = new QPushButton(gridLayoutWidget_2);
        but1->setObjectName(QString::fromUtf8("but1"));

        gridLayout_2->addWidget(but1, 1, 1, 1, 1);

        but6 = new QPushButton(gridLayoutWidget_2);
        but6->setObjectName(QString::fromUtf8("but6"));

        gridLayout_2->addWidget(but6, 3, 3, 1, 1);

        but7 = new QPushButton(gridLayoutWidget_2);
        but7->setObjectName(QString::fromUtf8("but7"));

        gridLayout_2->addWidget(but7, 4, 1, 1, 1);

        but9 = new QPushButton(gridLayoutWidget_2);
        but9->setObjectName(QString::fromUtf8("but9"));

        gridLayout_2->addWidget(but9, 4, 3, 1, 1);

        but8 = new QPushButton(gridLayoutWidget_2);
        but8->setObjectName(QString::fromUtf8("but8"));

        gridLayout_2->addWidget(but8, 4, 2, 1, 1);

        but2 = new QPushButton(gridLayoutWidget_2);
        but2->setObjectName(QString::fromUtf8("but2"));

        gridLayout_2->addWidget(but2, 1, 2, 1, 1);

        but3 = new QPushButton(gridLayoutWidget_2);
        but3->setObjectName(QString::fromUtf8("but3"));

        gridLayout_2->addWidget(but3, 1, 3, 1, 1);

        but0 = new QPushButton(gridLayoutWidget_2);
        but0->setObjectName(QString::fromUtf8("but0"));

        gridLayout_2->addWidget(but0, 5, 1, 1, 2);

        butCote = new QPushButton(gridLayoutWidget_2);
        butCote->setObjectName(QString::fromUtf8("butCote"));

        gridLayout_2->addWidget(butCote, 3, 4, 1, 1);

        butBackspace = new QPushButton(gridLayoutWidget_2);
        butBackspace->setObjectName(QString::fromUtf8("butBackspace"));

        gridLayout_2->addWidget(butBackspace, 5, 4, 1, 1);

        butdivision = new QPushButton(gridLayoutWidget_2);
        butdivision->setObjectName(QString::fromUtf8("butdivision"));

        gridLayout_2->addWidget(butdivision, 0, 4, 1, 1);

        butespace = new QPushButton(gridLayoutWidget_2);
        butespace->setObjectName(QString::fromUtf8("butespace"));

        gridLayout_2->addWidget(butespace, 5, 3, 1, 1);

        butdollar = new QPushButton(gridLayoutWidget_2);
        butdollar->setObjectName(QString::fromUtf8("butdollar"));

        gridLayout_2->addWidget(butdollar, 4, 4, 1, 1);

        butmultiplication = new QPushButton(gridLayoutWidget_2);
        butmultiplication->setObjectName(QString::fromUtf8("butmultiplication"));

        gridLayout_2->addWidget(butmultiplication, 0, 2, 1, 1);

        butenter = new QPushButton(gridLayoutWidget_2);
        butenter->setObjectName(QString::fromUtf8("butenter"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        butenter->setFont(font1);

        gridLayout_2->addWidget(butenter, 6, 1, 1, 2);

        buteval = new QPushButton(gridLayoutWidget_2);
        buteval->setObjectName(QString::fromUtf8("buteval"));

        gridLayout_2->addWidget(buteval, 6, 3, 1, 2);

        butaddition = new QPushButton(gridLayoutWidget_2);
        butaddition->setObjectName(QString::fromUtf8("butaddition"));

        gridLayout_2->addWidget(butaddition, 0, 1, 1, 1);

        but4 = new QPushButton(gridLayoutWidget_2);
        but4->setObjectName(QString::fromUtf8("but4"));

        gridLayout_2->addWidget(but4, 3, 1, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(20, 280, 231, 71));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        butclear = new QPushButton(gridLayoutWidget_3);
        butclear->setObjectName(QString::fromUtf8("butclear"));

        gridLayout_3->addWidget(butclear, 2, 0, 1, 1);

        butdup = new QPushButton(gridLayoutWidget_3);
        butdup->setObjectName(QString::fromUtf8("butdup"));

        gridLayout_3->addWidget(butdup, 2, 1, 1, 1);

        butdrop = new QPushButton(gridLayoutWidget_3);
        butdrop->setObjectName(QString::fromUtf8("butdrop"));

        gridLayout_3->addWidget(butdrop, 2, 2, 1, 1);

        butsum = new QPushButton(gridLayoutWidget_3);
        butsum->setObjectName(QString::fromUtf8("butsum"));

        gridLayout_3->addWidget(butsum, 0, 1, 1, 1);

        butswap = new QPushButton(gridLayoutWidget_3);
        butswap->setObjectName(QString::fromUtf8("butswap"));

        gridLayout_3->addWidget(butswap, 0, 0, 1, 1);

        butmean = new QPushButton(gridLayoutWidget_3);
        butmean->setObjectName(QString::fromUtf8("butmean"));

        gridLayout_3->addWidget(butmean, 0, 2, 1, 1);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(250, 139, 20, 211));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(550, 139, 20, 211));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        messagesCalculette = new QLabel(centralWidget);
        messagesCalculette->setObjectName(QString::fromUtf8("messagesCalculette"));
        messagesCalculette->setGeometry(QRect(25, 80, 371, 51));
        messagesCalculette->setMinimumSize(QSize(350, 0));
        messagesCalculette->setMaximumSize(QSize(391, 16777215));
        QFont font2;
        font2.setPointSize(11);
        font2.setItalic(false);
        messagesCalculette->setFont(font2);
        messagesCalculette->setWordWrap(true);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(20, 130, 801, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 252, 231, 31));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(true);
        font3.setUnderline(false);
        font3.setWeight(50);
        label->setFont(font3);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(19, 245, 241, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 148, 189, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioRadians = new QRadioButton(layoutWidget);
        radioRadians->setObjectName(QString::fromUtf8("radioRadians"));
        radioRadians->setChecked(true);

        verticalLayout->addWidget(radioRadians);

        radioDegres = new QRadioButton(layoutWidget);
        radioDegres->setObjectName(QString::fromUtf8("radioDegres"));

        verticalLayout->addWidget(radioDegres);

        checkBoxComplex = new QCheckBox(layoutWidget);
        checkBoxComplex->setObjectName(QString::fromUtf8("checkBoxComplex"));
        QFont font4;
        font4.setBold(false);
        font4.setWeight(50);
        checkBoxComplex->setFont(font4);

        verticalLayout->addWidget(checkBoxComplex);

        lastPile = new QLabel(centralWidget);
        lastPile->setObjectName(QString::fromUtf8("lastPile"));
        lastPile->setGeometry(QRect(420, 80, 391, 51));
        lastPile->setMinimumSize(QSize(361, 0));
        QFont font5;
        font5.setBold(true);
        font5.setItalic(false);
        font5.setWeight(75);
        lastPile->setFont(font5);
        lastPile->setWordWrap(true);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(397, 90, 20, 31));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 830, 25));
        menuApplication = new QMenu(menuBar);
        menuApplication->setObjectName(QString::fromUtf8("menuApplication"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuOptions_2 = new QMenu(menuBar);
        menuOptions_2->setObjectName(QString::fromUtf8("menuOptions_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuApplication->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuOptions_2->menuAction());
        menuApplication->addAction(actionAide);
        menuApplication->addAction(actionQuitter);
        menuEdition->addAction(actionAnnuler);
        menuEdition->addAction(actionRetablir);
        menuOptions->addAction(actionKeyboard);
        menuOptions->addAction(actionDialog_Windows);
        menuOptions_2->addAction(actionComplex_Mode);
        menuOptions_2->addAction(actionRadians);
        menuOptions_2->addAction(actionDegrees);

        retranslateUi(MainWindow);
        QObject::connect(actionQuitter, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculator in Reverse Polish notation by Tudor Luchiancenco & K\303\251vin Njo Ewele", 0, QApplication::UnicodeUTF8));
        actionAide->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        actionAide->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setText(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRetablir->setText(QApplication::translate("MainWindow", "Redo", 0, QApplication::UnicodeUTF8));
        actionRetablir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionKeyboard->setText(QApplication::translate("MainWindow", "Keyboard", 0, QApplication::UnicodeUTF8));
        actionDialog_Windows->setText(QApplication::translate("MainWindow", "Dialog Windows", 0, QApplication::UnicodeUTF8));
        actionParameters->setText(QApplication::translate("MainWindow", "Parameters", 0, QApplication::UnicodeUTF8));
        actionComplex_Mode->setText(QApplication::translate("MainWindow", "Complex Mode", 0, QApplication::UnicodeUTF8));
        actionRadians->setText(QApplication::translate("MainWindow", "Radians", 0, QApplication::UnicodeUTF8));
        actionDegrees->setText(QApplication::translate("MainWindow", "Degrees", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("MainWindow", "> ", 0, QApplication::UnicodeUTF8));
        butmod->setText(QApplication::translate("MainWindow", "Mod", 0, QApplication::UnicodeUTF8));
        butcube->setText(QApplication::translate("MainWindow", "Cube", 0, QApplication::UnicodeUTF8));
        buttanh->setText(QApplication::translate("MainWindow", "Tanh", 0, QApplication::UnicodeUTF8));
        butcos->setText(QApplication::translate("MainWindow", "Cos", 0, QApplication::UnicodeUTF8));
        butinv->setText(QApplication::translate("MainWindow", "Inv", 0, QApplication::UnicodeUTF8));
        butcosh->setText(QApplication::translate("MainWindow", "Cosh", 0, QApplication::UnicodeUTF8));
        buttan->setText(QApplication::translate("MainWindow", "Tan", 0, QApplication::UnicodeUTF8));
        butfact->setText(QApplication::translate("MainWindow", "Fact", 0, QApplication::UnicodeUTF8));
        butfact->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        butsin->setText(QApplication::translate("MainWindow", "Sin", 0, QApplication::UnicodeUTF8));
        butsinh->setText(QApplication::translate("MainWindow", "Sinh", 0, QApplication::UnicodeUTF8));
        butsqr->setText(QApplication::translate("MainWindow", "Sqr", 0, QApplication::UnicodeUTF8));
        butsqrt->setText(QApplication::translate("MainWindow", "Sqrt", 0, QApplication::UnicodeUTF8));
        butlog->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        butln->setText(QApplication::translate("MainWindow", "Ln", 0, QApplication::UnicodeUTF8));
        butpow->setText(QApplication::translate("MainWindow", "Pow", 0, QApplication::UnicodeUTF8));
        butsign->setText(QApplication::translate("MainWindow", "Sign", 0, QApplication::UnicodeUTF8));
        butdel->setText(QApplication::translate("MainWindow", "Delete line", 0, QApplication::UnicodeUTF8));
        butdel->setShortcut(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        butRandomCmd->setText(QApplication::translate("MainWindow", "Random cmd", 0, QApplication::UnicodeUTF8));
        butpoint->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        butpoint->setShortcut(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        butsoustraction->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        butsoustraction->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        but5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        but5->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        but1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        but1->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        but6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        but6->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        but7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        but7->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        but9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        but9->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        but8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        but8->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        but2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        but2->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        but3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        but3->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        but0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        but0->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        butCote->setText(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        butCote->setShortcut(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        butBackspace->setText(QApplication::translate("MainWindow", "BSpace", 0, QApplication::UnicodeUTF8));
        butBackspace->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        butdivision->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        butdivision->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        butespace->setText(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        butespace->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        butdollar->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        butdollar->setShortcut(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        butmultiplication->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        butmultiplication->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        butenter->setText(QApplication::translate("MainWindow", "ENTER", 0, QApplication::UnicodeUTF8));
        butenter->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        buteval->setText(QApplication::translate("MainWindow", "Evaluate", 0, QApplication::UnicodeUTF8));
        butaddition->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        butaddition->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        but4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        but4->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        butclear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        butclear->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        butdup->setText(QApplication::translate("MainWindow", "Dup", 0, QApplication::UnicodeUTF8));
        butdrop->setText(QApplication::translate("MainWindow", "Drop", 0, QApplication::UnicodeUTF8));
        butsum->setText(QApplication::translate("MainWindow", "Sum", 0, QApplication::UnicodeUTF8));
        butswap->setText(QApplication::translate("MainWindow", "Swap", 0, QApplication::UnicodeUTF8));
        butmean->setText(QApplication::translate("MainWindow", "Mean", 0, QApplication::UnicodeUTF8));
        messagesCalculette->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Operations on the stack", 0, QApplication::UnicodeUTF8));
        radioRadians->setText(QApplication::translate("MainWindow", "Radians", 0, QApplication::UnicodeUTF8));
        radioRadians->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        radioDegres->setText(QApplication::translate("MainWindow", "Degrees", 0, QApplication::UnicodeUTF8));
        radioDegres->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        checkBoxComplex->setText(QApplication::translate("MainWindow", "Complex Mode", 0, QApplication::UnicodeUTF8));
        checkBoxComplex->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        lastPile->setText(QString());
        menuApplication->setTitle(QApplication::translate("MainWindow", "Application", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Display", 0, QApplication::UnicodeUTF8));
        menuOptions_2->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
