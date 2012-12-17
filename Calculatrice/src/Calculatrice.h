/**
 * @file Calculatrice.h
 * @brief Fichier header de la classe Calculatrice
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QString>
#include <QRegExp>

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"


enum enumType {ENTIER, REEL, RATIONNEL, COMPLEXE, EXPRESSION, OPERATEUR};

/**
 *  @class Calculatrice
 *  @brief Classe permettant de créer les différentes types de constantes et de traiter les opérations.
 *
 *  Le Design Pattern Singleton est utilisé.
 */
class Calculatrice {
    private:
        /**<
         *  Un pointeur vers l'unique instance de cete classe Calculatrice.
         */
        static Calculatrice* mCalculatrice;

        /**
         *  @brief Crée un objet de cette classe.
         *
         *  Crée un objet de cette classe.
         */
        Calculatrice() {}

        /**
         *  @brief Crée un objet de cette classe.
         *  @param Le nouveau objet de cette classe.
         *
         *  Crée un objet de cette classe.
         */
        Calculatrice(const Calculatrice&) {}

        /**
         *  @brief Détruit cette instance de la classe.
         *
         *  Détruit cette instance de la classe.
         */
        ~Calculatrice(){}

    public:
        /**
         *  @brief Retourne l'unique instance de cette classe.
         *  @return Un pointeur vers l'unique instance de cette classe.
         *
         *  Retourne l'unique instance de cette classe.
         */
        static Calculatrice& getInstance();

        /**
         *  @brief Libère l'unique instance de cette classe.
         *
         *  Libère l'unique instance de cette classe.
         */
        static void libereInstance();

        /**
         *  @brief Fabrique une constante et l'empile ou dans le cas d'un opérateur, on le traite.
         *  @param La constante ou l'opérateur sous la forme d'une chaine de caractères.
         *  @param Le type qui déterminera le type du futur objet à fabriquer et son traitement.
         *
         *  Fabrique une constante et l'empile ou dans le cas d'un opérateur, on le traite.
         */
        void fabriquer(const QString& text, enumType type) const;

        /**
         *  @brief Détermine si une chaine de caractères est un opérateur.
         *  @param La chaine de caractères à examiner.
         *
         *  Détermine si une chaine de caractères est un opérateur.
         */
        bool isOperateur(const QString& s) const;

        /**
         *  @brief Détermine si une chaine de caractères est une constante.
         *  @param La chaine de caractères à examiner.
         *
         *  Détermine si une chaine de caractères est une constante.
         */
        bool isConstante(const QString& s) const;

        /**
         *  @brief Détermine si une chaine de caractères est un entier.
         *  @param La chaine de caractères à examiner.
         *
         *  Détermine si une chaine de caractères est un entier.
         */
        bool isEntier(const QString& s) const;

        /**
         *  @brief Détermine si une chaine de caractères est un réel.
         *  @param La chaine de caractères à examiner.
         *
         *  Détermine si une chaine de caractères est un réel.
         */
        bool isReel(const QString& s) const;

        /**
         *  @brief Détermine si une chaine de caractères est un rationnel.
         *  @param La chaine de caractères à examiner.
         *
         *  Détermine si une chaine de caractères est un rationnel.
         */
        bool isRationnel(const QString& s) const;

        /**
         *  @brief Détermine si une chaine de caractères est un complexe.
         *  @param La chaine de caractères à examiner.
         *
         *  Détermine si une chaine de caractères est un complexe.
         */
        bool isComplexe(const QString& s) const;

        /**
         *  @brief Détermine si une chaine de caractères est un opérateur binaire.
         *  @param La chaine de caractères à examiner.
         *
         *  Détermine si une chaine de caractères est un opérateur binaire.
         */
        bool isOperateurBinaire(const QString& s) const;

        /**
         *  @brief Détermine si une chaine de caractères est un opérateur unaire.
         *  @param La chaine de caractères à examiner.
         *
         *  Détermine si une chaine de caractères est un opérateur unaire.
         */
        bool isOperateurUnaire(const QString& s) const;

        /**
         *  @brief Détermine si une chaine de caractères est un opérateur ne nécessitant aucun aucun argument.
         *  @param La chaine de caractères à examiner.
         *
         *  Détermine si une chaine de caractères est un opérateur ne nécessitant aucun aucun argument.
         */
        bool isOperateurSansArg(const QString& s) const;

};

#endif
