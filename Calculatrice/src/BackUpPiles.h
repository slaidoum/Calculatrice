/**
 * @file BackUpPiles.h
 * @brief Fichier header de la classe BackUpPiles
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef BACKUPPILES_H
#define BACKUPPILES_H

#include "Pile.h"
#include <QMessageBox>

/**
 *  @class BackUpPiles
 *  @brief  Classe permettant de garder en mémoire une liste des piles (pointeurs vers des objets de type Memento)
 *  ce qui permet donc de réaliser le Undo et le Redo de la pile.
 *
 *  Le Design Pattern Singleton est utilisé.
 */
class BackUpPiles {
        private:
            /**<
             *  Un pointeur vers l'unique instance de cete classe.
             */
            static BackUpPiles* mBackUpPiles;

            /**<
             *  Un pointeur vers des objets de type Memento (des piles).
             */
            QStack<Pile::Memento*> mListePiles;

            /**<
             *  Un index : pour savoir où l'on est dans la liste des piles.
             */
            static unsigned int mIndexListe;

            /**
             *  @brief Crée un objet de cette classe.
             *
             *  Crée un objet de cette classe.
             */
            BackUpPiles(){}

            /**
             *  @brief Crée un objet de cette classe.
             *  @param Le nouveau objet de cette classe.
             *
             *  Crée un objet de cette classe.
             */
            BackUpPiles(const BackUpPiles&){}

            /**
             *  @brief Détruit l'unique instance de cette classe.
             *
             *  Détruit l'unique instance de cette classe.
             */
            ~BackUpPiles(){}

        public:
            /**
             *  @brief Retourne l'unique instance de cette classe.
             *  @return Un pointeur vers l'unique instance de cette classe.
             *
             *  Retourne l'unique instance de cette classe.
             */
            static BackUpPiles* getInstance();

            /**
             *  @brief Libère l'unique instance de cette classe.
             *
             *  Libère l'unique instance de cette classe.
             */
            static void libereInstance();

            /**
             *  @brief Ajoute une nouvelle instance de pile dans la liste des piles.
             *  @param Un pointeur vers un objet de type Memento contenant la nouvelle instance de pile.
             *
             *  Ajoute une nouvelle instance de pile dans la liste des piles.
             */
            void ajouterNouvellePile(Pile::Memento* pile);

            /**
             *  @brief Retourne la pile précédente, celle se trouvant à l'index mIndexListe. { UNDO }
             *  @return Un pointeur vers un objet de type Memento correspondant contenant la pile précédente.
             *
             *  Retourne la pile précédente, celle se trouvant à l'index mIndexListe.
             */
            const Pile::Memento* getDernierePile() const;

            /**
             *  @brief Retourne la pile suivante, celle se trouvant à l'index mIndexListe. { REDO }
             *  @return Un pointeur vers un objet de type Memento correspondant contenant la pile suivante.
             *
             *  Retourne la pile suivante, celle se trouvant à l'index mIndexListe.
             */
            const Pile::Memento* getPileSuivante() const;

            /**
             *  @brief Libère la liste des piles et initialise l'index à 0.
             *
             *  Libère la liste des piles et initialise l'index à 0.
             */
            void clearBackUpPiles();
    };

#endif // BACKUPPILES_H
