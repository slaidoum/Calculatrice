/**
 * @file LogSystem.h
 * @brief Fichier header de la classe LogSystem
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#include "LogMessage.h"
#include <QString>

/**
 *  @class LogSystem
 *  @brief Classe permettant d'écrire des messages de log dans un fichier spécifique.
 */
class LogSystem {
    private:
    public:
        /**
         *  @brief Ajoute un message de log dans un fichier spécifique, et l'écrit dans la console.
         *  @param log Un message de log.
         *
         *  Ajoute un message de log dans un fichier spécifique, et l'écrit dans la console.
         */
        static void add(LogMessage log);

        /**
         *  @brief Ajoute un message de log dans un fichier spécifique, et l'écrit dans la console.
         *  @param message Une chaine de caractères correspondant au message de log.
         *  @param importance Un type enum correspondant à l'importance du message de log.
         *
         *  Ajoute un message de log dans un fichier spécifique, et l'écrit dans la console.
         */
        static void add(const QString& message, enumImportance importance);
};

#endif // LOGSYSTEM_H
