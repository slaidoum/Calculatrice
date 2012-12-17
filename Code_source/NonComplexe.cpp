#include "NonComplexe.h"

#include "Reel.h"
#include <cmath>

// méthodes membres de cette classe (communes aux entiers, réels et rationnels)
NonComplexe& NonComplexe::sin() const {
    const Reel* ptReel = dynamic_cast<const Reel*>(&(this->toReel()));
    if (ptReel == 0) {
        throw CalculatriceException("NonComplexe : sin : Impossible d'effectuer le dynamic cast!");
    }
    Reel* res = new Reel(std::sin(ptReel->getX()));
    NonComplexe& ref = *res;
    return (ref);
}

NonComplexe& NonComplexe::cos() const {
    const Reel* ptReel = dynamic_cast<const Reel*>(&(this->toReel()));
    if (ptReel == 0) {
        throw CalculatriceException("NonComplexe : cos : Impossible d'effectuer le dynamic cast!");
    }
    Reel* res = new Reel(std::cos(ptReel->getX()));
    NonComplexe& ref = *res;
    return (ref);
}
NonComplexe& NonComplexe::tan() const {
    const Reel* ptReel = dynamic_cast<const Reel*>(&(this->toReel()));
    if (ptReel == 0) {
        throw CalculatriceException("NonComplexe : tan : Impossible d'effectuer le dynamic cast!");
    }
    Reel* res = new Reel(std::tan(ptReel->getX()));
    NonComplexe& ref = *res;
    return (ref);
}

NonComplexe& NonComplexe::sinh() const {
    const Reel* ptReel = dynamic_cast<const Reel*>(&(this->toReel()));
    if (ptReel == 0) {
        throw CalculatriceException("NonComplexe : sinh : Impossible d'effectuer le dynamic cast!");
    }
    Reel* res = new Reel(std::sinh(ptReel->getX()));
    NonComplexe& ref = *res;
    return (ref);
}

NonComplexe& NonComplexe::cosh() const {
    const Reel* ptReel = dynamic_cast<const Reel*>(&(this->toReel()));
    if (ptReel == 0) {
        throw CalculatriceException("NonComplexe : cosh : Impossible d'effectuer le dynamic cast!");
    }
    Reel* res = new Reel(std::cosh(ptReel->getX()));
    NonComplexe& ref = *res;
    return (ref);
}

NonComplexe& NonComplexe::tanh() const {
    const Reel* ptReel = dynamic_cast<const Reel*>(&(this->toReel()));
    if (ptReel == 0) {
        throw CalculatriceException("NonComplexe : tanh : Impossible d'effectuer le dynamic cast!");
    }
    Reel* res = new Reel(std::tanh(ptReel->getX()));
    NonComplexe& ref = *res;
    return (ref);
}

NonComplexe& NonComplexe::ln() const {
    const Reel* ptReel = dynamic_cast<const Reel*>(&(this->toReel()));
    if (ptReel == 0) {
        throw CalculatriceException("NonComplexe : ln : Impossible d'effectuer le dynamic cast!");
    }
    Reel* res = new Reel(std::log(ptReel->getX()));
    NonComplexe& ref = *res;
    return (ref);
}

NonComplexe& NonComplexe::inv() const {
    // NonComplexe -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&*this);
    if (ptEntier == 0) {
        // NonComplexe -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&*this);
        if (ptReel == 0) {
            // NonComplexe -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&*this);
            if (ptRationnel == 0) {
                throw CalculatriceException("NonComplexe : inv : Impossible d'effectuer le dynamic cast!");
            } else{ // Rationnel
                Rationnel* res = new Rationnel(ptRationnel->getDen(),ptRationnel->getNum()); // y/x
                NonComplexe& ref = *res;
                return (ref);
            }
        } else{ // Reel
            const Rationnel* ptRat = dynamic_cast<const Rationnel *>(&(ptReel->toRationnel()));
            Rationnel* res = new Rationnel(ptRat->getDen(), ptRat->getNum()); // 1/x.y
            res->simplifier();
            NonComplexe& ref = *res;
            return (ref);
        }
    } else { // Entier
        Rationnel* res = new Rationnel(1, ptEntier->getX()); // 1/x
        NonComplexe& ref = *res;
        return (ref);
    }
}

NonComplexe& NonComplexe::log() const {
    const Reel* ptReel = dynamic_cast<const Reel*>(&(this->toReel()));
    if (ptReel == 0) {
        throw CalculatriceException("NonComplexe : log : Impossible d'effectuer le dynamic cast!");
    }
    Reel* res = new Reel(std::log(ptReel->getX()));
    NonComplexe& ref = *res;
    return (ref);
}

NonComplexe& NonComplexe::sqrt() const {
    const Reel* ptReel = dynamic_cast<const Reel*>(&(this->toReel()));
    if (ptReel == 0) {
        throw CalculatriceException("NonComplexe : log : Impossible d'effectuer le dynamic cast!");
    }
    double nb = ptReel->getX();
    Reel* res = new Reel(std::sqrt(nb));
    NonComplexe& ref = *res;
    return (ref);
}

NonComplexe& NonComplexe::pow(const NonComplexe& puiss) const {
    // Conversion de la puissance en reel
    Reel& refPuiss =  (Reel&)puiss.toReel();
    float puissance = refPuiss.getX();

    // NonComplexe -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(this);
    if (ptEntier == 0) {
        // NonComplexe -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(this);
        if (ptReel == 0) {
            // NonComplexe -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(this);
            if (ptRationnel == 0) {
                throw CalculatriceException("NonComplexe : pow : Impossible d'effectuer le dynamic cast!");
            } else { // Rationnel
                Rationnel* res= new Rationnel(std::pow(ptRationnel->getNum().getX(), puissance), std::pow(ptRationnel->getDen().getX(), puissance));
                res->simplifier();
                NonComplexe& ref = *res;
                return (ref);
            }
        } else{ // Reel
            Reel* res = new Reel(std::pow(ptReel->getX(),puissance));
            NonComplexe& ref = *res;
            return (ref);
        }
    } else { // Entier
        Entier* res = new Entier(std::pow(ptEntier->getX(),puissance));
        NonComplexe& ref = *res;
        return (ref);
    }
}
