#include "Entier.h"

// méthodes VP héritées et implémentées depuis la classe Nombre
Nombre& Entier::addition(const Nombre& n) const {
    // Nombre -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
    if (ptEntier == 0) {
        // Nombre -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&n);
        if (ptReel == 0) {
            // Nombre -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
            if (ptRationnel == 0) {
                throw CalculatriceException("Entier : addition : Impossible d'effectuer le dynamic cast!");
            } else { // Entier + Rationnel                
                Entier num = (mX * ptRationnel->getDen().getX() + ptRationnel->getNum().getX());
                Entier den = (ptRationnel->getDen().getX());
                Rationnel* res = new Rationnel(num, den);
                res->simplifier();
                Nombre& ref = *res;
                return(ref);
           }
        } else { // Entier + Reel
            Reel* res = new Reel(mX + ptReel->getX());
            Nombre& ref = *res;
            return(ref);
        }
    } else { // Entier + Entier
        Entier* res = new Entier(mX + ptEntier->getX());
        Nombre& ref = *res;
        return(ref);
    }
}
Nombre& Entier::soustraction(const Nombre& n) const {
    // Nombre -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
    if (ptEntier == 0) {
        // Nombre -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&n);
        if (ptReel == 0) {
            // Nombre -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
            if (ptRationnel == 0) {
                throw CalculatriceException("Entier : soustraction : Impossible d'effectuer le dynamic cast!");
            } else { //  Entier - Rationnel
                Entier num(mX * ptRationnel->getDen().getX() - ptRationnel->getNum().getX());
                Entier den(ptRationnel->getDen().getX());
                Rationnel* res = new Rationnel(num.toEntier(), den.toEntier());
                res->simplifier();
                Nombre& ref = *res;
                return(ref);
           }
        } else { // Entier - Reel
            Reel* res = new Reel(mX - ptReel->getX());
            Nombre& ref = *res;
            return(ref);
        }
    } else { // Entier - Entier
        Entier* res = new Entier(mX - ptEntier->getX());
        Nombre& ref = *res;
        return(ref);
    }

}
Nombre& Entier::multiplication(const Nombre& n) const {
    // Nombre -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
    if (ptEntier == 0) {
        // Nombre -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&n);
        if (ptReel == 0) {
            // Nombre -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
            if (ptRationnel == 0) {
                throw CalculatriceException("Entier : multiplication : Impossible d'effectuer le dynamic cast!");
            } else { //  Entier * Rationnel
                Rationnel* res=new Rationnel( (this->mX  * ptRationnel->getNum().getX()) , ptRationnel->getDen().getX());
                Nombre& ref = *res;
                return(ref);
           }
        } else { // Entier * Reel
            Reel* res = new Reel(mX * ptReel->getX());
            Nombre& ref = *res;
            return(ref);
        }
    } else { // Entier * Entier
        Entier* res = new Entier(mX * ptEntier->getX());
        Nombre& ref = *res;
        return(ref);
    }
}
Nombre& Entier::division(const Nombre& n) const {
    // Nombre -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
    if (ptEntier == 0) {
        // Nombre -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&n);
        if (ptReel == 0) {
            // Nombre -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
            if (ptRationnel == 0) {
                throw CalculatriceException("Entier : division : Impossible d'effectuer le dynamic cast!");
            } else { //  Entier / Rationnel
                if (ptRationnel->getNum().getX()/ptRationnel->getDen().getX()==0) {
                     throw CalculatriceException("Entier : division : Division par 0");
                }
                Entier num = Entier(mX  * ptRationnel->getDen().getX());
                Entier den = Entier(ptRationnel->getNum().getX());
                Rationnel* res= new Rationnel(num.toEntier(), den.toEntier());
                res->simplifier();
                Nombre& ref = *res;
                return(ref);
           }
        } else { // Entier / Reel
            if (ptReel->getX()==0) {
                 throw CalculatriceException("Entier : division : Division par 0");
            }
            Nombre& ref = this->division(ptReel->toRationnel());
            return(ref);
        }
    } else { // Entier / Entier
        if (ptEntier->getX()==0) {
             throw CalculatriceException("Entier : division : Division par 0");
        }
        Reel* res = new Reel(mX / ptEntier->getX());
        Nombre& ref = *res;
        return(ref);
    }
}

// méthodes VP implémentées depuis la classe NonComplexe
NonComplexe& Entier::toEntier() const {
    NonComplexe& ref = (NonComplexe&)*this;
    return ref;
}

NonComplexe& Entier::toReel() const {
    // Entier -> Réel
    Reel* res= new Reel(mX);
    NonComplexe& ref = *res;
    return (ref);
}
NonComplexe& Entier::toRationnel() const {
    // Entier -> Rationnel
    Rationnel* res= new Rationnel(mX,1);
    NonComplexe& ref = *res;
    return (ref);
}
NonComplexe& Entier::toComplexe() const {
    // Entier -> Complexe
    const Nombre& re = *(new Entier(getX()));
    const Nombre& im = *(new Entier(0));
    Complexe* res = new Complexe(re,im);
    NonComplexe& ref = (NonComplexe&)*res;
    return (ref);
}

// méthodes membres de cette classe
Entier& Entier::mod(const Entier& e) {
    Entier* res = new Entier(mX % e.mX);
    Entier& ref = *res;
    return (ref);
}

int factorielle(int n) {
    if (n == 0) {
         return 1;
    } else {
        return n * factorielle(n-1);
    }
}

Entier& Entier::fact() {
    Entier* res = new Entier(factorielle(mX));
    Entier& ref = *res;
    return ref;
}
