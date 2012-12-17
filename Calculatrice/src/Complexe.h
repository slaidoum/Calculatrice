/**
 * @file Complexe.h
 * @brief Fichier header de la classe Complexe
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "NonComplexe.h"
#include "Nombre.h"

class NonComplexe;

/**
 *  @class Complexe
 *  @brief  Classe permettant de créer et manipuler des constantes de type Complexe.
 *  { hérite de Nombre }
 */
class Complexe : public Nombre {
    private:
        /**<
         *  Un pointeur vers la partie imaginaire de ce nombre complexe.
         */
        const NonComplexe* mRe;

        /**<
         *  Un pointeur vers la partie réelle de ce nombre complexe.
         */
        const NonComplexe* mIm;
    public:
        /**
         *  @brief Crée un nombre complexe.
         *  @param re La partie réelle de ce nombre complexe.
         *  @param im La partie imaginaire de ce nombre complexe.
         *
         *  Crée un nombre complexe.
         */
        Complexe(const NonComplexe& re, const NonComplexe& im);

        /**
         *  @brief Crée un nombre complexe.
         *  @param re La partie réelle de ce nombre complexe.
         *  @param im La partie imaginaire de ce nombre complexe.
         *
         *  Crée un nombre complexe.
         */
        Complexe(const Nombre& re, const Nombre& im);

        /**
         *  @brief Détruit cette instance de la classe Complexe.
         *
         *  Détruit cette instance de la classe Complexe.
         */
        ~Complexe();

        /**
         *  @brief Calcule la somme de deux nombres complexe.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n L'autre nombre complexe.
         *  @return La somme de deux nombres complexe.
         *
         *  Calcule la somme de deux nombres complexe.
         */
        Nombre& addition(const Nombre& n) const;

        /**
         *  @brief Calcule la soustraction de deux nombres complexe.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n L'autre nombre complexe.
         *  @return La soustraction de deux nombres complexe.
         *
         *  Calcule la soustraction de deux nombres complexe.
         */
        Nombre& soustraction(const Nombre& n) const;

        /**
         *  @brief Calcule la multiplication de deux nombres complexe.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n L'autre nombre complexe.
         *  @return La multiplication de deux nombres complexe.
         *
         *  Calcule la multiplication de deux nombres complexe.
         */
        Nombre& multiplication(const Nombre& n) const;

        /**
         *  @brief Calcule la division de deux nombres complexe.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n L'autre nombre complexe.
         *  @return La division de deux nombres complexe.
         *
         *  Calcule la division de deux nombres complexe.
         */
        Nombre& division(const Nombre& n) const;

        /**
         *  @brief Calcule l'opposée d'un nombre complexe.
         *  Méthode virtuelle héritée et reimplémentée depuis la classe Nombre.
         *  @return L'opposée d'un nombre complexe.
         *
         *  Calcule l'opposée d'un nombre complexe.
         */
        Nombre& sign() const;

        /**
         *  @brief Calcule le carré d'un nombre complexe.
         *  Méthode virtuelle héritée et reimplémentée depuis la classe Nombre.
         *  @return Le carré d'un nombre complexe.
         *
         *  Calcule le carré d'un nombre complexe.
         */
        Nombre& sqr() const;

        /**
         *  @brief Calcule le cube d'un nombre complexe.
         *  Méthode virtuelle héritée et reimplémentée depuis la classe Nombre.
         *  @return Le cube d'un nombre complexe.
         *
         *  Calcule le cube d'un nombre complexe.
         */
        Nombre& cube() const;

        /**
         *  @brief Calcule le module d'un nombre complexe.
         *  @return Le module d'un nombre complexe.
         *
         *  Calcule le module d'un nombre complexe.
         */
        Nombre& module() const;

        /**
         *  @brief Retourne une chaine de caractères correspondant aux informations encapsulées par un nombre complexe.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Constante.
         *  @return Une chaine de caractères correspondant aux informations encapsulées par un nombre complexe.
         *
         *  Retourne une chaine de caractères correspondant aux informations encapsulées par un nombre complexe.
         */
        QString toString() const;

        /**
         *  @brief Crée une nouvelle instance de cette classe.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Constante.
         *  @return La nouvelle instance de cette classe.
         *
         *  Crée une nouvelle instance de cette classe.
         */
        inline virtual Complexe* clone() const;

};

inline Complexe* Complexe::clone() const {
    return new Complexe(*this);
}



#endif // COMPLEXE_H
