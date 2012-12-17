/**
 * @file CalculatriceException.h
 * @brief Fichier header de la classe CalculatriceException
 * @author Tudor Luchiancenco & Kévin Njo Ewele
 */

#ifndef CALCULATRICEEXCEPTION_H
#define CALCULATRICEEXCEPTION_H

#include <QString>
#include <stdexcept>

/**
 *  @class CalculatriceException
 *  @brief  Classe permettant de gérer les exceptions (problèmes d'éxécution).
 *  { hérite de std::exception }
 */
class CalculatriceException : public std::exception {
    private:
        /**<
         *  Une chaine de caractères correspondant au message de l'exception.
         */
        QString mMessage;
    public:
        /**
         *  @brief Crée un objet de cette classe.
         *  @param Une chaine de caractères correspondant au message de l'exception.
         *
         *  Crée un objet de cette classe.
         */
        CalculatriceException(const QString& s) : mMessage(s) {}

        /**
         *  @brief Détruit cette instance de la classe.
         *
         *  Détruit cette instance de la classe.
         */
        virtual ~CalculatriceException() throw() {}

        /**
         *  @brief Retourne une chaine de caractères correspondant au message de l'exception.
         *  @return Une chaine de caractères correspondant au message de l'exception.
         *
         *  Retourne une chaine de caractères correspondant au message de l'exception.
         */
        inline const char* what() const throw();

        /**
         *  @brief Retourne une chaine de caractères correspondant au message de l'exception.
         *  @return Une chaine de caractères correspondant au message de l'exception.
         *
         *  Retourne une chaine de caractères correspondant au message de l'exception.
         */
        inline QString getMessage() const;

};

inline const char* CalculatriceException::what() const throw() {
    return mMessage.toStdString().c_str();
}

inline QString CalculatriceException::getMessage() const {
    return mMessage;
}

#endif // CALCULATRICEEXCEPTION_H
