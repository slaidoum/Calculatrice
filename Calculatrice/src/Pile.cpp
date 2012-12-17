#include "Pile.h"
#include "BackUpPiles.h"

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"
#include "Expression.h"

#include "Calculatrice.h"
#include "LogSystem.h"

#include <QStringList>
#include <QMessageBox>
#include <QFile>

#define FICHIER_PARAMETRES "fichierParametres"

Pile* Pile::mPile = 0;

Pile& Pile::getInstance() {
    if (mPile==0) {
        mPile = new Pile();
    }
    return *mPile;
}

void Pile::libereInstance(){
    if (mPile!=0) {
        delete mPile;
    }
    mPile = 0;
}

void Pile::swap(int x, int y){
    if (x >= mPile->size() || x < 0 || y < 0 || y >= mPile->size()) {
        throw CalculatriceException("SWAP : Impossible, parametres incorrects (débordement/contraire : pile)!");
    }
    Constante* tmp;
    tmp = mPile->value(x);
    mPile->replace(x, mPile->value(y));
    mPile->replace(y, tmp);
}

void Pile::sum(int x){
    if (x > mPile->size() || x < 0) {
        throw CalculatriceException("SUM : Impossible, parametre incorrect (débordement/contraire : pile)");
    }
    do {
        try {
            Constante* a = mPile->pop();
            Constante* b = mPile->pop();
            Nombre* ca = dynamic_cast<Nombre*>(a);
            Nombre* cb = dynamic_cast<Nombre*>(b);
            if (ca!=0 || cb!=0){ // deux Nombre
                Constante& res = *ca + *cb;
                mPile->push(&res);

                delete a;
                delete b;
            }
        } catch (std::exception& e) {
            QMessageBox::critical(0, "Erreur !", e.what());
        }
        x--;
    } while(x > 1);
}

void Pile::mean(int x){
    if(x > mPile->size() || x < 0) {
        throw CalculatriceException("MEAN : Impossible, parametre incorrect (débordement/contraire : pile)!");
    }
    this->sum(x); // on push la somme des x premiers elements de la pile
    Entier diviseur(x); // notre diviseur

    try {
        Constante* c = mPile->pop(); // on pop la somme
        Nombre* cx = dynamic_cast<Nombre*>(c);
        if (cx != 0) {
            Constante& res = *cx / diviseur;
            mPile->push(&res);
            delete c;
        }
    } catch (std::exception& e) {
        QMessageBox::critical(0, "Erreur !", e.what());
    }
}

void Pile::clearPile() {
    mPile->clear();
    BackUpPiles::getInstance()->clearBackUpPiles();

}

void Pile::dup() {

    // on recupère une instance de la calculatrice
    Calculatrice& calc = Calculatrice::getInstance();

    // pile vide = erreur
    if(Pile::getInstance().isEmpty()){
        throw CalculatriceException("Dup Impossible : Pile vide");
    }

    // on pop le dernier élement
    Constante* c = mPile->top();

    Entier* ptEntier = dynamic_cast<Entier*>(c);
    if(ptEntier != 0){ // Entier
        mPile->push(new Entier(ptEntier->getX()));
    } else {
        Reel* ptReel = dynamic_cast<Reel*>(c);
        if (ptReel != 0){ // Reel
            mPile->push(new Reel(ptReel->getX()));
        } else {
            Rationnel* ptRationnel = dynamic_cast<Rationnel*>(c);
            if(ptRationnel != 0){ // Rationnel
                Entier n = ptRationnel->getNum();
                Entier d = ptRationnel->getDen();
                mPile->push(new Rationnel(n,d));
            }
            else{
                Expression* ptExpression = dynamic_cast<Expression*>(c);
                if (ptExpression != 0){ // Expression
                    mPile->push(new Expression(ptExpression->toString()));
                }
                else{
                   Complexe* ptComplexe = dynamic_cast<Complexe*>(c);
                    if (ptComplexe != 0){ // Complexe

                        // séparation re  $  im
                        QStringList tmp = ptComplexe->toString().split("$");

                        // push la partie réelle du complexe
                        if (calc.isEntier(tmp.value(0))) {
                            calc.fabriquer(tmp.value(0),ENTIER);
                        } else if (calc.isReel(tmp.value(0))) {
                            calc.fabriquer(tmp.value(0),REEL);
                        } else if (calc.isRationnel(tmp.value(0))) {
                            calc.fabriquer(tmp.value(0),RATIONNEL);
                        }

                        // push la partie imaginaire du complexe
                        if (calc.isEntier(tmp.value(1))) {
                            calc.fabriquer(tmp.value(1),ENTIER);
                        } else if (calc.isReel(tmp.value(1))) {
                            calc.fabriquer(tmp.value(1),REEL);
                        } else if (calc.isRationnel(tmp.value(1))) {
                            calc.fabriquer(tmp.value(1),RATIONNEL);
                        }

                        // pop les deux parties
                        const NonComplexe* c1 = dynamic_cast<const NonComplexe*>(mPile->pop());
                        const NonComplexe* c2 = dynamic_cast<const NonComplexe*>(mPile->pop());

                        // construction du complexe et push.
                        mPile->push(new Complexe(*c2,*c1));
                    }
                    else {
                        throw CalculatriceException("DUP : Impossible de dupliquer cette constante (type inconnu)!");
                    }
               }
            }
        }
    }
}

void Pile::drop(){
    if (mPile->isEmpty()) {
        throw CalculatriceException("Drop Impossible : Pile vide");
    }
    Constante* e = this->pop();
    delete e;
}

void Pile::sauvegarderDansFichier(int nbEltsPile) const {
    QFile fichier(FICHIER_PARAMETRES);

    if (fichier.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            QDataStream ecriture(&fichier);

            // on écrit en premier le nombre d'élements de la pile à afficher.
            ecriture << nbEltsPile;

            QStack<Constante*>::iterator it;
            Constante* c = 0;
            QString s = "";
            for (it = Pile::getInstance().begin(); it != Pile::getInstance().end(); ++it){
                c = *it;
                s = c->toString();
                ecriture << s; // on écrit des QString dans le fichier
            }

            // ajout log dans le fichier de log
            // LogSystem::add("(sauvegarde etat pile et nbElts a afficher dans le fic. 'fichierParametres')",FAIBLE);
            fichier.close();
    }
    else {
        QMessageBox::information(0, "Information", "Impossible d'ouvrir le fichier de paramètres, paramètres reglés par défaut.");
        // ajout log dans le fichier de log
        LogSystem::add("Impossible d'ouvrir le fichier de paramètres, paramètres reglés par défaut.",MOYENNE);
    }
}

/* Récuperation état pile */
int Pile::chargerDepuisFichier() {
    // on recupère une instance de la calculatrice
    Calculatrice& calc = Calculatrice::getInstance();

    QFile fichier(FICHIER_PARAMETRES);
    if (fichier.exists()) {
       fichier.open(QIODevice::ReadOnly);
       QDataStream lecture(&fichier);

       QString constante;
       int i = 0;
       int nbEltsPile = 0;

       QTextStream cout(stdout, QIODevice::WriteOnly);
       cout << endl;

       // tant qu'on n'a pas atteint la fin du fichier, on lit
       while (!lecture.atEnd()) {
           if (i == 0) {
               lecture >> nbEltsPile;
               cout << "Lu depuis le fichier de parametres : " << nbEltsPile << endl;
           } else {
               lecture >> constante;
               cout << "Lu depuis le fichier de parametres : " << constante << endl;
               if (calc.isEntier(constante)) {
                   calc.fabriquer(constante,ENTIER);
               } else if (calc.isReel(constante)) {
                   calc.fabriquer(constante,REEL);
               } else if (calc.isRationnel(constante)) {
                   calc.fabriquer(constante,RATIONNEL);
               } else if (calc.isComplexe(constante)) {
                   calc.fabriquer(constante,COMPLEXE);
               } else { // sinon c'est forcement une expression
                   calc.fabriquer(constante,EXPRESSION);
               }
           }
           i++;
       }
       fichier.close();
       return nbEltsPile;
    } else {
       QMessageBox::information(0, "Information", QString::fromUtf8("Impossible d'ouvrir le fichier de paramètres, paramètres reglés par défaut."));
       // ajout log dans le fichier de log
       LogSystem::add("Impossible d'ouvrir le fichier de paramètres, paramètres reglés par défaut.",MOYENNE);
       return -1;
    }
}

Pile* Pile::clone() const {
    Pile* pClone = new Pile();
    QStack<Constante*>::iterator it;
    Constante* c = 0;
    for (it = Pile::getInstance().begin(); it != Pile::getInstance().end(); ++it){
        c = *it;
        pClone->push(c->clone()); // on push dans la nouvelle pile le clone de chaque constante de la pile actuelle.
    }
    return pClone;
}

