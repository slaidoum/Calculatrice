/**
 * @file Constante.h
 * @brief Fichier header de la classe Constante
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef CONSTANTE_H
#define CONSTANTE_H

#include <QTextStream>
#include "CalculatriceException.h"

/**
 *  @class Constante
 *  @brief Classe abstraite étant utilisée comme interface pour les classes qui en héritent.
 *
 *  Le Design Pattern Template Method est utilisé.
 */
class Constante {
    private:

    public:
        /**
         *  @brief Affiche les informations encapsulées par un nombre complexe.
         *
         *  Affiche les informations encapsulées par un nombre complexe.
         */
        void afficher() const;

        /**
         *  @brief Crée une nouvelle instance de cette classe.
         *  Méthode virtuelle pure.
         *  @return La nouvelle instance de cette classe.
         *
         *  Crée une nouvelle instance de cette classe.
         */
        virtual Constante* clone() const = 0;

        /**
         *  @brief Retourne une chaine de caractères correspondant aux informations encapsulées par une constante.
         *  Méthode virtuelle pure.
         *  @return Une chaine de caractères correspondant aux informations encapsulées par une constante.
         *
         *  Retourne une chaine de caractères correspondant aux informations encapsulées par une constante.
         */
        virtual QString toString() const = 0;
};

QTextStream& operator<<(QTextStream& f, const Constante& c);

#endif // CONSTANTE_H
