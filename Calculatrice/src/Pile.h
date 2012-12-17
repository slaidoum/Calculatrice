/**
 * @file Pile.h
 * @brief Fichier header de la classe Pile
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef PILE_H
#define PILE_H

#include "QStack"
#include "Constante.h"

/**
 *  @class Pile
 *  @brief Classe permettant de stocker les différentes constantes et résultats de calculs de l'utilisateur de la calculatrice.
 *  { hérite de QStack<Constante*> }
 *
 *  Le Design Pattern Singleton est utilisé.
 */
class Pile: public QStack<Constante*> {
    private:
        /**<
         *  Un pointeur vers l'unique instance de cete classe.
         */
        static Pile* mPile;

        /**
         *  @brief Crée un objet de cette classe.
         *
         *  Crée un objet de cette classe.
         */
        Pile(){}

        /**
         *  @brief Crée un objet de cette classe.
         *  @param Le nouveau objet de cette classe.
         *
         *  Crée un objet de cette classe.
         */
        Pile(const Pile&);

        /**
         *  @brief Détruit l'unique instance de cette classe.
         *
         *  Détruit l'unique instance de cette classe.
         */
        ~Pile(){}
    public:
        /**
         *  @brief Retourne l'unique instance de cette classe.
         *  @return Un pointeur vers l'unique instance de cette classe.
         *
         *  Retourne l'unique instance de cette classe.
         */
        static Pile& getInstance();

        /**
         *  @brief Libère l'unique instance de cette classe.
         *
         *  Libère l'unique instance de cette classe.
         */
        static void libereInstance();

        /**
         *  @brief Effectue le swap entre les valeurs de la pile se trouvant aux positions x et y.
         *  @param x Premier indice à swaper
         *  @param y Second indice à swaper
         *
         *  Effectue le swap entre les valeurs de la pile se trouvant aux positions x et y.
         */
        void swap(int x, int y);

        /**
         *  @brief Effectue la somme des x premiers élements de la pile.
         *  @param x Nombre d'élements de la pile à sommer.
         *
         *  Effectue la somme des x premiers élements de la pile.
         */
        void sum(int x);

        /**
         *  @brief Effectue la moyenne des x premiers élements de la pile.
         *  @param x Nombre d'élements de la pile pour lesquels il faut faire la moyenne.
         *
         *  Effectue la moyenne des x premiers élements de la pile.
         */
        void mean(int x);

        /**
         *  @brief Vide la pile.
         *
         *  Vide la pile.
         */
        void clearPile();

        /**
         *  @brief Duplique le dernier élement de la pile.
         *
         *  Duplique le dernier élement de la pile.
         */
        void dup();

        /**
         *  @brief Supprime le dernier élement de la pile.
         *
         *  Supprime le dernier élement de la pile.
         */
        void drop();

        /**
         *  @brief Sauvegarde l'état de la pile dans un fichier spécifique.
         *  @param nbEltsPile Le nombre d'élements de la pile à afficher.
         *
         *  Sauvegarde l'état de la pile dans un fichier spécifique.
         */
        void sauvegarderDansFichier(int nbEltsPile) const;

        /**
         *  @brief Charge l'état de la pile depuis un fichier spécifique.
         *  @return nbEltsPile Le nombre d'élements de la pile à afficher.
         *
         *  Charge l'état de la pile depuis un fichier spécifique.
         */
        int chargerDepuisFichier(); // retourne le nb elts pile à afficher

        /**
         *  @brief Crée une nouvelle instance de cette classe.
         *  @return La nouvelle instance de cette classe.
         *
         *  Crée une nouvelle instance de cette classe.
         */
        Pile* clone() const;

        /**
        *  @brief Retourne la pile courante.
        *  @return La pile courante.
        *
        *  Retourne la pile courante.
        */
        Pile* getPile() const {
            return mPile;
        }

        /**
         *  @class Memento
         *  @brief Classe permettant de toujours garder en mémoire une pile donnée.
         *
         *  Classe permettant de toujours garder en mémoire une pile donnée.
         */
        class Memento{
            private:
                /**<
                 *  Un pointeur vers une instance de pile.
                 */
                Pile* mPileCourante;
            public:
                /**
                 *  @brief Crée un objet de cette classe.
                 *  @param Un pointeur vers une pile.
                 *
                 *  Crée un objet de cette classe.
                 */
                Memento(const Pile* pile): mPileCourante(pile->clone()) {}

                /**
                *  @brief Retourne la pile courante.
                *  @return La pile courante.
                *
                *  Retourne la pile courante.
                */
                Pile* getPileMemento() const {
                    return mPileCourante;
                }
        };

        /**
         *  @brief Retourne une instance d'objet de type Memento encapsulant une instance de pile.
         *  @return Un pointeur vers un objet de type Memento.
         *
         *  Retourne une instance d'objet de type Memento encapsulant une instance de pile.
         */
        Memento* sauvegarderPileCourante() const {
            return new Memento(mPile);
        }

        /**
         *  @brief Charge la pile courante par la pile encapsulée dans l'objet de type Memento
         *  @param m Un pointeur vers un objet de type Memento.
         *
         *  Charge la pile courante par la pile encapsulée dans l'objet de type Memento
         */
        void chargerUnePile(const Memento* m){
            mPile = m->getPileMemento();
        }

};

#endif // PILE_H
