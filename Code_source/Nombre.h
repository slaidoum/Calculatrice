/**
 * @file Nombre.h
 * @brief Fichier header de la classe Nombre
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef NOMBRE_H
#define NOMBRE_H

#include <QString>

#include "Constante.h"

/**
 *  @class Nombre
 *  @brief Classe abstraite étant utilisée comme interface pour les classes qui en héritent.
 *  { hérite de Constante }
 *
 *  Un Nombre peut être soit un Complexe soit un NonComplexe.
 *
 *  Le Design Pattern Template Method est utilisé.
 */
class Nombre : public Constante {
    private:
    public:
        /**
         *  @brief Constructeur d'un nombre.
         *
         *  Constructeur d'un nombre.
         */
        Nombre() {}

        /**
         *  @brief Calcule l'opposée d'un nombre.
         *  Méthode virtuelle.
         *  @return L'opposée d'un nombre.
         *
         *  Calcule l'opposée d'un nombre.
         */
        virtual Nombre& sign() const;

        /**
         *  @brief Calcule le carré d'un nombre.
         *  Méthode virtuelle.
         *  @return Le carré d'un nombre.
         *
         *  Calcule le carré d'un nombre.
         */
        virtual Nombre& sqr() const;

        /**
         *  @brief Calcule le cube d'un nombre.
         *  Méthode virtuelle.
         *  @return Le cube d'un nombre.
         *
         *  Calcule le cube d'un nombre.
         */
        virtual Nombre& cube() const;

        /**
         *  @brief Calcule la somme de deux nombres.
         *  @param n L'autre nombre.
         *  @return La somme de deux nombres.
         *
         *  Calcule la somme de deux nombres.
         */
        inline Nombre& operator+(const Nombre& n);

        /**
         *  @brief Calcule la soustraction de deux nombres.
         *  @param n L'autre nombre.
         *  @return La soustraction de deux nombres.
         *
         *  Calcule la soustraction de deux nombres.
         */
        inline Nombre& operator-(const Nombre& n);

        /**
         *  @brief Calcule la multiplication de deux nombres.
         *  @param n L'autre nombre.
         *  @return La multiplication de deux nombres.
         *
         *  Calcule la multiplication de deux nombres.
         */
        inline Nombre& operator*(const Nombre& n);

        /**
         *  @brief Calcule la division de deux nombres.
         *  @param n L'autre nombre.
         *  @return La division de deux nombres.
         *
         *  Calcule la division de deux nombres.
         */
        inline Nombre& operator/(const Nombre& n);

        /**
         *  @brief Calcule la somme de deux nombres.
         *  Méthode virtuelle pure héritée depuis la classe Nombre.
         *  @param n L'autre nombre.
         *
         *  Calcule la somme de deux nombres.
         */
        virtual Nombre& addition(const Nombre& nb) const = 0;

        /**
         *  @brief Calcule la soustraction de deux nombres.
         *  Méthode virtuelle pure héritée depuis la classe Nombre.
         *  @param n L'autre nombre.
         *
         *  Calcule la soustraction de deux nombres.
         */
        virtual Nombre& soustraction(const Nombre& nb) const = 0;

        /**
         *  @brief Calcule la multiplication de deux nombres.
         *  Méthode virtuelle pure héritée depuis la classe Nombre.
         *  @param n L'autre nombre.
         *
         *  Calcule la multiplication de deux nombres.
         */
        virtual Nombre& multiplication(const Nombre& nb) const = 0;

        /**
         *  @brief Calcule la division de deux nombres.
         *  Méthode virtuelle pure héritée depuis la classe Nombre.
         *  @param n L'autre nombre.
         *
         *  Calcule la division de deux nombres.
         */
        virtual Nombre& division(const Nombre& nb) const = 0;

        /**
         *  @brief Crée une nouvelle instance de cette classe.
         *  Méthode virtuelle pure héritée depuis la classe Constante.
         *  @return La nouvelle instance de cette classe.
         *
         *  Crée une nouvelle instance de cette classe.
         */
        inline virtual Nombre* clone() const = 0;

        /**
         *  @brief Retourne une chaine de caractères correspondant aux informations encapsulées par un nombre.
         *  Méthode virtuelle pure héritée depuis la classe Constante.
         *  @return Une chaine de caractères correspondant aux informations encapsulées par un nombre.
         *
         *  Retourne une chaine de caractères correspondant aux informations encapsulées par un nombre.
         */
        virtual QString toString() const = 0;

};

// méthode membre de la classe qui appelle une méthode VP => DP Template Method
inline Nombre& Nombre::operator+(const Nombre& n){
    return this->addition(n);
}
// méthode membre de la classe qui appelle une méthode VP => DP Template Method
inline Nombre& Nombre::operator-(const Nombre& n){
    return this->soustraction(n);
}
// méthode membre de la classe qui appelle une méthode VP => DP Template Method
inline Nombre& Nombre::operator*(const Nombre& n){
    return this->multiplication(n);
}
// méthode membre de la classe qui appelle une méthode VP => DP Template Method
inline Nombre& Nombre::operator/(const Nombre& n){
    return this->division(n);
}

#endif // NOMBRE_H
