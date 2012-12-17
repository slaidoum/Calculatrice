/**
 * @file Rationnel.h
 * @brief Fichier header de la classe Rationnel
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "NonComplexe.h"

#include "Entier.h"
#include "Reel.h"
#include "Complexe.h"

class Entier;
class Reel;
class Complexe;

/**
 *  @class Rationnel
 *  @brief Classe permettant de créer et manipuler des constantes de type Rationnel.
 *  { hérite de NonComplexe }
 */
class Rationnel : public NonComplexe{
    private:
        /**<
         *  Un pointeur vers le numérateur de ce nombre rationnel.
         */
        const Entier* mNum;
        /**<
         *  Un pointeur vers le dénominateur de ce nombre rationnel.
         */
        const Entier* mDen;
    public:
        /**
         *  @brief Crée un nombre rationnel.
         *  @param num Le numérateur de ce nombre rationnel.
         *  @param den Le dénominateur de ce nombre rationnel.
         *
         *  Crée un nombre rationnel.
         */
        Rationnel(const Entier& num, const Entier& den);

        /**
         *  @brief Crée un nombre rationnel.
         *  @param num Le numérateur de ce nombre rationnel.
         *  @param den Le dénominateur de ce nombre rationnel.
         *
         *  Crée un nombre rationnel.
         */
        Rationnel(const NonComplexe& num, const NonComplexe& den);

        /**
         *  @brief Crée un nombre rationnel.
         *  @param num Le numérateur de ce nombre rationnel.
         *  @param den Le dénominateur de ce nombre rationnel.
         *
         *  Crée un nombre rationnel.
         */
        Rationnel(unsigned int num = 0, unsigned int den = 1);

        /**
         *  @brief Détruit cette instance de la classe Rationnel.
         *
         *  Détruit cette instance de la classe Rationnel.
         */
        ~Rationnel();

        /**
         *  @brief Calcule la somme de ce nombre rationnel et d'un nombre.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n Un nombre.
         *  @return La somme de ce nombre rationnel et d'un nombre.
         *
         *  Calcule la somme de ce nombre rationnel et d'un nombre.
         */
        Nombre& addition(const Nombre& n) const;

        /**
         *  @brief Calcule la soustraction de ce nombre rationnel et d'un nombre.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n Un nombre.
         *  @return La soustraction de ce nombre rationnel et d'un nombre.
         *
         *  Calcule la soustraction de ce nombre rationnel et d'un nombre.
         */
        Nombre& soustraction(const Nombre& n) const;

        /**
         *  @brief Calcule la multiplication de ce nombre rationnel et d'un nombre.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n Un nombre.
         *  @return La multiplication de ce nombre rationnel et d'un nombre.
         *
         *  Calcule la multiplication de ce nombre rationnel et d'un nombre.
         */
        Nombre& multiplication(const Nombre& n) const;

        /**
         *  @brief Calcule la division de ce nombre rationnel et d'un nombre.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Nombre.
         *  @param n Un nombre.
         *  @return La division de ce nombre rationnel et d'un nombre.
         *
         *  Calcule la division de ce nombre rationnel et d'un nombre.
         */
        Nombre& division(const Nombre& n) const;

        /**
         *  @brief Converti le nombre rationnel en un nombre entier.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe NonComplexe.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre entier.
         *
         *  Converti le nombre rationnel en un nombre entier.
         */
        NonComplexe& toEntier() const;

        /**
         *  @brief Converti le nombre rationnel en un nombre réel.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe NonComplexe.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre réel.
         *
         *  Converti le nombre rationnel en un nombre réel.
         */
        NonComplexe& toReel() const;

        /**
         *  @brief Converti le nombre rationnel en un nombre rationnel.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe NonComplexe.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre rationnel.
         *
         *  Converti le nombre rationnel en un nombre rationnel.
         */
        NonComplexe& toRationnel() const;

        /**
         *  @brief Converti le nombre rationnel en un nombre complexe.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe NonComplexe.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre complexe.
         *
         *  Converti le nombre rationnel en un nombre complexe.
         */
        NonComplexe& toComplexe() const;

        /**
         *  @brief Simplifie un nombre rationnel si cela est possible.
         *
         *  Simplifie un nombre rationnel si cela est possible.
         */
        void simplifier();

        /**
         *  @brief Retourne le numérateur de ce nombre rationnel.
         *  @return Un nombre entier.
         *
         *  Retourne le numérateur de ce nombre rationnel.
         */
        inline const Entier& getNum() const;

        /**
         *  @brief Retourne le dénominateur de ce nombre rationnel.
         *  @return Un nombre entier.
         *
         *  Retourne le dénominateur de ce nombre rationnel.
         */
        inline const Entier& getDen() const;

        /**
         *  @brief Crée une nouvelle instance de cette classe.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Constante.
         *  @return La nouvelle instance de cette classe.
         *
         *  Crée une nouvelle instance de cette classe.
         */
        inline virtual Rationnel* clone() const;

        /**
         *  @brief Retourne une chaine de caractères correspondant aux informations encapsulées par un nombre rationnel.
         *  Méthode virtuelle pure héritée et implémentée depuis la classe Constante.
         *  @return Une chaine de caractères correspondant aux informations encapsulées par un nombre rationnel.
         *
         *  Retourne une chaine de caractères correspondant aux informations encapsulées par un nombre rationnel.
         */
        QString toString() const;
};

// pgcd
Entier pgcd(const Entier& a, const Entier& b);

// getters
inline const Entier& Rationnel::getNum() const {
    return *mNum;
}

inline const Entier& Rationnel::getDen() const {
    return *mDen;
}

// clone
inline Rationnel* Rationnel::clone() const {
    return new Rationnel(*this);
}

#endif // RATIONNEL_H
