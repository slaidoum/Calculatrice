/**
 * @file mainwindow.h
 * @brief Fichier header de la classe MainWindow
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iterator>
#include <QString>
#include <QList>
#include <QTextStream>
#include <QChar>

#include "Calculatrice.h"
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void show();

    void connections();

private:
    Ui::MainWindow *ui;
    Dialog *mDialog;

private slots:
        // 0 -> 9
        void but0Appuye();
        void but1Appuye();
        void but2Appuye();
        void but3Appuye();
        void but4Appuye();
        void but5Appuye();
        void but6Appuye();
        void but7Appuye();
        void but8Appuye();
        void but9Appuye();

        // dollar et espace
        void butDollarAppuye();
        void butEspaceAppuye();

        // cote
        void butCote();

        // point
        void butPointAppuye();

        // maj pile
        void miseAJourPile();

        // sauvegarde etat pile
        void sauvegarderEtatPile();

        // opérations + - * /
        void butAdditionAppuye();
        void butSoustractionAppuye();
        void butMultiplicationAppuye();
        void butDivisionAppuye();

        // mode Complex = qq boutons disable
        void checkModeComplex(bool);

        // RandomCmd
        void randomCmd();

        // enter & eval
        void butEnterAppuye();
        void butEvalAppuye();

        // delete
        void butDelAppuye();


        // Display : fenetre Dialog && keyboard
        void Dialog_Windows(bool);
        void Keyboard(bool);

        void decocherActionDialog();

        // Edition : actions Undo et Redo
        void annulerEtatPile();
        void retablirEtatPile();

        // Options : actions mode complex, radians, et degrees
        void activerModeComplexe(bool);
        void activerDegres(bool);
        void activerRadians(bool);

        // maths
        void butPowAppuye();
        void butModAppuye();
        void butSignAppuye();
        void butSinAppuye();
        void butCosAppuye();
        void butTanAppuye();
        void butSinhAppuye();
        void butCoshAppuye();
        void butTanhAppuye();
        void butLnAppuye();
        void butLogAppuye();
        void butInvAppuye();
        void butFactAppuye();
        void butSqrtAppuye();
        void butSqrAppuye();

        // pile
        void butCubeAppuye();
        void butSwapAppuye();
        void butClearAppuye();
        void butSumAppuye();
        void butMeanAppuye();
        void butDropAppuye();
        void butDupAppuye();

        // Messages de la calculatrice
        void MessageAlerte(const QString& mes);
        void MessageSucces(const QString& mes);

        // backspace
        void butBackspace();
};

    int randInt();

#endif // MAINWINDOW_H
