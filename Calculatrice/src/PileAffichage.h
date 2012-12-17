/**
 * @file PileAffichage.h
 * @brief Fichier header de la classe PileAffichage
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef PILEAFFICHAGE_H
#define PILEAFFICHAGE_H

#include <QStack>
#include <QString>

/**
 *  @class PileAffichage
 *  @brief Classe permettant de stocker les différentes constantes et résultats de calculs de l'utilisateur de la calculatrice, mais également les opérateurs.
 *  { hérite de QStack<QString> }
 *
 *  Le Design Pattern Singleton est utilisé.
 */
class PileAffichage: public QStack<QString> {
    private:
        /**<
         *  Un pointeur vers l'unique instance de cete classe.
         */
        static PileAffichage* mPile;

        /**
         *  @brief Crée un objet de cette classe.
         *
         *  Crée un objet de cette classe.
         */
        PileAffichage(){}

        /**
         *  @brief Crée un objet de cette classe.
         *  @param Le nouveau objet de cette classe.
         *
         *  Crée un objet de cette classe.
         */
        PileAffichage(const PileAffichage&);

        /**
         *  @brief Détruit l'unique instance de cette classe.
         *
         *  Détruit l'unique instance de cette classe.
         */
        ~PileAffichage(){}
    public:

        /**
         *  @brief Retourne l'unique instance de cette classe.
         *  @return Un pointeur vers l'unique instance de cette classe.
         *
         *  Retourne l'unique instance de cette classe.
         */
        static PileAffichage& getInstance();

        /**
         *  @brief Libère l'unique instance de cette classe.
         *
         *  Libère l'unique instance de cette classe.
         */
        static void libereInstance();
};

#endif // PILEAFFICHAGE_H
