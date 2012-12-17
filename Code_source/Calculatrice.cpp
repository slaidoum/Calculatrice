#include "Calculatrice.h"
#include "Pile.h"
#include "PileAffichage.h"

#include "Expression.h"
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"
#include "Operateur.h"

#include "LogSystem.h"

#include <QStringList>
#include <QMessageBox>


// init
Calculatrice* Calculatrice::mCalculatrice = 0;

// récuperation l'unique instance de Calculatrice
Calculatrice& Calculatrice::getInstance(){
    if (mCalculatrice == 0){
        mCalculatrice = new Calculatrice();
    }
    return *mCalculatrice;
}

// libération instance de Calculatrice
void Calculatrice::libereInstance(){
    if (mCalculatrice != 0){
        delete mCalculatrice;
    }
    mCalculatrice = 0;
}

// fabrique soit une constante soit un opérateur (et l'éxécute).
void Calculatrice::fabriquer(const QString& text, enumType type) const {
    Pile* p = &Pile::getInstance();
    PileAffichage* pA = &PileAffichage::getInstance();

    switch (type) {
        case ENTIER:{
            Constante* res = new Entier(text.toInt());
            p->push(res);

            // ajout log dans le fichier de log
            LogSystem::add("Push dans la pile : " + res->toString(),FAIBLE);

            // on push dans la pile d'affichage
            pA->push(text);

            break;
        }
        case REEL:{
            Constante* res = new Reel(text.toDouble());
            p->push(res);

            // ajout log dans le fichier de log
            LogSystem::add("Push dans la pile : " + res->toString(),FAIBLE);

            // on push dans la pile d'affichage
            pA->push(text);


            break;
        }
        case RATIONNEL:{
            // séparation num / den
            QStringList tmp = text.split("/");
            Constante* res = new Rationnel(tmp.value(0).toInt(), tmp.value(1).toInt());
            p->push(res);

            // ajout log dans le fichier de log
            LogSystem::add("Push dans la pile : " + res->toString(),FAIBLE);

            // on push dans la pile d'affichage
            pA->push(text);


            break;
        }
        case COMPLEXE:{
            // séparation re  $  im
            QStringList tmp = text.split("$");

            // push la partie réelle du complexe
            if (this->isEntier(tmp.value(0))) {
                this->fabriquer(tmp.value(0),ENTIER);
            } else if (this->isReel(tmp.value(0))) {
                this->fabriquer(tmp.value(0),REEL);
            } else if (this->isRationnel(tmp.value(0))) {
                this->fabriquer(tmp.value(0),RATIONNEL);
            }

            // push la partie imaginaire du complexe
            if (this->isEntier(tmp.value(1))) {
                this->fabriquer(tmp.value(1),ENTIER);
            } else if (this->isReel(tmp.value(1))) {
                this->fabriquer(tmp.value(1),REEL);
            } else if (this->isRationnel(tmp.value(1))) {
                this->fabriquer(tmp.value(1),RATIONNEL);
            }

            // pop les deux parties
            const NonComplexe* c1 = dynamic_cast<const NonComplexe*>(p->pop());
            const NonComplexe* c2 = dynamic_cast<const NonComplexe*>(p->pop());

            // construction du complexe et push.
            Complexe* res = new Complexe(*c2, *c1);
            p->push(res);

            // ajout log dans le fichier de log
            LogSystem::add("Push dans la pile : " + res->toString(),FAIBLE);

            // on push dans la pile d'affichage
            pA->push(text);

            break;

        }
        case OPERATEUR:{
            Operateur* res = new Operateur(text);

            // ajout log dans le fichier de log
            LogSystem::add("Traitement opération : " + text,FAIBLE);

            // on push dans la pile d'affichage
            pA->push(text);

            res->effectuerOperation();
            break;
        }
        case EXPRESSION:{
            QString tmp(text);
            tmp.replace(QString("'"), QString(""));
            Constante* res = new Expression(tmp);
            p->push(res);

            // ajout log dans le fichier de log
            LogSystem::add("Push dans la pile : " + res->toString(),FAIBLE);

            // on push dans la pile d'affichage
            pA->push(text);

            break;
        }
        default:{
            QMessageBox::critical(0,"Erreur !", "Fabrication d'objet impossible!");
            // ajout log dans le fichier de log
            LogSystem::add("Fabrication d'objet impossible",ELEVEE);
            break;
        }
    }
}


bool Calculatrice::isOperateur(const QString& s) const{
    if (isOperateurBinaire(s) || isOperateurUnaire(s) || isOperateurSansArg(s)) {
        return true;
    }
    return false;
}

bool Calculatrice::isConstante(const QString& s) const{
    if (isEntier(s) || isReel(s) || isRationnel(s) || isComplexe(s)) {
        return true;
    }
    return false;
}

// 5 6 8 2 48888
bool Calculatrice::isEntier(const QString& s) const{
    QRegExp regexp("^[\\d]+$");
    return regexp.exactMatch(s);
}

// 41.4 6.0 44.5454
bool Calculatrice::isReel(const QString& s) const{
    QRegExp regexp("^[\\d]+[\.][\\d]+$");
    return regexp.exactMatch(s);
}

// 45/456454
bool Calculatrice::isRationnel(const QString& s) const{
    QRegExp regexp("^[\\d]+\/[\\d]+$");
    return regexp.exactMatch(s);
}

// 5454$5454 5454.222$5454.3222 5454/22$331/1212
bool Calculatrice::isComplexe(const QString& s) const{
    QRegExp regexp("^[\\d]+(([\.]|[\/])[\\d]+)?[\$][\\d]+(([\.]|[\/])[\\d]+)?$");
    return regexp.exactMatch(s);
}

// + - * / Pow Mod Swap
bool Calculatrice::isOperateurBinaire(const QString& s) const{
    QRegExp regexp("^(Pow|Mod|Swap)|([+*/-])$");
    return regexp.exactMatch(s);
}


// Fact, Sin, Cos, Tan, Sinh, Cosh, Tanh, Ln, Inv, Log, Sqrt, Eval, Sqr, Cube, Sign, Sum, Mean
bool Calculatrice::isOperateurUnaire(const QString& s) const{
    QRegExp regexp("^(Fact|Sin|Cos|Tan|Sinh|Cosh|Tanh|Ln|Inv|Log|Sqrt|Eval|Sqr|Cube|Sign|Sum|Mean)$");
    return regexp.exactMatch(s);
}

// Clear, Dup, Drop
bool Calculatrice::isOperateurSansArg(const QString& s) const{
    QRegExp regexp("^(Clear|Dup|Drop)$");
    return regexp.exactMatch(s);
}

