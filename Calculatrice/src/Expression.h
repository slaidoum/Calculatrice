/**
 * @file Expression.h
 * @brief Fichier header de la classe Expression
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QTextStream>
#include <QString>

#include "Constante.h"

/**
 *  @class Expression
 *  @brief Classe permettant de créer et manipuler des constantes de type Expression.
 *  { hérite de Constante }
 */
class Expression : public Constante {
    private:
        /**<
         *  Une chaine de caractères correspondant à l'expression.
         */
        QString mExpression;
    public:
        /**
         *  @brief Crée un objet de cette classe.
         *  @param Une chaine de caractères correspondant à l'expression.
         *
         *  Crée un objet de cette classe.
         */
        Expression(const QString& s = "") : mExpression(s) {}

        /**
         *  @brief Evalue l'expression encapsulée par cette classe.
         *
         *  Evalue l'expression encapsulée par cette classe.
         */
        void eval() const;

        /**
         *  @brief Retourne la concatenation de l'expression encapsulée par cette classe, de la constante passée en paramètre et de l'opérateur '+'.
         *  @param n La constante à concatener.
         *  @return Retourne la concatenation de l'expression encapsulée par cette classe, de la constante passée en paramètre et de l'opérateur '+'.
         *
         *  Retourne la concatenation de l'expression encapsulée par cette classe, de la constante passée en paramètre et de l'opérateur '+'.
         */
        Constante& addition(const Constante& n) const;

        /**
         *  @brief Retourne la concatenation de l'expression encapsulée par cette classe, de la constante passée en paramètre et de l'opérateur '-'.
         *  @param n La constante à concatener.
         *  @return Retourne la concatenation de l'expression encapsulée par cette classe, de la constante passée en paramètre et de l'opérateur '-'.
         *
         *  Retourne la concatenation de l'expression encapsulée par cette classe, de la constante passée en paramètre et de l'opérateur '-'.
         */
        Constante& soustraction(const Constante& n) const;

        /**
         *  @brief Retourne la concatenation de l'expression encapsulée par cette classe, de la constante passée en paramètre et de l'opérateur '*'.
         *  @param n La constante à concatener.
         *  @return Retourne la concatenation de l'expression encapsulée par cette classe, de la constante passée en paramètre et de l'opérateur '*'.
         *
         *  Retourne la concatenation de l'expression encapsulée par cette classe, de la constante passée en paramètre et de l'opérateur '/'.
         */
        Constante& multiplication(const Constante& n) const;

        /**
         *  @brief Retourne la concatenation de l'expression encapsulée par cette classe, de la constante passée en paramètre et de l'opérateur '/'.
         *  @param n La constante à concatener.
         *  @return Retourne la concatenation de l'expression encapsulée par cette classe, de la constante passée en paramètre et de l'opérateur '/'.
         *
         *  Retourne la concatenation de l'expression encapsulée par cette classe, de la constante passée en paramètre et de l'opérateur '/'.
         */
        Constante& division(const Constante& n) const;

        /**
         *  @brief Crée une nouvelle instance de cette classe.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Constante.
         *  @return La nouvelle instance de cette classe.
         *
         *  Crée une nouvelle instance de cette classe.
         */
        inline virtual Expression* clone() const;

        /**
         *  @brief Retourne une chaine de caractères correspondant aux informations encapsulées par une expression.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Constante.
         *  @return Une chaine de caractères correspondant aux informations encapsulées par une expression.
         *
         *  Retourne une chaine de caractères correspondant aux informations encapsulées par une expression.
         */
        inline QString toString() const;

};

// affichage
inline QString Expression::toString() const {
    return mExpression;
}

// clone
inline Expression* Expression::clone() const {
    return new Expression(*this);
}



#endif // EXPRESSION_H
