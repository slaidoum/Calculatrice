#include "Operateur.h"
#include "Pile.h"

#include "Expression.h"
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"
#include "Operateur.h"

#include "LogSystem.h"

#include <QStringList>
#include <QMessageBox>


Operateur::Operateur(const QString& s) {
    if (s == "+") {
        mOperateur = ADD;
    } else if (s == "-") {
        mOperateur = SOUS;
    } else if (s == "*") {
        mOperateur = MUL;
    } else if (s == "/") {
        mOperateur = DIV;
    } else if (s == "Pow") {
        mOperateur = POW;
    } else if (s == "Mod") {
        mOperateur = MOD;
    } else if (s == "Cos") {
        mOperateur = COS;
    } else if (s == "Fact") {
        mOperateur = FACT;
    } else if (s == "Sin") {
        mOperateur = SIN;
    } else if (s == "Tan") {
        mOperateur = TAN;
    } else if (s == "Cosh") {
        mOperateur = COSH;
    } else if (s == "Sinh") {
        mOperateur = SINH;
    } else if (s == "Tanh") {
        mOperateur = TANH;
    } else if (s == "Ln") {
        mOperateur = LN;
    } else if (s == "Inv") {
        mOperateur = INV;
    } else if (s == "Log") {
        mOperateur = LOG;
    } else if (s == "Sqrt") {
        mOperateur = SQRT;
    } else if (s == "Sqr") {
        mOperateur = SQR;
    } else if (s == "Cube") {
        mOperateur = CUBE;
    } else if (s == "Sign") {
        mOperateur = SIGN;
    } else if (s == "Eval") {
        mOperateur = EVAL;
    } else if (s == "Swap") {
        mOperateur = SWAP;
    } else if (s == "Sum") {
        mOperateur = SUM;
    } else if (s == "Mean") {
        mOperateur = MEAN;
    } else if (s == "Clear") {
        mOperateur = CLEAR;
    } else if (s == "Dup") {
        mOperateur = DUP;
    } else if (s == "Drop") {
        mOperateur = DROP;
    } else {
        QMessageBox::critical(0,"Erreur !", "Operateur inconnu !");
    }
}

void Operateur::effectuerOperation() const {

    Pile* p = &Pile::getInstance();

    switch (mOperateur) {
        case ADD : {
            try {
                if (p->count() < 2) {
                    throw CalculatriceException("ADD : La pile doit contenir au moins deux éléments!");
                }

                Constante* x = p->pop();
                Constante* y = p->pop();

                Expression* cy = dynamic_cast<Expression*>(y);

                // addition sur une Expression
                if (cy != 0) {
                    Constante& res = cy->addition(*x);
                    p->push(&res);
                    delete x;
                    delete y;
                } else {
                    try {

                        // cast en Nombre
                        Nombre* cx = dynamic_cast<Nombre*>(x);
                        Nombre* cy = dynamic_cast<Nombre*>(y);

                        if (cx!=0 || cy!=0){ // deux Nombre
                            Constante& res = cy->addition(*cx);
                            p->push(&res);
                            delete x;
                            delete y;
                        } else {
                            throw CalculatriceException("ADD : Division ne fonctionne que sur des Nombre!");
                        }
                    } catch(CalculatriceException& e) {
                        // on repoush ce qu'on a popé de la pile (le non Nombre)
                        p->push(y);
                        p->push(x);
                        QMessageBox::critical(0,"Erreur !",e.getMessage());
                        // ajout log dans le fichier de log
                        LogSystem::add(e.getMessage(),ELEVEE);
                    }
                }

            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }

            break;
        }
        case SOUS : {
            try {
                if (p->count() < 2) {
                    throw CalculatriceException("SOUS : La pile doit contenir au moins deux éléments!");
                }

                Constante* x = p->pop();
                Constante* y = p->pop();

                Expression* cy = dynamic_cast<Expression*>(y);

                // soustraction sur une Expression
                if (cy != 0) {
                    Constante& res = cy->soustraction(*x);
                    p->push(&res);
                    delete x;
                    delete y;
                } else {
                    try {
                        // cast en Nombre
                        Nombre* cx = dynamic_cast<Nombre*>(x);
                        Nombre* cy = dynamic_cast<Nombre*>(y);

                        if (cx!=0 || cy!=0){ // deux Nombre
                            Constante& res = cy->soustraction(*cx);
                            p->push(&res);
                            delete x;
                            delete y;
                        } else {
                            throw CalculatriceException("SOUS : Division ne fonctionne que sur des Nombre!");
                        }
                    } catch(CalculatriceException& e) {
                        // on repoush ce qu'on a popé de la pile (le non Nombre)
                        p->push(y);
                        p->push(x);
                        QMessageBox::critical(0,"Erreur !",e.getMessage());
                        // ajout log dans le fichier de log
                        LogSystem::add(e.getMessage(),ELEVEE);
                    }
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }

            break;
        }
        case MUL : {
            try {
                if (p->count() < 2) {
                    throw CalculatriceException("MUL : La pile doit contenir au moins deux éléments!");
                }

                Constante* x = p->pop();
                Constante* y = p->pop();

                Expression* cy = dynamic_cast<Expression*>(y);

                // multiplciation sur une Expression
                if (cy != 0) {
                    Constante& res = cy->multiplication(*x);
                    p->push(&res);
                    delete x;
                    delete y;
                } else {
                    try {
                        // cast en Nombre
                        Nombre* cx = dynamic_cast<Nombre*>(x);
                        Nombre* cy = dynamic_cast<Nombre*>(y);

                        if (cx!=0 || cy!=0){ // deux Nombre
                            Constante& res = cy->multiplication(*cx);
                            p->push(&res);
                            delete x;
                            delete y;
                        } else {
                            throw CalculatriceException("MUL : Division ne fonctionne que sur des Nombre!");
                        }
                    } catch(CalculatriceException& e) {
                        // on repoush ce qu'on a popé de la pile (le non Nombre)
                        p->push(y);
                        p->push(x);
                        QMessageBox::critical(0,"Erreur !",e.getMessage());
                        // ajout log dans le fichier de log
                        LogSystem::add(e.getMessage(),ELEVEE);
                    }
                }

            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }

            break;
        }
        case DIV : {
            try {
                if (p->count() < 2) {
                    throw CalculatriceException("DIV : La pile doit contenir au moins deux éléments!");
                }

                Constante* x = p->pop();
                Constante* y = p->pop();

                Expression* cy = dynamic_cast<Expression*>(y);

                // addition sur une Expression
                if (cy != 0) {
                    Constante& res = cy->division(*x);
                    p->push(&res);
                    delete x;
                    delete y;
                } else {
                    try {
                        // cast en Nombre
                        Nombre* cx = dynamic_cast<Nombre*>(x);
                        Nombre* cy = dynamic_cast<Nombre*>(y);

                        if (cx!=0 || cy!=0){ // deux Nombre
                            Constante& res = cy->division(*cx);
                            p->push(&res);
                            delete x;
                            delete y;
                        } else {
                            throw CalculatriceException("DIV : Division ne fonctionne que sur des Nombre!");
                        }
                    } catch(CalculatriceException& e) {
                        // on repoush ce qu'on a popé de la pile (le non Nombre)
                        p->push(y);
                        p->push(x);
                        QMessageBox::critical(0,"Erreur !",e.getMessage());
                        // ajout log dans le fichier de log
                        LogSystem::add(e.getMessage(),ELEVEE);
                    }
                }

            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }

            break;
        }
        case POW : {
            try {
                if (p->count() < 2) {
                    throw CalculatriceException("POW : La pile doit contenir au moins deux éléments!");
                }

                Constante* x = p->pop();
                Constante* y = p->pop();

                try {

                    // cast en Entier
                    NonComplexe* cx = dynamic_cast<NonComplexe*>(x);
                    NonComplexe* cy = dynamic_cast<NonComplexe*>(y);

                    if (cx!=0 || cy!=0){ // deux non complexes
                        Constante& res = cy->pow(*cx);
                        p->push(&res);
                        delete x;
                        delete y;
                    } else {
                        throw CalculatriceException("POW : Puissance fonctionne ainsi : NonComplexe^NonComplexe!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(y);
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }

            break;
        }
        case MOD : {
            try {
                if (p->count() < 2) {
                    throw CalculatriceException("MOD : La pile doit contenir au moins deux éléments!");
                }

                Constante* x = p->pop();
                Constante* y = p->pop();

                try {

                    // cast en Entier
                    Entier* cx = dynamic_cast<Entier*>(x);
                    Entier* cy = dynamic_cast<Entier*>(y);

                    if (cx!=0 || cy!=0){ // deux non complexes
                        Constante& res = cy->mod(*cx);
                        p->push(&res);
                        delete x;
                        delete y;
                    } else {
                        throw CalculatriceException("MOD : Modulo ne fonctionne que sur des Entier!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(y);
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }

            break;
        }
        case FACT : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("FACT : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {

                    // cast en Entier
                    Entier* cx = dynamic_cast<Entier*>(x);

                    if (cx!=0) { // Entier
                        Constante& res = cx->fact();
                        p->push(&res);
                        delete x;
                    } else {
                        throw CalculatriceException("FACT : Factorielle ne fonctionne que sur des entiers !");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non entier)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);

                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }

            break;
        }
        case COS : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("COS : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {
                    // canst en NonComplexe
                    NonComplexe* cx = dynamic_cast<NonComplexe*>(x);

                    if (cx!=0) { // NonComplexe
                        Constante& res = cx->cos();
                        p->push(&res);
                        delete x;
                    } else {
                        throw CalculatriceException("COS : Cosinus ne fonctionne que sur des NonComplexes!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case SIN : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("SIN : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {
                    // canst en NonComplexe
                    NonComplexe* cx = dynamic_cast<NonComplexe*>(x);

                    if (cx!=0) { // NonComplexe
                        Constante& res = cx->sin();
                        p->push(&res);
                        delete x;
                    } else {
                        throw CalculatriceException("SIN : Sinus ne fonctionne que sur des NonComplexes!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case TAN : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("TAN : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {
                    // canst en NonComplexe
                    NonComplexe* cx = dynamic_cast<NonComplexe*>(x);

                    if (cx!=0) { // NonComplexe
                        Constante& res = cx->tan();
                        p->push(&res);
                        delete x;
                    } else {
                        throw CalculatriceException("TAN : Tangente ne fonctionne que sur des NonComplexes!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case COSH : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("COSH : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {
                    // canst en NonComplexe
                    NonComplexe* cx = dynamic_cast<NonComplexe*>(x);

                    if (cx!=0) { // NonComplexe
                        Constante& res = cx->cosh();
                        p->push(&res);
                        delete x;
                    } else {
                        throw CalculatriceException("COSH : CosinusH ne fonctionne que sur des NonComplexes!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case SINH : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("SINH : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {
                    // canst en NonComplexe
                    NonComplexe* cx = dynamic_cast<NonComplexe*>(x);

                    if (cx!=0) { // NonComplexe
                        Constante& res = cx->sinh();
                        p->push(&res);
                        delete x;
                    } else {

                        throw CalculatriceException("SINH : SinusH ne fonctionne que sur des NonComplexes!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case TANH : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("TANH : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {
                    // canst en NonComplexe
                    NonComplexe* cx = dynamic_cast<NonComplexe*>(x);

                    if (cx!=0) { // NonComplexe
                        Constante& res = cx->tanh();
                        p->push(&res);
                        delete x;
                    } else {
                        throw CalculatriceException("TANH : TangenteH ne fonctionne que sur des NonComplexes!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case LN : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("COS : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {
                    // canst en NonComplexe
                    NonComplexe* cx = dynamic_cast<NonComplexe*>(x);

                    if (cx!=0) { // NonComplexe
                        Constante& res = cx->ln();
                        p->push(&res);
                        delete x;
                    } else {
                        throw CalculatriceException("LN : LN  ne fonctionne que sur des NonComplexes!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }

            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case INV : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("INV : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {
                    // canst en NonComplexe
                    NonComplexe* cx = dynamic_cast<NonComplexe*>(x);

                    if (cx!=0) { // NonComplexe
                        Constante& res = cx->inv();
                        p->push(&res);
                        delete x;
                    } else {
                        throw CalculatriceException("INV : Inverse ne fonctionne que sur des NonComplexes!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }

            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case LOG : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("LOG : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {
                    // canst en NonComplexe
                    NonComplexe* cx = dynamic_cast<NonComplexe*>(x);

                    if (cx!=0) { // NonComplexe
                        Constante& res = cx->log();
                        p->push(&res);
                        delete x;
                    } else {

                        throw CalculatriceException("LOG : Logarithme ne fonctionne que sur des NonComplexes!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }

            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case SQRT : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("SQRT : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {
                    // canst en NonComplexe
                    NonComplexe* cx = dynamic_cast<NonComplexe*>(x);

                    if (cx!=0) { // NonComplexe
                        Constante& res = cx->sqrt();
                        p->push(&res);
                        delete x;
                    } else {
                        throw CalculatriceException("SQRT : Racine carée ne fonctionne que sur des NonComplexes!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }

            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case SIGN : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("SIGN : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {

                    // canst en Nombre
                    Nombre* cx = dynamic_cast<Nombre*>(x);

                    if (cx!=0) { // Nombre
                        Constante& res = cx->sign();
                        p->push(&res);
                        delete x;
                    } else {

                        throw CalculatriceException("SIGN : Signe ne fonctionne que sur des Nombre!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case EVAL : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("EVAL : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {

                    // canst en Expression
                    Expression* cx = dynamic_cast<Expression*>(x);

                    if (cx!=0) { // Expression
                        cx->eval();
                        delete x;
                    } else {
                        throw CalculatriceException("EVAL : Evaluation ne fonctionne que sur des Expression!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non Expression)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case SQR : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("SQR : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {

                    // canst en Nombre
                    Nombre* cx = dynamic_cast<Nombre*>(x);

                    if (cx!=0) { // Nombre
                        Constante& res = cx->sqr();
                        p->push(&res);
                        delete x;
                    } else {
                        throw CalculatriceException("SQR : Fonction carré ne fonctionne que sur des Nombre!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case CUBE : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("Cube : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {

                    // canst en Nombre
                    Nombre* cx = dynamic_cast<Nombre*>(x);

                    if (cx!=0) { // Nombre
                        Constante& res = cx->cube();
                        p->push(&res);
                        delete x;
                    } else {

                        throw CalculatriceException("Cube : Cube ne fonctionne que sur des Nombre!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }

            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }
            break;
        }
        case SWAP : {
            try {
                if (p->count() < 4) {
                    throw CalculatriceException("SWAP : La pile doit contenir au moins quatres éléments (x, y : les parametres et le reste pour swaper)!");
                }

                Constante* x = p->pop();
                Constante* y = p->pop();

                try {

                    // cast en Entier
                    Entier* cx = dynamic_cast<Entier*>(x);
                    Entier* cy = dynamic_cast<Entier*>(y);

                    if (cx!=0 || cy!=0){ // deux Entier
                        p->swap(cx->getX(),cy->getX());
                    } else {
                        throw CalculatriceException("SWAP : Swap prend comme parametres deux Entier!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(y);
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case SUM : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("SUM : La pile doit contenir deux éléments (x le parametre pour la somme > 1 et le reste)!");
                }

                Constante* x = p->pop();

                try {

                    // canst en Entier
                    Entier* cx = dynamic_cast<Entier*>(x);

                    if (cx!=0) { // Entier
                        if (cx->getX() <= 1) {
                           throw CalculatriceException("SUM : Somme prend comme parametre un Entier supérieur à 1!");
                        }
                        p->sum(cx->getX());
                        delete x;
                    } else {
                        throw CalculatriceException("SUM : Somme prend comme parametre un Entier!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }


            break;
        }
        case MEAN : {
            try {
                if (p->count() < 1) {
                    throw CalculatriceException("MEAN : La pile doit contenir au moins un élément!");
                }

                Constante* x = p->pop();

                try {

                    // canst en Entier
                    Entier* cx = dynamic_cast<Entier*>(x);

                    if (cx!=0) { // Entier
                        if (cx->getX() <= 1) {
                           throw CalculatriceException("MEAN : Moyenne prend comme parametre un Entier supérieur à 1!");
                        }
                        p->mean(cx->getX());
                        delete x;
                    } else {
                        throw CalculatriceException("MEAN : Moyenne prend comme parametre un Entier!");
                    }
                } catch(CalculatriceException& e) {
                    // on repoush ce qu'on a popé de la pile (le non NonComplexe)
                    p->push(x);
                    QMessageBox::critical(0,"Erreur !",e.getMessage());
                    // ajout log dans le fichier de log
                    LogSystem::add(e.getMessage(),ELEVEE);
                }
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }

            break;
        }
        case CLEAR : {
            p->clearPile();
            break;
        }
        case DUP : {
            try {
                p->dup();
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }
            break;
        }
        case DROP : {
            try {
                p->drop();
            } catch(CalculatriceException& e) {
                QMessageBox::critical(0,"Erreur !",e.getMessage());
                // ajout log dans le fichier de log
                LogSystem::add(e.getMessage(),ELEVEE);
            }
            break;
        }
        default : {
            QMessageBox::critical(0,"Erreur !", "Operateur inconnu !");
            // ajout log dans le fichier de log
            LogSystem::add("Operateur inconnu !",ELEVEE);
            break;
        }
    }
}
