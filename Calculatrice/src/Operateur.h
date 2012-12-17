/**
 * @file Operateur.h
 * @brief Fichier header de la classe Operateur
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef OPERATEUR_H
#define OPERATEUR_H

#include <QString>
#include "CalculatriceException.h"

/**<
 *  Les opérateurs valides.
 */
enum enumOperateur {ADD, SOUS, MUL, DIV, POW, MOD, FACT, COS, SIN, TAN, COSH, SINH, TANH, LN, INV, LOG, SQRT, EVAL, SQR, CUBE,  SIGN, SWAP, SUM, MEAN, CLEAR, DUP, DROP};

/**
 *  @class Operateur
 *  @brief Classe permettant de créer et manipuler des opérateurs.
 */
class Operateur {
    private:
        /**<
         *  Une chaine de caractères correspondant à l'opérateur.
         */
        enumOperateur mOperateur;
    public:
        /**
         *  @brief Crée un objet de cette classe.
         *  @param Une chaine de caractères correspondant à l'opérateur.
         *
         *  Crée un objet de cette classe.
         */
        Operateur(const QString& s);

        /**
         *  @brief Effectue l'opération encapsulée par cette classe (traitement avec la pile).
         *
         *  Effectue l'opération encapsulée par cette classe (traitement avec la pile).
         */
        void effectuerOperation() const;
};

#endif // OPERATEUR_H
