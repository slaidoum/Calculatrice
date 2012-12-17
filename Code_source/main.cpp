#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QTextStream>
#include <cstdio>
#include "Nombre.h"
#include "NonComplexe.h"
#include "Complexe.h"
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Calculatrice.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication ap(argc, argv);
    MainWindow w;
    w.show();

    // gérer le problème des accents
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    return ap.exec();
}
