/**
 * @file Reel.h
 * @brief Fichier header de la classe Reel
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef REEL_H
#define REEL_H

#include "NonComplexe.h"

#include "Entier.h"
#include "Rationnel.h"
#include "Complexe.h"

class Entier;
class Rationnel;
class Complexe;

/**
 *  @class Reel
 *  @brief Classe permettant de créer et manipuler des constantes de type Reel.
 *  { hérite de NonComplexe }
 */
class Reel : public NonComplexe {
    private:
        /**<
         *  La valeur de ce nombre reel.
         */
        float mX;
    public:
        /**
         *  @brief Crée un nombre reel.
         *  @param x La valeur de ce nombre reel.
         *
         *  Crée un nombre reel de valeur donnée.
         */
        Reel(float x = 0) : mX(x) {}

        /**
         *  @brief Calcule la somme de ce nombre reel et d'un nombre.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n Un nombre.
         *  @return La somme de ce nombre reel et d'un nombre.
         *
         *  Calcule la somme de ce nombre reel et d'un nombre.
         */
        Nombre& addition(const Nombre& n) const;

        /**
         *  @brief Calcule la soustraction de ce nombre reel et d'un nombre.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n Un nombre.
         *  @return La soustraction de ce nombre reel et d'un nombre.
         *
         *  Calcule la soustraction de ce nombre reel et d'un nombre.
         */
        Nombre& soustraction(const Nombre& n) const;


        /**
         *  @brief Calcule la multiplication de ce nombre reel et d'un nombre.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n Un nombre.
         *  @return La multiplication de ce nombre reel et d'un nombre.
         *
         *  Calcule la multiplication de ce nombre reel et d'un nombre.
         */
        Nombre& multiplication(const Nombre& n) const;

        /**
         *  @brief Calcule la division de ce nombre reel et d'un nombre.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n Un nombre.
         *  @return La division de ce nombre reel et d'un nombre.
         *
         *  Calcule la division de ce nombre reel et d'un nombre.
         */
        Nombre& division(const Nombre& n) const;

        /**
         *  @brief Converti le nombre reel en un nombre entier.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe NonComplexe.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre entier.
         *
         *  Converti le nombre reel en un nombre entier.
         */
        NonComplexe& toEntier() const;

        /**
         *  @brief Converti le nombre reel en un nombre réel.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe NonComplexe.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre réel.
         *
         *  Converti le nombre reel en un nombre réel.
         */
        NonComplexe& toReel() const;

        /**
         *  @brief Converti le nombre reel en un nombre rationnel.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe NonComplexe.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre rationnel.
         *
         *  Converti le nombre reel en un nombre rationnel.
         */
        NonComplexe& toRationnel() const;

        /**
         *  @brief Converti le nombre reel en un nombre complexe.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe NonComplexe.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre complexe.
         *
         *  Converti le nombre reel en un nombre complexe.
         */
        NonComplexe& toComplexe() const;

        /**
         *  @brief Retourne le reel de ce nombre reel.
         *  @return Un reel.
         *
         *  Retourne le reel de ce nombre reel.
         */
        inline float getX() const;

        /**
         *  @brief Crée une nouvelle instance de cette classe.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Constante.
         *  @return La nouvelle instance de cette classe.
         *
         *  Crée une nouvelle instance de cette classe.
         */
        inline virtual Reel* clone() const;

        /**
         *  @brief Retourne une chaine de caractères correspondant aux informations encapsulées par un nombre reel.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Constante.
         *  @return Une chaine de caractères correspondant aux informations encapsulées par un nombre reel.
         *
         *  Retourne une chaine de caractères correspondant aux informations encapsulées par un nombre reel.
         */
        inline QString toString() const;
};

// getters
inline float Reel::getX() const {
    return mX;
}

// affichage
inline QString Reel::toString() const {
    QString str;
    str.setNum(mX);
    return str;
}

// clone
inline Reel* Reel::clone() const {
    return new Reel(*this);
}

#endif // REEL_H
