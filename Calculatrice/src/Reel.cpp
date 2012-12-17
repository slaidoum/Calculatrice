#include "Reel.h"
#include <cmath>
#include <QStringList>

// méthodes VP héritées et implémentées depuis la classe Nombre
Nombre& Reel::addition(const Nombre& n) const {
    // Nombre -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
    if (ptEntier == 0) {
        // Nombre -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&n);
        if (ptReel == 0) {
            // Nombre -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
            if (ptRationnel == 0) {
                throw CalculatriceException("Reel : addition : Impossible d'effectuer le dynamic cast!");
            } else { // Reel + Rationnel
                NonComplexe& r = this->toRationnel();
                Nombre& ref = r.addition((Nombre&)*ptRationnel);
                return(ref);
           }
        } else { // Reel + Reel
            Reel* res = new Reel(mX + ptReel->getX());
            Nombre& ref = *res;
            return(ref);
        }
    } else { // Reel + Entier
        Nombre& ref = ptEntier->addition(*this);
        return(ref);
    }
}
Nombre& Reel::soustraction(const Nombre& n) const {
    // Nombre -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
    if (ptEntier == 0) {
        // Nombre -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&n);
        if (ptReel == 0) {
            // Nombre -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
            if (ptRationnel == 0) {
                throw CalculatriceException("Reel : soustraction : Impossible d'effectuer le dynamic cast!");
            } else { //  Reel - Rationnel
                Nombre& ref = toRationnel().soustraction(*ptRationnel);
                return(ref);
           }
        } else { // Reel - Reel
            Reel* res = new Reel(mX - ptReel->getX());
            Nombre& ref = *res;
            return(ref);
        }
    } else { // Reel - Entier
        Nombre& ref = ptEntier->soustraction(*this).sign();
        return(ref);
    }
}
Nombre& Reel::multiplication(const Nombre& n) const {
    // Nombre -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
    if (ptEntier == 0) {
        // Nombre -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&n);
        if (ptReel == 0) {
            // Nombre -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
            if (ptRationnel == 0) {
                throw CalculatriceException("Reel : soustraction : Impossible d'effectuer le dynamic cast!");
            } else { //  Reel * Rationnel
                Reel res(mX * ptRationnel->getNum().getX());
                Nombre& ref = res.toRationnel();
                return(ref);
           }
        } else { // Reel * Reel
            Reel* res= new Reel(mX * ptReel->getX());
            Nombre& ref = *res;
            return(ref);
        }
    } else { // Reel * Entier
        Nombre& ref = ptEntier->multiplication(*this);
        return(ref);
    }
}
Nombre& Reel::division(const Nombre& n) const {
    // Nombre -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
    if (ptEntier == 0) {
        // Nombre -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&n);
        if (ptReel == 0) {
            // Nombre -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
            if (ptRationnel == 0) {
                throw CalculatriceException("Reel : division : Impossible d'effectuer le dynamic cast!");
            } else { //  Reel / Rationnel
                Nombre& ref = this->toRationnel().division(*ptRationnel);
                return(ref);
           }
        } else { // Reel / Reel
            if (ptReel->getX() == 0) {
                throw CalculatriceException("Reel : division : Division par 0 !");
            }
            Reel* res = new Reel(this->mX / ptReel->getX());
            Nombre& ref = *res;
            return(ref);
        }
    } else { // Reel / Entier
        Nombre& pt = ptEntier->division(*this);
        NonComplexe* pt2 = dynamic_cast<NonComplexe *>(&pt);
        NonComplexe& res = pt2->inv();
        Nombre& ref = (Nombre&)(res);
        return(ref);
    }
}


// méthodes VP implémentées depuis la classe NonComplexe
NonComplexe& Reel::toEntier() const {
    // Reel -> Entier
    Entier* res= new Entier(getX());
    NonComplexe& ref = (NonComplexe&)*res;
    return (ref);
}

NonComplexe& Reel::toReel() const {
    NonComplexe& ref = (NonComplexe&)*this;
    return (ref);
}


NonComplexe& Reel::toRationnel() const {
    // Reel -> Rationnel
    QString str;
    str.setNum(mX);
    QStringList list = str.split(".");
    int nbdec = list.value(1).count();
    Rationnel* res= new Rationnel(mX * std::pow((int)10,nbdec), std::pow((int)10,nbdec));
    res->simplifier();
    NonComplexe& ref = *res;
    return (ref);
}

NonComplexe& Reel::toComplexe() const {
    // Reel -> Complexe
    const Nombre& re = *(new Entier(getX()));
    const Nombre& im = *(new Entier(0));
    Complexe* res = new Complexe(re,im);
    NonComplexe& ref = (NonComplexe&)*res;
    return (ref);
}
