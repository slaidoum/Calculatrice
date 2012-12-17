#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialog.h"
#include "ui_dialog.h"

#include "LogSystem.h"
#include "Pile.h"
#include "PileAffichage.h"
#include "BackUpPiles.h"

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"
#include "Expression.h"
#include "Operateur.h"

#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mDialog = new Dialog(this);

    // on établit les connections entre les boutons
    connections();

    // on charge les parametres (l'état de la pile + nombre élements à afficher)
    int nbEltsPile = Pile::getInstance().chargerDepuisFichier();

    // si on a réussi à charger le fichier et lire la valeur alors..;
    if (nbEltsPile != -1) {
        mDialog->ui->spinBox->setValue(nbEltsPile);
    } else { // parametre par défaut
         mDialog->ui->spinBox->setValue(99);
    }

    // on met à jour l'affichage de la pile
    miseAJourPile();

    // Initialisation BackUpPile => sauvegarde état pile initiale
    this->sauvegarderEtatPile();

    // ajout log dans le fichier de log
    LogSystem::add("Ouverture de la calculatrice",FAIBLE);
}

MainWindow::~MainWindow()
{
    // ajout log dans le fichier de log
    LogSystem::add("Fermeture de la calculatrice",FAIBLE);
    delete ui;
}
void MainWindow::show()
{
    mDialog->show();
    QWidget::show();
}


// connection
void MainWindow::connections() {
    // bouttons 0 -> 9
    connect(ui->but0, SIGNAL(clicked()), this, SLOT(but0Appuye()));
    connect(ui->but1, SIGNAL(clicked()), this, SLOT(but1Appuye()));
    connect(ui->but2, SIGNAL(clicked()), this, SLOT(but2Appuye()));
    connect(ui->but3, SIGNAL(clicked()), this, SLOT(but3Appuye()));
    connect(ui->but4, SIGNAL(clicked()), this, SLOT(but4Appuye()));
    connect(ui->but5, SIGNAL(clicked()), this, SLOT(but5Appuye()));
    connect(ui->but6, SIGNAL(clicked()), this, SLOT(but6Appuye()));
    connect(ui->but7, SIGNAL(clicked()), this, SLOT(but7Appuye()));
    connect(ui->but8, SIGNAL(clicked()), this, SLOT(but8Appuye()));
    connect(ui->but9, SIGNAL(clicked()), this, SLOT(but9Appuye()));

    // dollar
    connect(ui->butdollar, SIGNAL(clicked()), this, SLOT(butDollarAppuye()));

    // espace
    connect(ui->butespace, SIGNAL(clicked()), this, SLOT(butEspaceAppuye()));

    // virgule
    connect(ui->butpoint, SIGNAL(clicked()), this, SLOT(butPointAppuye()));

    // opérations
    connect(ui->butaddition, SIGNAL(clicked()), this, SLOT(butAdditionAppuye()));
    connect(ui->butsoustraction, SIGNAL(clicked()), this, SLOT(butSoustractionAppuye()));
    connect(ui->butmultiplication, SIGNAL(clicked()), this, SLOT(butMultiplicationAppuye()));
    connect(ui->butdivision, SIGNAL(clicked()), this, SLOT(butDivisionAppuye()));

    // enter et eval
    connect(ui->butenter, SIGNAL(clicked()), this, SLOT(butEnterAppuye()));
    connect(ui->buteval, SIGNAL(clicked()), this, SLOT(butEvalAppuye()));

    // delete
    connect(ui->butdel, SIGNAL(clicked()), this, SLOT(butDelAppuye()));

    // maths
    connect(ui->butpow, SIGNAL(clicked()), this, SLOT(butPowAppuye()));
    connect(ui->butmod, SIGNAL(clicked()), this, SLOT(butModAppuye()));
    connect(ui->butsign, SIGNAL(clicked()), this, SLOT(butSignAppuye()));
    connect(ui->butsin, SIGNAL(clicked()), this, SLOT(butSinAppuye()));
    connect(ui->butcos, SIGNAL(clicked()), this, SLOT(butCosAppuye()));
    connect(ui->buttan, SIGNAL(clicked()), this, SLOT(butTanAppuye()));
    connect(ui->butsinh, SIGNAL(clicked()), this, SLOT(butSinhAppuye()));
    connect(ui->butcosh, SIGNAL(clicked()), this, SLOT(butCoshAppuye()));
    connect(ui->buttanh, SIGNAL(clicked()), this, SLOT(butTanhAppuye()));
    connect(ui->butln, SIGNAL(clicked()), this, SLOT(butLnAppuye()));
    connect(ui->butlog, SIGNAL(clicked()), this, SLOT(butLogAppuye()));
    connect(ui->butinv, SIGNAL(clicked()), this, SLOT(butInvAppuye()));
    connect(ui->butfact, SIGNAL(clicked()), this, SLOT(butFactAppuye()));
    connect(ui->butsqr, SIGNAL(clicked()), this, SLOT(butSqrAppuye()));
    connect(ui->butsqrt, SIGNAL(clicked()), this, SLOT(butSqrtAppuye()));
    connect(ui->butcube, SIGNAL(clicked()), this, SLOT(butCubeAppuye()));

    // checkbox mode complex = annuler qq boutons
    connect(ui->checkBoxComplex, SIGNAL(clicked(bool)), this, SLOT(checkModeComplex(bool)));

    // boutton random CMD
    connect(ui->butRandomCmd, SIGNAL(clicked()), this, SLOT(randomCmd()));

    // boutton backspace
    connect(ui->butBackspace, SIGNAL(clicked()), this, SLOT(butBackspace()));

    // Display : actionDialog_Windows et actionKeyboard
    connect(ui->actionDialog_Windows, SIGNAL(triggered(bool)), this, SLOT(Dialog_Windows(bool)));
    connect(ui->actionKeyboard, SIGNAL(triggered(bool)), this, SLOT(Keyboard(bool)));

    // Pour decocherActionDialog
    connect(mDialog->ui->butDQuit,SIGNAL(clicked()),this,SLOT(decocherActionDialog()));

    // Edition : actions Undo et Redo
    connect(ui->actionAnnuler, SIGNAL(triggered()), this, SLOT(annulerEtatPile()));
    connect(ui->actionRetablir, SIGNAL(triggered()), this, SLOT(retablirEtatPile()));

    // Options : actions mode complex, radians, et degrees
    connect(ui->actionComplex_Mode, SIGNAL(triggered(bool)), this, SLOT(activerModeComplexe(bool)));
    connect(ui->actionDegrees, SIGNAL(triggered(bool)), this, SLOT(activerDegres(bool)));
    connect(ui->actionRadians, SIGNAL(triggered(bool)), this, SLOT(activerRadians(bool)));

    // pile
    connect(ui->butswap, SIGNAL(clicked()), this, SLOT(butSwapAppuye()));
    connect(ui->butsum, SIGNAL(clicked()), this, SLOT(butSumAppuye()));
    connect(ui->butmean, SIGNAL(clicked()), this, SLOT(butMeanAppuye()));
    connect(ui->butclear, SIGNAL(clicked()), this, SLOT(butClearAppuye()));
    connect(ui->butdrop, SIGNAL(clicked()), this, SLOT(butDropAppuye()));
    connect(ui->butdup, SIGNAL(clicked()), this, SLOT(butDupAppuye()));
    connect(ui->butCote, SIGNAL(clicked()), this, SLOT(butCote()));

}

/* LES SLOTS */
// 0->9
void MainWindow::but0Appuye() {
    if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ))) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"0");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" 0");
        }
    } else if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() >= '0') && (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() <= '9' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '.' ) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '$' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '/' )))) {
        ui->lineEdit->setText(ui->lineEdit->text()+"0");
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" 0");
    }
}

void MainWindow::but1Appuye(){
    if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ))) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"1");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" 1");
        }
    } else if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() >= '0') && (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() <= '9' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '.' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '$' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '/' ))) {
        ui->lineEdit->setText(ui->lineEdit->text()+"1");
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" 1");
    }
}

void MainWindow::but2Appuye(){
    if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ))) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"2");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" 2");
        }
    } else if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() >= '0') && (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() <= '9' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '.' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '$' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '/' ))) {
        ui->lineEdit->setText(ui->lineEdit->text()+"2");
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" 2");
    }
}

void MainWindow::but3Appuye(){
    if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ))) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"3");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" 3");
        }
    } else if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() >= '0') && (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() <= '9' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '.' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '$' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '/' ))) {
        ui->lineEdit->setText(ui->lineEdit->text()+"3");
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" 3");
    }
}

void MainWindow::but4Appuye(){
    if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ))) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"4");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" 4");
        }
    } else if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() >= '0') && (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() <= '9' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '.' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '$' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '/' ))) {
        ui->lineEdit->setText(ui->lineEdit->text()+"4");
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" 4");
    }
}

void MainWindow::but5Appuye(){
    if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ))) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"5");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" 5");
        }
    } else if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() >= '0') && (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() <= '9' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '.' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '$' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '/' ))) {
        ui->lineEdit->setText(ui->lineEdit->text()+"5");
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" 5");
    }
}

void MainWindow::but6Appuye(){
    if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ))) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"6");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" 6");
        }
    } else if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() >= '0') && (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() <= '9' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '.' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '$' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '/' ))) {
        ui->lineEdit->setText(ui->lineEdit->text()+"6");
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" 6");
    }
}

void MainWindow::but7Appuye(){
    if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ))) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"7");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" 7");
        }
    } else if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() >= '0') && (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() <= '9' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '.' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '$' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '/' ))) {
        ui->lineEdit->setText(ui->lineEdit->text()+"7");
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" 7");
    }
}

void MainWindow::but8Appuye(){
    if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ))) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"8");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" 8");
        }
    } else if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() >= '0') && (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() <= '9' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '.' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '$' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '/' ))) {
        ui->lineEdit->setText(ui->lineEdit->text()+"8");
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" 8");
    }
}

void MainWindow::but9Appuye(){
    if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ))) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"9");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" 9");
        }
    } else if (((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() >= '0') && (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() <= '9' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) || ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '.' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '$' ))|| ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '/' ))) {
        ui->lineEdit->setText(ui->lineEdit->text()+"9");
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" 9");
    }
}

// dollar
void MainWindow::butDollarAppuye(){ ui->lineEdit->setText(ui->lineEdit->text()+"$"); }
// espace
void MainWindow::butEspaceAppuye(){ ui->lineEdit->setText(ui->lineEdit->text()+" "); }
// cote
void MainWindow::butCote() {
    // on compte les cotes simples
    int nbCotes = 0;
     QTextStream cout(stdout, QIODevice::WriteOnly);
    for (int i = 0; i < ui->lineEdit->text().length(); i++) {
        if (ui->lineEdit->text().at(i) == '\'') {
            nbCotes++;
        }
    }
    cout << nbCotes << endl;
    if (nbCotes%2 != 0 || (nbCotes == 0 && ui->lineEdit->text().isEmpty())) {
        ui->lineEdit->setText(ui->lineEdit->text()+"'");
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" '");
    }
}

//checkModeComplex
void MainWindow::checkModeComplex(bool change) {
    if (change == true) {
        ui->butinv->setEnabled(false);
        ui->butlog->setEnabled(false);
        ui->butsqrt->setEnabled(false);
        ui->butln->setEnabled(false);
        ui->buttanh->setEnabled(false);
        ui->butcosh->setEnabled(false);
        ui->butsinh->setEnabled(false);
        ui->buttan->setEnabled(false);
        ui->butcos->setEnabled(false);
        ui->butsin->setEnabled(false);
        ui->buttan->setEnabled(false);
        ui->butfact->setEnabled(false);
        ui->butmod->setEnabled(false);
        ui->butpow->setEnabled(false);
    } else {
        ui->butinv->setEnabled(true);
        ui->butlog->setEnabled(true);
        ui->butsqrt->setEnabled(true);
        ui->butln->setEnabled(true);
        ui->buttanh->setEnabled(true);
        ui->butcosh->setEnabled(true);
        ui->butsinh->setEnabled(true);
        ui->buttan->setEnabled(true);
        ui->butcos->setEnabled(true);
        ui->butsin->setEnabled(true);
        ui->buttan->setEnabled(true);
        ui->butfact->setEnabled(true);
        ui->butmod->setEnabled(true);
        ui->butpow->setEnabled(true);
    }
}

int randInt(int low, int high) {
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}

// random CMD
void MainWindow::randomCmd() {
    QVector<QString> *tab = NULL;
    tab = new QVector<QString>;

    // non complexes
    tab->push_back("2 3 +");
    tab->push_back("9 14 + 2 4 +");
    tab->push_back("'2 3 +' '15 9 -'");
    tab->push_back("'12/5 11 -'");
    tab->push_back("'22.5 33/9 +'");

    tab->push_back("2 3.51 +");
    tab->push_back("22 23 12 + + 2 4 + 88 78 - * +");
    tab->push_back("'2 3 +' '1 2 +'");
    tab->push_back("'12/5 11 -' 4 +");
    tab->push_back("'22.5 33/9 +'");

    // complexes
    tab->push_back("2$6 3 +");
    tab->push_back("9$5 14 + 2 4 +");
    tab->push_back("'2$2 3$9 +'");
    tab->push_back("'12/5$99 11$12.23 -'");
    tab->push_back("'22.5$0 33/9$3 +'");

    tab->push_back("15$5 3$2 +");
    tab->push_back("9 2 + 2$2.3 4 +");
    tab->push_back("'2$2 3$3.1 +'");
    tab->push_back("'12/5$74 11$12 -' '52$21 96$78 +'");
    tab->push_back("'12/5$74 11$12 -' '52$21 96$78 +' + '1 2 +' '5 3 +' + +");

    if (ui->checkBoxComplex->isChecked() == false) {
        ui->lineEdit->setText("> " + tab->at(randInt(0,9)));
    } else {
        ui->lineEdit->setText("> " + tab->at(randInt(10,19)));
    }
}

// virgule
void MainWindow::butPointAppuye(){ ui->lineEdit->setText(ui->lineEdit->text()+"."); }
// opérations
void MainWindow::butAdditionAppuye(){ ui->lineEdit->setText(ui->lineEdit->text()+" +"); }
void MainWindow::butSoustractionAppuye(){ ui->lineEdit->setText(ui->lineEdit->text()+" -"); }
void MainWindow::butMultiplicationAppuye(){ ui->lineEdit->setText(ui->lineEdit->text()+" *"); }
void MainWindow::butDivisionAppuye(){ ui->lineEdit->setText(ui->lineEdit->text()+"/"); }

// met à jour la pile (niveau affichage)
void MainWindow::miseAJourPile() {

    QStack<Constante*>::iterator it;
    Constante* c = 0;

    // met à jour l'affichage de la vraie pile
    // pour finir, on écrit le dernier élément de la pile dans le label dédié au résultat.
    mDialog->ui->pile->clear();
    int i = 0;
    it = Pile::getInstance().end();
    while (it!=Pile::getInstance().begin()) {
        --it;
        c = *it;
        i++;
        // on ajoute X élements
        if (mDialog->ui->spinBox->value() >= i) {
            mDialog->ui->pile->addItem(c->toString());
        }
    }


    // on n'oublie pas de sauvegarder la nouvelle valeur de la spin et la pile dans le fichier
    Pile::getInstance().sauvegarderDansFichier(mDialog->ui->spinBox->value());

    // met à jour la pile d'affichage aussi (niveau affichage)
    mDialog->ui->history->clear();
    QStack<QString>::iterator it2;
    QString s = "";
    it2 = PileAffichage::getInstance().end();
    while (it2!=PileAffichage::getInstance().begin()) {
        --it2;
        s = *it2;
        mDialog->ui->history->addItem(s);
    }


    // pour finir, on écrit le dernier élément de la pile dans le label dédié au résultat.
    if (Pile::getInstance().size() > 0) { // si la pile contient au moins un élément
        it = Pile::getInstance().end();
        --it;
        c = *it;
        ui->lastPile->setText(c->toString());
    } else {
        ui->lastPile->setText("");
    }

}

// enter et eval
void MainWindow::butEnterAppuye() {

    QTextStream cout(stdout, QIODevice::WriteOnly);

    QString texte = ui->lineEdit->text();

    // on supprime les espaces et '>' du début de la commande
    texte.replace(QRegExp("^>?[ ]+"),"");
     // on supprime les espaces de la fin de la commande
    texte.replace(QRegExp("[ ]+$"),"");
    // si on trouve deux espaces ou plus, on le transforme dans un espace
    texte.replace(QRegExp("(\\s){2,}")," ");
    // on traite le problème des simples cotes entourant une expression
    int nbCotes = 0;
    for (int i = 0; i < texte.length(); i++) {
        if (texte.at(i) == '\'') {
            nbCotes++;
            // si cote impair ou on est sur la première cote, et il y a un espace à la suite, on le supprime
            if ((nbCotes%2 != 0 || nbCotes == 0) && (texte.at(i+1) == ' ')) {
                texte = texte.remove(i+1,1);
            } else if ((nbCotes%2 == 0 && (texte.at(i-1) == ' '))) {
                texte = texte.remove(i-1,1);
            }
        }
    }

    // Enter et commande vide => On duplique le premier élément de la pile
    if (texte.isEmpty()) {
        Pile& p = Pile::getInstance();
        try {
            p.dup();
            miseAJourPile();
        } catch (CalculatriceException e) {
             QMessageBox::critical(0,"Erreur !",e.getMessage());
             // ajout log dans le fichier de log
             LogSystem::add(e.getMessage(),MOYENNE);
        }
    } else {
        cout << endl << "Commande : |" << texte << "|" << endl;

        // on recupère une instance de Calculatrice
        Calculatrice& calculatrice = Calculatrice::getInstance();

        QString expression = "'"; // sert à construire notre expression
        QString constanteATraiter = ""; // constante en cours d'examination
        bool exp = false; // dit si on est en train de traiter une expression ou pas


        // Tout d'abord on teste si le nombre de cotes simples dans la comande est paire, sinon erreur !
        // on compte les cotes simples
        nbCotes = 0;
        for (int i = 0; i < texte.length(); i++) {
            if (texte.at(i) == '\'') {
                nbCotes++;
            }
        }

        // nombre cotes paire, on peut examiner la commande
        if (nbCotes%2 == 0) {

            // on remet l'expression au bon format dans la qlinedit
            ui->lineEdit->setText("> " + texte);
            //ui->lineEdit->setText(ui->lineEdit->text() + texte);

            // on construits des constantes et opérateurs à partir de la commande entrée, en enlevant les espaces
            QStringList listeConst = texte.split(" ");
            QStringList::iterator it;
            // on boucle sur chacun des élements de la commande
            for (it = listeConst.begin(); it != listeConst.end(); ++it) {
                constanteATraiter = QString(*it); // on recupère sour forme de chaine de caractères
                cout << "En cours : |" << constanteATraiter << "|"<< endl;


                /* Traitement expression */
                // cas particuler expression : '+' , '8'
                if (constanteATraiter.startsWith("'") && constanteATraiter.endsWith("'") && exp == false) {
                    constanteATraiter = constanteATraiter.remove(0,1); // on enlève le ' du début
                    constanteATraiter = constanteATraiter.remove(constanteATraiter.length()-1,1); // on enlève le ' de la fin
                    // si il s'agit d'un opérateur ou d'une constante
                    if (calculatrice.isOperateur(constanteATraiter) || calculatrice.isConstante(constanteATraiter)) {
                        // si pas de mode Complex et que la constante c'est un complex
                        if (ui->checkBoxComplex->isChecked() == false && calculatrice.isComplexe(constanteATraiter)) {
                            MessageAlerte("Vous avez entré des nombres complexes alors que ce mode n'est pas activé !");
                            cout << "erreur : complex & complex non actif";
                            break;
                        // si on travaille en mode Complex et qu'on doit traiter une constante
                        } else if (ui->checkBoxComplex->isChecked() == true && !calculatrice.isComplexe(constanteATraiter) && calculatrice.isConstante(constanteATraiter)) {
                            // si pas de '$' dans la constante, alors on l'ajoute
                            constanteATraiter.append("$0");
                        }
                        expression.append(constanteATraiter);
                        expression.append("'");
                        cout << "Expression Finale :" << expression << endl;

                        // on fabrique l'expression
                        calculatrice.fabriquer(expression,EXPRESSION);
                        // on met à jour l'affichage de la pile
                        miseAJourPile();

                        // APRES TOUTE FABRICATION, ON SAUVEGARDE ETAT PILE
                        this->sauvegarderEtatPile();

                        expression = "'";
                        exp = false;
                        MessageSucces("Commande examinée avec succès.");

                    } else { // erreur, objet inconnu
                        if (constanteATraiter.length() > 19) {
                            constanteATraiter.remove(15,constanteATraiter.length()-1);
                            constanteATraiter.append("...");
                        }
                        MessageAlerte("L'objet '"+ constanteATraiter +"' de votre commande est inconnu ! ");
                        // ajout log dans le fichier de log
                        LogSystem::add("L'objet '"+ constanteATraiter +"' de votre commande est inconnu ! ",MOYENNE);
                        cout << "erreur : objet inconnu";
                        break;
                    }

                } else if (constanteATraiter.startsWith("'") && exp == false) {
                    // début expression
                    exp = true; // désormais on traite une expression
                    constanteATraiter = constanteATraiter.remove(0,1); // on enlève le ' du début
                    // si il s'agit d'un opérateur ou d'une constante
                    if (calculatrice.isOperateur(constanteATraiter) || calculatrice.isConstante(constanteATraiter)) {
                        // si pas de mode Complex et que la constante c'est un complex
                        if (ui->checkBoxComplex->isChecked() == false && calculatrice.isComplexe(constanteATraiter)) {
                            MessageAlerte("Vous avez entré des nombres complexes alors que ce mode n'est pas activé !");
                            // ajout log dans le fichier de log
                            LogSystem::add("Vous avez entré des nombres complexes alors que ce mode n'est pas activé !",MOYENNE);
                            cout << "erreur : complex & complex non actif";
                            break; // si on travaille en mode Complex et qu'on doit traiter une constante
                        } else if (ui->checkBoxComplex->isChecked() == true && !calculatrice.isComplexe(constanteATraiter) && calculatrice.isConstante(constanteATraiter)) {
                            // si pas de '$' dans la constante, alors on l'ajoute
                            constanteATraiter.append("$0");
                        }
                        expression.append(constanteATraiter);
                    } else { // erreur, objet inconnu
                        if (constanteATraiter.length() > 19) {
                            constanteATraiter.remove(15,constanteATraiter.length()-1);
                            constanteATraiter.append("...");
                        }
                        MessageAlerte("L'objet '"+ constanteATraiter +"' de votre commande est inconnu ! ");
                        // ajout log dans le fichier de log
                        LogSystem::add("L'objet '"+ constanteATraiter +"' de votre commande est inconnu ! ",MOYENNE);
                        cout << "erreur : objet inconnu";
                        break;
                    }
                // milieu d'expression
                } else if (!constanteATraiter.endsWith("'") && exp == true) {
                    // si il s'agit d'un opérateur ou d'une constante
                    if (calculatrice.isOperateur(constanteATraiter) || calculatrice.isConstante(constanteATraiter)) {
                        // si pas de mode Complex et que la constante c'est un complex
                        if (ui->checkBoxComplex->isChecked() == false && calculatrice.isComplexe(constanteATraiter)) {
                            MessageAlerte("Vous avez entré des nombres complexes alors que ce mode n'est pas activé !");
                            // ajout log dans le fichier de log
                            LogSystem::add("Vous avez entré des nombres complexes alors que ce mode n'est pas activé ! ",MOYENNE);
                            cout << "erreur : complex & complex non actif";
                            break; // si on travaille en mode Complex et qu'on doit traiter une constante
                        } else if (ui->checkBoxComplex->isChecked() == true && !calculatrice.isComplexe(constanteATraiter) && calculatrice.isConstante(constanteATraiter)) {
                            // si pas de '$' dans la constante, alors on l'ajoute
                            constanteATraiter.append("$0");
                        }
                        expression.append(" ");
                        expression.append(constanteATraiter);
                    } else {
                        if (constanteATraiter.length() > 19) {
                            constanteATraiter.remove(15,constanteATraiter.length()-1);
                            constanteATraiter.append("...");
                        }
                        MessageAlerte("L'objet '"+ constanteATraiter +"' de votre commande est inconnu ! ");
                        // ajout log dans le fichier de log
                        LogSystem::add("L'objet '"+ constanteATraiter +"' de votre commande est inconnu !  ",MOYENNE);
                        cout << "erreur : objet inconnu";
                        break;
                    }
                // fin d'expression
                } else if (constanteATraiter.endsWith("'") && exp == true) {
                    constanteATraiter = constanteATraiter.remove(constanteATraiter.length()-1,1); // on enlève le ' de la fin
                    // si il s'agit d'un opérateur ou d'une constante
                    if (calculatrice.isOperateur(constanteATraiter) || calculatrice.isConstante(constanteATraiter)) {
                        // si pas de mode Complex et que la constante c'est un complex
                        if (ui->checkBoxComplex->isChecked() == false && calculatrice.isComplexe(constanteATraiter)) {
                            MessageAlerte("Vous avez entré des nombres complexes alors que ce mode n'est pas activé !");
                            cout << "erreur : complex & complex non actif";
                            break;
                        // si on travaille en mode Complex et qu'on doit traiter une constante
                        } else if (ui->checkBoxComplex->isChecked() == true && !calculatrice.isComplexe(constanteATraiter) && calculatrice.isConstante(constanteATraiter)) {
                            // si pas de '$' dans la constante, alors on l'ajoute
                            constanteATraiter.append("$0");
                        }
                        expression.append(" ");
                        expression.append(constanteATraiter);
                        expression.append("'");
                        cout << "Expression Finale :" << expression << endl;

                        // on fabrique l'expression
                        calculatrice.fabriquer(expression,EXPRESSION);

                        // on met à jour l'affichage de la pile
                        miseAJourPile();

                        // APRES TOUTE FABRICATION, ON SAUVEGARDE ETAT PILE
                        this->sauvegarderEtatPile();

                        expression = "'";
                        exp = false;
                        MessageSucces("Commande examinée avec succès.");
                    } else { // erreur, objet inconnu
                        if (constanteATraiter.length() > 19) {
                            constanteATraiter.remove(15,constanteATraiter.length()-1);
                            constanteATraiter.append("...");
                        }
                        MessageAlerte("L'objet '"+ constanteATraiter +"' de votre commande est inconnu ! ");
                        // ajout log dans le fichier de log
                        LogSystem::add("L'objet '"+ constanteATraiter +"' de votre commande est inconnu !  ",MOYENNE);
                        cout << "erreur : objet inconnu";
                        break;
                    }
                // constante ou opérateur
                } else if (calculatrice.isOperateur(constanteATraiter) || calculatrice.isConstante(constanteATraiter)) {
                    // si c'est une constante
                    if (calculatrice.isConstante(constanteATraiter)) {
                        // si pas de mode Complex et que la constante c'est un complex
                        if (ui->checkBoxComplex->isChecked() == false && calculatrice.isComplexe(constanteATraiter)) {
                            MessageAlerte("Vous avez entré des nombres complexes alors que ce mode n'est pas activé !");
                            // ajout log dans le fichier de log
                            LogSystem::add("Vous avez entré des nombres complexes alors que ce mode n'est pas activé !  ",MOYENNE);
                            cout << "erreur : complex & complex non actif";
                            break;
                        } else if (ui->checkBoxComplex->isChecked() == true && !calculatrice.isComplexe(constanteATraiter) && calculatrice.isConstante(constanteATraiter)) {
                            // si mode Complex active et la constante n'est pas un complex, ajouter '$'
                            constanteATraiter.append("$0");
                        }
                        cout << "Element is constante :";
                        cout << constanteATraiter << endl;
                        MessageSucces("Commande examinée avec succès.");

                        // on fabrique la constante
                        if (calculatrice.isComplexe(constanteATraiter)) {
                            cout << "... est c'est un Complexe !" << endl;
                            calculatrice.fabriquer(constanteATraiter,COMPLEXE);
                        } else if (calculatrice.isEntier(constanteATraiter)) {
                            cout << "... est c'est un Entier !" << endl;
                            calculatrice.fabriquer(constanteATraiter,ENTIER);
                        } else if (calculatrice.isReel(constanteATraiter)) {
                            cout << "... est c'est un Reel !" << endl;
                            calculatrice.fabriquer(constanteATraiter,REEL);
                        } else if (calculatrice.isRationnel(constanteATraiter)) {
                            cout << "... est c'est un Rationnel !" << endl;
                            calculatrice.fabriquer(constanteATraiter,RATIONNEL);
                        }

                        // on met à jour l'affichage de la pile
                        miseAJourPile();

                        // APRES TOUTE FABRICATION, ON SAUVEGARDE ETAT PILE
                        this->sauvegarderEtatPile();

                    // si c'est un opérateur
                    } else if (calculatrice.isOperateur(constanteATraiter)) {
                        cout << "Element is operateur :";
                        cout << constanteATraiter << endl;
                        MessageSucces("Commande examinée avec succès.");

                        // on fabrique l'opérateur (on le traite aussi)
                        calculatrice.fabriquer(constanteATraiter,OPERATEUR);

                        // on met à jour l'affichage de la pile
                        miseAJourPile();

                        // APRES TOUTE FABRICATION, ON SAUVEGARDE ETAT PILE
                        this->sauvegarderEtatPile();

                    }
                // objet inconnu, erreur
                } else {
                    if (constanteATraiter.length() > 13) {
                        constanteATraiter.remove(9,constanteATraiter.length()-1);
                        constanteATraiter.append("...");
                    }
                    MessageAlerte("L'objet '"+ constanteATraiter +"' de votre commande est inconnu ! ");
                    // ajout log dans le fichier de log
                    LogSystem::add("L'objet '"+ constanteATraiter +"' de votre commande est inconnu !   ",MOYENNE);
                    cout << "erreur : objet inconnu";
                    break;
                }
            }
            // nombre cotes impair = erreur dans la commande
        } else {
            MessageAlerte("Vérifiez à nouveau votre commande (problèmes au niveau des simples côtes) ! ");
            // ajout log dans le fichier de log
            LogSystem::add("Vérifiez à nouveau votre commande (problèmes au niveau des simples côtes) ! ",MOYENNE);
            cout << "erreur : cotes impaire";
        }
        cout << "(Nb Cotes = " << nbCotes << ")" << endl;
    }
}

// eval
void MainWindow::butEvalAppuye() {
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Eval");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Eval");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Eval");
    }
}
// delete
void MainWindow::butDelAppuye(){ ui->lineEdit->setText("> "); }


// Backspace
void MainWindow::butBackspace() {
    // ne pas effacer les '> '
    if ((ui->lineEdit->text().length() < 3 && ui->lineEdit->text().at(0) == '>' && ui->lineEdit->text().at(1) == ' ') || (ui->lineEdit->text().isEmpty())) {
        Pile& p = Pile::getInstance();
        try {
            p.drop();
            miseAJourPile();
        } catch (CalculatriceException e) {
             QMessageBox::critical(0,"Erreur !",e.getMessage());
             // ajout log dans le fichier de log
             LogSystem::add(e.getMessage(),MOYENNE);
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text().remove(ui->lineEdit->text().length()-1,1));
    }   
}

// maths
void MainWindow::butPowAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Pow");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Pow");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Pow");
    }
}
void MainWindow::butModAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Mod");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Mod");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Mod");
    }
}
void MainWindow::butSignAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Sign");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Sign");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Sign");
    }
}
void MainWindow::butSinAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Sin");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Sin");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Sin");
    }
}

void MainWindow::butCosAppuye() {
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Cos");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Cos");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Cos");
    }
}

void MainWindow::butTanAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Tan");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Tan");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Tan");
    }
}
void MainWindow::butSinhAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Sinh");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Sinh");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Sinh");
    }
}
void MainWindow::butCoshAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Cosh");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Cosh");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Cosh");
    }
}
void MainWindow::butTanhAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Tanh");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Tanh");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Tanh");
    }
}
void MainWindow::butLnAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Ln");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Ln");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Ln");
    }
}

void MainWindow::butLogAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Log");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Log");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Log");
    }
}

void MainWindow::butInvAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Inv");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Inv");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Inv");
    }
}

void MainWindow::butFactAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Fact");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Fact");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Fact");
    }
}

void MainWindow::butSqrtAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Sqrt");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Sqrt");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Sqrt");
    }
}
void MainWindow::butSqrAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Sqr");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Sqr");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Sqr");
    }
}
void MainWindow::butCubeAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Cube");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Cube");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Cube");
    }
}

void MainWindow::butSwapAppuye() {
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Swap");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Swap");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Swap");
    }


}
void MainWindow::butSumAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Sum");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Sum");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Sum");
    }
}
void MainWindow::butMeanAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Mean");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Mean");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Mean");
    }
}
void MainWindow::butClearAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Clear");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Clear");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Clear");
    }
}
void MainWindow::butDropAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Drop");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Drop");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Drop");
    }
}
void MainWindow::butDupAppuye(){
    if ((ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == '\'' ) || (ui->lineEdit->text().at(ui->lineEdit->text().length()-1).toLatin1() == ' ' )) {
        // on compte les cotes simples
        int nbCotes = 0;
         QTextStream cout(stdout, QIODevice::WriteOnly);
        for (int i = 0; i < ui->lineEdit->text().length(); i++) {
            if (ui->lineEdit->text().at(i) == '\'') {
                nbCotes++;
            }
        }
        cout << nbCotes << endl;
        if (nbCotes%2 != 0 || nbCotes == 0) {
            ui->lineEdit->setText(ui->lineEdit->text()+"Dup");
        } else {
            ui->lineEdit->setText(ui->lineEdit->text()+" Dup");
        }
    } else {
        ui->lineEdit->setText(ui->lineEdit->text()+" Dup");
    }
}

// message d'alerte
void MainWindow::MessageAlerte(const QString& mes) {
    QPalette palette = ui->messagesCalculette->palette();
    palette.setColor(ui->messagesCalculette->foregroundRole(), QColor(220, 110, 70));
    ui->messagesCalculette->setPalette(palette);
    ui->messagesCalculette->setText(QString::fromUtf8(mes.toStdString().c_str()));
}

// message de succès
void MainWindow::MessageSucces(const QString& mes) {
    QPalette palette = ui->messagesCalculette->palette();
    palette.setColor(ui->messagesCalculette->foregroundRole(), QColor(160, 204, 40));
    ui->messagesCalculette->setPalette(palette);
    ui->messagesCalculette->setText(QString::fromUtf8(mes.toStdString().c_str()));
}

// keyboard
void MainWindow::Keyboard(bool change) {
    if (change == false) {
        this->setFixedHeight(195);
    } else {
        this->setFixedHeight(420);
    }
}

// Dialog
void MainWindow::Dialog_Windows(bool change) {
    if (change == true) {
        this->mDialog->setHidden(false);
    } else {
        this->mDialog->setHidden(true);
    }
}

// actions Undo et Redo

// undo
void MainWindow::annulerEtatPile() {
    try {
        BackUpPiles* liste = BackUpPiles::getInstance();
        // on charge une nouvelle pile (celle sauvegardée)
        Pile::getInstance().chargerUnePile(liste->getDernierePile());
        miseAJourPile();
    } catch (CalculatriceException& e) {
        QMessageBox::critical(0,"Erreur !",e.getMessage());
        // ajout log dans le fichier de log
        LogSystem::add(e.getMessage(),MOYENNE);
    }
}

// redo
void MainWindow::retablirEtatPile() {
    try {
        BackUpPiles* liste = BackUpPiles::getInstance();
        // on charge une nouvelle pile (celle sauvegardée)
        Pile::getInstance().chargerUnePile(liste->getPileSuivante());
        miseAJourPile();
    } catch (CalculatriceException& e) {
        QMessageBox::critical(0,"Erreur !",e.getMessage());
        // ajout log dans le fichier de log
        LogSystem::add(e.getMessage(),MOYENNE);
    }
}

// sauvegarde l'état de la pile courante, dans la liste des piles
void MainWindow::sauvegarderEtatPile() {
    BackUpPiles* liste = BackUpPiles::getInstance();
    liste->ajouterNouvellePile(Pile::getInstance().sauvegarderPileCourante());
}

void MainWindow::decocherActionDialog() {
    ui->actionDialog_Windows->setChecked(false);
}

// Options : actions mode complex, radians, et degrees
void MainWindow::activerModeComplexe(bool b) {
    if (b == true) {
        ui->checkBoxComplex->setChecked(true);
    } else {
        ui->checkBoxComplex->setChecked(false);
    }
}

void MainWindow::activerDegres(bool b) {
    if (b == true) {
        ui->radioDegres->setChecked(true);
        ui->radioRadians->setChecked(false);
        ui->actionRadians->setChecked(false);
    } else {
        ui->radioDegres->setChecked(false);
        ui->radioRadians->setChecked(true);
        ui->actionRadians->setChecked(true);
    }
}

void MainWindow::activerRadians(bool b) {
    if (b == true) {
        ui->radioRadians->setChecked(true);
        ui->radioDegres->setChecked(false);
        ui->actionDegrees->setChecked(false);
    } else {
        ui->radioRadians->setChecked(false);
        ui->radioDegres->setChecked(true);
        ui->actionDegrees->setChecked(true);
    }
}
