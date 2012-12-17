#include "dialog.h"
#include "ui_dialog.h"

#include "Pile.h"
#include "PileAffichage.h"

#include "LogSystem.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->spinBox->setValue(99);
    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(nbElsPile()));
    connect(ui->butCleanHistory,SIGNAL(clicked()),this,SLOT(clearHistory()));

    // ajout log dans le fichier de log
    LogSystem::add("Ouverture de la fenetre de Dialog",FAIBLE);
}

Dialog::~Dialog()
{
    // ajout log dans le fichier de log
    LogSystem::add("Fermeture de la fenetre de Dialog",FAIBLE);
    delete ui;
}

void Dialog::nbElsPile() {

    // met à jour l'affichage de la vraie pile
    // pour finir, on écrit le dernier élément de la pile dans le label dédié au résultat.
    ui->pile->clear();
    QStack<Constante*>::iterator it;
    Constante* c = 0;
    int i = 0;
    it = Pile::getInstance().end();
    while (it!=Pile::getInstance().begin()) {
        --it;
        c = *it;
        i++;
        // on ajoute X élements
        if (ui->spinBox->value() >= i) {
            ui->pile->addItem(c->toString());
        }
    }

    // on n'oublie pas de sauvegarder la nouvelle valeur de la spin et la pile dans le fichier
    Pile::getInstance().sauvegarderDansFichier(ui->spinBox->value());
}

void Dialog::clearHistory() {
    ui->history->clear();
    PileAffichage::getInstance().clear();
}



