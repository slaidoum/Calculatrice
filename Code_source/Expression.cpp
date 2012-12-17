#include "Expression.h"
#include "Calculatrice.h"
#include "Pile.h"
#include <QString>
#include <QStringList>

void Expression::eval() const {
    if (!mExpression.isEmpty()) {
         QTextStream cout(stdout, QIODevice::WriteOnly);

        // on recupère une instance de Calculatrice
        Calculatrice& calculatrice = Calculatrice::getInstance();

        QString constanteATraiter("");

        // on construit des constantes et opérateurs à partir de l'expresssion, en enlevant les espaces
        QStringList listeConst = mExpression.split(" ");
        QStringList::iterator it;
        // on boucle sur chacun des élements de l'expression
        for (it = listeConst.begin(); it != listeConst.end(); ++it) {
            constanteATraiter = QString(*it); // on recupère sour forme de chaine de caractères
            cout << "En cours : |" << constanteATraiter << "|"<< endl;
            // constante ou opérateur
            if (calculatrice.isOperateur(constanteATraiter) || calculatrice.isConstante(constanteATraiter)) {
                // si c'est une constante
                if (calculatrice.isConstante(constanteATraiter)) {
                    cout << "Element is constante :";
                    cout << constanteATraiter << endl;

                    if (calculatrice.isComplexe(constanteATraiter)) {
                        calculatrice.fabriquer(constanteATraiter,COMPLEXE);
                    } else if (calculatrice.isEntier(constanteATraiter)) {
                        calculatrice.fabriquer(constanteATraiter,ENTIER);
                    } else if (calculatrice.isReel(constanteATraiter)) {
                        calculatrice.fabriquer(constanteATraiter,REEL);
                    } else if (calculatrice.isRationnel(constanteATraiter)) {
                        calculatrice.fabriquer(constanteATraiter,RATIONNEL);
                    }

                // si c'est un opérateur
                } else if (calculatrice.isOperateur(constanteATraiter)) {
                    cout << "Element is operateur :";
                    cout << constanteATraiter << endl;
                    calculatrice.fabriquer(constanteATraiter,OPERATEUR);
                }
            // objet inconnu, erreur
            } else {
                cout << "erreur : objet inconnu";
                break;
            }
        }
    } else {
        throw CalculatriceException("Impossible d'évaluer une expression vide !");
    }
}

// contatenation expressions et constantes
Constante& Expression::addition(const Constante& n) const {
    Expression* res = new Expression(mExpression + " " + n.toString() + " +");
    Constante& ref = *res;
    return ref;
}
Constante& Expression::soustraction(const Constante& n) const {
    Expression* res = new Expression(mExpression + " " + n.toString() + " -");
    Constante& ref = *res;
    return ref;
}

Constante& Expression::multiplication(const Constante& n) const {
    Expression* res = new Expression(mExpression + " " + n.toString() + " *");
    Constante& ref = *res;
    return ref;
}

Constante& Expression::division(const Constante& n) const {
    Expression* res = new Expression(mExpression + " " + n.toString() + " /");
    Constante& ref = *res;
    return ref;
}

