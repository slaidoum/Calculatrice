#include "Constante.h"

void Constante::afficher() const {
    QTextStream cout(stdout, QIODevice::WriteOnly);
    cout << this->toString();
}

QTextStream& operator<<(QTextStream& f, const Constante& c) {
    c.afficher();
    return f;
}
