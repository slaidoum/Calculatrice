#include "LogMessage.h"
#include "CalculatriceException.h"

LogMessage::LogMessage(const QString& message, enumImportance importance) : mMessage(message), mImportance(importance) {
    time_t now;
    time(&now);
    mDate = *localtime(&now);
}

QString LogMessage::toStringDate(int i) {
    QString s = "";
    if (i >= 0 && i < 10) {
        s = "0";
    }
    s.append(QString::number(i));
    return s;
}

QString LogMessage::toStringImportance(enumImportance importance) {
    QString s = "";
    switch (importance) {
        case FAIBLE: {
            s = "Faible";
            break;
        }
        case MOYENNE: {
            s = "Moyenne";
            break;
        }
        case ELEVEE: {
            s = "Elevée";
            break;
        }
        default : {
            throw CalculatriceException("LogMessage : Niveau d'importance inconnu !");
            break;
        }
    }
    return s;
}

std::string LogMessage::toString() {
    QString tmp = "";

    tmp.append("|").append(toStringImportance(mImportance)).append("|, |").append(toStringDate(mDate.tm_year + 1900));
    tmp.append("-");
    tmp.append(toStringDate(mDate.tm_mon + 1));
    tmp.append("-");
    tmp.append(toStringDate(mDate.tm_mday));
    tmp.append(" ");
    tmp.append(toStringDate(mDate.tm_hour));
    tmp.append(":");
    tmp.append(toStringDate(mDate.tm_min));
    tmp.append(":");
    tmp.append(toStringDate(mDate.tm_sec));
    tmp.append("|, ");
    tmp.append(mMessage);
    return tmp.toStdString();
}
