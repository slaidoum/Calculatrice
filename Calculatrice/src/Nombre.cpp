#include "Nombre.h"

#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"

Nombre& Nombre::sign() const {
    // Nombre -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&*this);
    if (ptEntier == 0) {
        // Nombre -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&*this);
        if (ptReel == 0) {
            // Nombre -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&*this);
            if (ptRationnel == 0) {
                throw CalculatriceException("Impossible d'effectuer le dynamic cast!");
            } else { // Rationnel
                const Entier* oppNum = dynamic_cast<const Entier*>(&(ptRationnel->getNum().sign())); // -Numérateur (Entier)
                Rationnel* res = new Rationnel(oppNum->getX(),ptRationnel->getDen().getX()); // -Numérateur (Entier), Dénominateur (Entier)
                Nombre& ref = *res;
                return (ref);
            }
        } else { // Reel
            Reel* res = new Reel(-(ptReel->getX())); // - float
            Nombre& ref = *res;
            return (ref);
        }
    } else { // Entier
        Entier* res = new Entier(-(ptEntier->getX())); // - int
        Nombre& ref = *res;
        return (ref);
    }
}

Nombre& Nombre::sqr() const {
    return (*this).multiplication(*this);
}

Nombre& Nombre::cube() const {
    return (*this).multiplication(this->sqr());
}
