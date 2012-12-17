/**
 * @file Entier.h
 * @brief Fichier header de la classe Entier
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef ENTIER_H
#define ENTIER_H

#include "NonComplexe.h"

#include "Rationnel.h"
#include "Reel.h"
#include "Complexe.h"

class Reel;
class Rationnel;
class Complexe;

/**
 *  @class Entier
 *  @brief Classe permettant de créer et manipuler des constantes de type Entier.
 *  { hérite de NonComplexe }
 */
class Entier : public NonComplexe {
    private:
        /**<
         *  La valeur de ce nombre entier.
         */
        int mX;
    public:
        /**
         *  @brief Crée un nombre entier.
         *  @param x La valeur de ce nombre entier.
         *
         *  Crée un nombre entier de valeur donnée.
         */
        Entier(int x = 0) : mX(x) {}

        /**
         *  @brief Calcule la somme de ce nombre entier et d'un nombre.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n Un nombre.
         *  @return La somme de ce nombre entier et d'un nombre.
         *
         *  Calcule la somme de ce nombre entier et d'un nombre.
         */
        Nombre& addition(const Nombre& n) const;

        /**
         *  @brief Calcule la soustraction de ce nombre entier et d'un nombre.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n Un nombre.
         *  @return La soustraction de ce nombre entier et d'un nombre.
         *
         *  Calcule la soustraction de ce nombre entier et d'un nombre.
         */
        Nombre& soustraction(const Nombre& n) const;

        /**
         *  @brief Calcule la multiplication de ce nombre entier et d'un nombre.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n Un nombre.
         *  @return La multiplication de ce nombre entier et d'un nombre.
         *
         *  Calcule la multiplication de ce nombre entier et d'un nombre.
         */
        Nombre& multiplication(const Nombre& n) const;

        /**
         *  @brief Calcule la division de ce nombre entier et d'un nombre.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n Un nombre.
         *  @return La division de ce nombre entier et d'un nombre.
         *
         *  Calcule la division de ce nombre entier et d'un nombre.
        */
        Nombre& division(const Nombre& n) const;

        /**
         *  @brief Converti le nombre entier en un nombre entier.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe NonComplexe.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre entier.
         *
         *  Converti le nombre entier en un nombre entier.
         */
        NonComplexe& toEntier() const;

        /**
         *  @brief Converti le nombre entier en un nombre réel.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe NonComplexe.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre réel.
         *
         *  Converti le nombre entier en un nombre réel.
         */
        NonComplexe& toReel() const;

        /**
         *  @brief Converti le nombre entier en un nombre rationnel.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe NonComplexe.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre rationnel.
         *
         *  Converti le nombre entier en un nombre rationnel.
         */
        NonComplexe& toRationnel() const;

        /**
         *  @brief Converti le nombre entier en un nombre complexe.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe NonComplexe.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre complexe.
         *
         *  Converti le nombre entier en un nombre complexe.
         */
        NonComplexe& toComplexe() const;

        /**
         *  @brief Calcule le module de ce nombre entier.
         *  @param Une référence constante vers un nombre entier correspondant au diviseur.
         *  @return Une référence vers le modulo de ce nombre entier.
         *
         *  Calcule le module de ce nombre entier.
         */
        Entier& mod(const Entier& e);

        /**
         *  @brief Calcule la factorielle de ce nombre entier.
         *  @return Une référence vers la factorielle de ce nombre entier.
         *
         *  Calcule la factorielle de ce nombre entier.
         */
        Entier& fact();

        /**
         *  @brief Retourne l'entier de ce nombre entier.
         *  @return Un entier.
         *
         *  Retourne l'entier de ce nombre entier.
         */
        inline int getX() const;

        /**
         *  @brief Crée une nouvelle instance de cette classe.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Constante.
         *  @return La nouvelle instance de cette classe.
         *
         *  Crée une nouvelle instance de cette classe.
         */
        inline virtual Entier* clone() const;

        /**
         *  @brief Retourne une chaine de caractères correspondant aux informations encapsulées par un nombre entier.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Constante.
         *  @return Une chaine de caractères correspondant aux informations encapsulées par un nombre entier.
         *
         *  Retourne une chaine de caractères correspondant aux informations encapsulées par un nombre entier.
         */
        inline QString toString() const;
};

// getters
inline int Entier::getX() const {
    return mX;
}


// affichage
inline QString Entier::toString() const {
    QString str;
    str.setNum(mX);
    return str;
}

// clone
inline Entier* Entier::clone() const {
    return new Entier(*this);
}

// factorielle
int factorielle(int n);

#endif // ENTIER_H
