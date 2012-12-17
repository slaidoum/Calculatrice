/**
 * @file NonComplexe.h
 * @brief Fichier header de la classe NonComplexe
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef NONCOMPLEXE_H
#define NONCOMPLEXE_H

#include "Nombre.h"

/**
 *  @class NonComplexe
 *  @brief Classe permettant de créer et manipuler des constantes de type NonComplexe, fourni également une interface aux classes qui en héritent.
 *  { hérite de Nombre }
 */
class NonComplexe : public Nombre  {
    private:

    public:

        /**
         *  @brief Calcule la somme de deux nombres.
         *  Méthode virtuelle pure héritée depuis la classe Nombre.
         *  @param n L'autre nombre.
         *
         *  Calcule la somme de deux nombres.
         */
        virtual Nombre& addition(const Nombre& n) const = 0;

        /**
         *  @brief Calcule la soustraction de deux nombres.
         *  Méthode virtuelle pure héritée depuis la classe Nombre.
         *  @param n L'autre nombre.
         *
         *  Calcule la soustraction de deux nombres.
         */
        virtual Nombre& soustraction(const Nombre& n) const = 0;

        /**
         *  @brief Calcule la multiplication de deux nombres.
         *  Méthode virtuelle pure héritée depuis la classe Nombre.
         *  @param n L'autre nombre.
         *
         *  Calcule la multiplication de deux nombres.
         */
        virtual Nombre& multiplication(const Nombre& n) const = 0;

        /**
         *  @brief Calcule la division de deux nombres.
         *  Méthode virtuelle pure héritée depuis la classe Nombre.
         *  @param n L'autre nombre.
         *
         *  Calcule la division de deux nombres.
         */
        virtual Nombre& division(const Nombre& n) const = 0;

        /**
         *  @brief Converti le nombre non complexe en un nombre non complexe.
         *  Méthode virtuelle pure.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre non complexe.
         *
         *  Converti le nombre non complexe en un nombre non complexe.
         */
        virtual NonComplexe& toEntier() const = 0;

        /**
         *  @brief Converti le nombre non complexe en un nombre non complexe.
         *  Méthode virtuelle pure.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre non complexe.
         *
         *  Converti le nombre non complexe en un nombre non complexe.
         */
        virtual NonComplexe& toReel() const = 0;

        /**
         *  @brief Converti le nombre non complexe en un nombre non complexe.
         *  Méthode virtuelle pure.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre non complexe.
         *
         *  Converti le nombre non complexe en un nombre non complexe.
         */
        virtual NonComplexe& toRationnel() const = 0;

        /**
         *  @brief Converti le nombre non complexe en un nombre non complexe.
         *  Méthode virtuelle pure.
         *  @return Une référence vers un nombre non complexe emmagasinant en réalité un nombre non complexe.
         *
         *  Converti le nombre non complexe en un nombre non complexe.
         */
        virtual NonComplexe& toComplexe() const = 0;

        /**
         *  @brief Calcule le sinus du nombre non complexe.
         *  @return Une référence vers un nombre non complexe emmagasinant le résultat du calcul.
         *
         *  Calcule le sinus du nombre non complexe.
         */
        NonComplexe& sin() const;

        /**
         *  @brief Calcule le cosinus du nombre non complexe.
         *  @return Une référence vers un nombre non complexe emmagasinant le résultat du calcul.
         *
         *  Calcule le cosinus du nombre non complexe.
         */
        NonComplexe& cos() const;

        /**
         *  @brief Calcule la tangente du nombre non complexe.
         *  @return Une référence vers un nombre non complexe emmagasinant le résultat du calcul.
         *
         *  Calcule la tangente du nombre non complexe.
         */
        NonComplexe& tan() const;

        /**
         *  @brief Calcule le sinus hiperbolique du nombre non complexe.
         *  @return Une référence vers un nombre non complexe emmagasinant le résultat du calcul.
         *
         *  Calcule le sinus du nombre non complexe.
         */
        NonComplexe& sinh() const;

        /**
         *  @brief Calcule le cosinus hiperbolique du nombre non complexe.
         *  @return Une référence vers un nombre non complexe emmagasinant le résultat du calcul.
         *
         *  Calcule le cosinus hiperbolique du nombre non complexe.
         */
        NonComplexe& cosh() const;

        /**
         *  @brief Calcule la tangente hiperbolique du nombre non complexe.
         *  @return Une référence vers un nombre non complexe emmagasinant le résultat du calcul.
         *
         *  Calcule la tangente hiperbolique du nombre non complexe.
         */
        NonComplexe& tanh() const;

        /**
         *  @brief Calcule le logarithme du nombre non complexe.
         *  @return Une référence vers un nombre non complexe emmagasinant le résultat du calcul.
         *
         *  Calcule le logarithme du nombre non complexe.
         */
        NonComplexe& ln() const;

        /**
         *  @brief Calcule l'inverse du nombre non complexe.
         *  @return Une référence vers un nombre non complexe emmagasinant le résultat du calcul.
         *
         *  Calcule l'inverse du nombre non complexe.
         */
        NonComplexe& inv() const;

        /**
         *  @brief Calcule le logarithme du nombre non complexe.
         *  @return Une référence vers un nombre non complexe emmagasinant le résultat du calcul.
         *
         *  Calcule le logarithme du nombre non complexe.
         */
        NonComplexe& log() const;

        /**
         *  @brief Calcule la racine carrée du nombre non complexe.
         *  @return Une référence vers un nombre non complexe emmagasinant le résultat du calcul.
         *
         *  Calcule le racine carrée du nombre non complexe.
         */
        NonComplexe& sqrt() const;

        /**
         *  @brief Calcule la puissance passée en parametre du nombre non complexe.
         *  @param Une puissance.
         *  @return Une référence vers un nombre non complexe emmagasinant le résultat du calcul.
         *
         *  Calcule la puissance passée en parametre du nombre non complexe.
         */
        NonComplexe& pow(const NonComplexe& puiss) const;

        /**
         *  @brief Crée une nouvelle instance de cette classe.
         *  Méthode virtuelle pure héritée depuis la classe Constante.
         *  @return La nouvelle instance de cette classe.
         *
         *  Crée une nouvelle instance de cette classe.
         */
        inline virtual NonComplexe* clone() const = 0;

        /**
         *  @brief Retourne une chaine de caractères correspondant aux informations encapsulées par un nombre non complexe.
         *  Méthode virtuelle pure héritée depuis la classe Constante.
         *  @return Une chaine de caractères correspondant aux informations encapsulées par un nombre non complexe.
         *
         *  Retourne une chaine de caractères correspondant aux informations encapsulées par un nombre non complexe.
         */
        virtual QString toString() const = 0;

};

#endif // NONCOMPLEXE_H
