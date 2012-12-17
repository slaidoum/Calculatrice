/**
 * @file LogMessage.h
 * @brief Fichier header de la classe LogMessage
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include <QString>
#include <ctime>

/**<
 *  Les degrés d'importance d'un message de log.
 */
enum enumImportance {FAIBLE, MOYENNE, ELEVEE};

/**
 *  @class LogMessage
 *  @brief Classe permettant de créer et manipuler des messages de log.
 */
class LogMessage {
    private:
        /**<
         *  Une chaine de caractères correspondant au message de log.
         */
        QString mMessage;

        /**<
         *  Un type enum correspondant à l'importance du message de log.
         */
        enumImportance mImportance;

        /**<
         *  Une date correspondant à la date d'émission du message de log.
         */
        struct tm mDate;

        /**
         *  @brief Retourne une chaine de caractères correspondant à l'importance du message de log.
         *  @return Une chaine de caractères correspondant à l'importance du message de log.
         *
         * Retourne une chaine de caractères correspondant à l'importance du message de log.
         */
        QString toStringImportance(enumImportance importance);

        /**
         *  @brief Retourne une chaine de caractères correspondant à la date d'émission du message de log.
         *  @return Une chaine de caractères correspondant à la date d'émission du message de log.
         *
         * Retourne une chaine de caractères correspondant à la date d'émission du message de log.
         */
        QString toStringDate(int i);

    public:
        /**
         *  @brief Crée un objet de cette classe.
         *  @param Une chaine de caractères correspondant au message de log.
         *  @param Un type enum correspondant à l'importance du message de log.
         *
         *  Crée un objet de cette classe.
         */
        LogMessage(const QString& message, enumImportance importance);

        /**
         *  @brief Retourne une chaine de caractères correspondant aux informations encapsulées par un message de log.
         *  @return Une chaine de caractères correspondant aux informations encapsulées par un message de log.
         *
         *  Retourne une chaine de caractères correspondant aux informations encapsulées par un message de log.
         */
        std::string toString();
};

#endif // LOGMESSAGE_H
