#include "LogSystem.h"
#include <QFile>
#include <QTextStream>

// ajoute un message de log dans un fichier, et écriture dans la console
void LogSystem::add(LogMessage log) {

    QTextStream cout(stdout, QIODevice::WriteOnly);
    QFile fichier("fichierDeLog.txt");

    // ouverture en mode Append, pour écrire à la fin.
    fichier.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream flux(&fichier);

    QString tmp = log.toString().c_str();

    // écriture du log dans le fichier
    flux << tmp << "\n";

    // éciture du log sur la console
    cout << "Ecriture dans le fichier de log : " << log.toString().c_str() << endl;
    fichier.close();
}

// ajoute un message de log dans un fichier, et écriture dans la console
void LogSystem::add(const QString& message, enumImportance importance ) {
    // ajout du log
    add(LogMessage(message,importance));
}
