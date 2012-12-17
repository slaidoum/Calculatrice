#include "Complexe.h"

#include "Entier.h"
#include "Rationnel.h"
#include "Reel.h"

// constructeurs
Complexe::Complexe(const NonComplexe& re, const NonComplexe& im) {
    mRe = &re;
    mIm = &im;
}

Complexe::Complexe(const Nombre& re, const Nombre& im) {
    const NonComplexe* tmpRe = dynamic_cast<const NonComplexe*>(&re);
    const NonComplexe* tmpIm = dynamic_cast<const NonComplexe*>(&im);
    if (tmpRe == 0 || tmpIm == 0) {
        throw CalculatriceException("Construction du complexe impossible (2 Nombres NonComplexe nécessaires !)");
    } else {
        mRe = tmpRe;
        mIm = tmpIm;
    }
}

// destructeur
Complexe::~Complexe() {
    delete mRe;
    delete mIm;
}

// méthodes VP implémentées depuis la classe Nombre

// C(re1 + re2,im1 + im2)
Nombre& Complexe::addition(const Nombre& n) const {
    // Nombre -> Complexe
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&n);
    if (ptComplexe == 0) {
        // Nombre -> Entier
        const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
        if (ptEntier == 0) {
            // Nombre -> Reel
            const Reel* ptReel = dynamic_cast<const Reel*>(&n);
            if (ptReel == 0) {
                // Nombre -> Rationnel
                const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
                if (ptRationnel == 0) {
                    throw CalculatriceException("Complexe : addition : Impossible d'effectuer le dynamic cast!");
                } else { // Rationnel
                    Complexe& refC = (Complexe&)ptRationnel->toComplexe();
                    Complexe* res = new Complexe(mRe->addition(*refC.mRe), mIm->addition(*refC.mIm));
                    Nombre& ref = *res;
                    return(ref);
               }
            } else { // Reel
                Complexe& refC = (Complexe&)ptReel->toComplexe();
                Complexe* res = new Complexe(mRe->addition(*refC.mRe), mIm->addition(*refC.mIm));
                Nombre& ref = *res;
                return(ref);
            }
        } else { // Entier
            Complexe& refC = (Complexe&)ptEntier->toComplexe();
            Complexe* res = new Complexe(mRe->addition(*refC.mRe), mIm->addition(*refC.mIm));
            Nombre& ref = *res;
            return(ref);
        }
    } else {  // Complexe
        Complexe* res = new Complexe(mRe->addition(*ptComplexe->mRe), mIm->addition(*ptComplexe->mIm));
        Nombre& ref = *res;
        return(ref);
    }
}

// C(re1 - re2, im1 - im2)
Nombre& Complexe::soustraction(const Nombre& n) const {
    // Nombre -> Complexe
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&n);
    if (ptComplexe == 0) {
        // Nombre -> Entier
        const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
        if (ptEntier == 0) {
            // Nombre -> Reel
            const Reel* ptReel = dynamic_cast<const Reel*>(&n);
            if (ptReel == 0) {
                // Nombre -> Rationnel
                const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
                if (ptRationnel == 0) {
                    throw CalculatriceException("Complexe : soustraction : Impossible d'effectuer le dynamic cast!");
                } else { // Rationnel
                    Complexe& refC= (Complexe&)ptRationnel->toComplexe();
                    Complexe* res = new Complexe( mRe->soustraction(*refC.mRe) ,mIm->soustraction(*refC.mIm));
                    Nombre& ref = *res;
                    return(ref);
               }
            } else { // Reel
                Complexe& refC = (Complexe&)ptReel->toComplexe();
                Complexe* res = new Complexe( mRe->soustraction(*refC.mRe) ,mIm->soustraction(*refC.mIm));
                Nombre& ref = *res;
                return(ref);
            }
        } else { // Entier
            Complexe& refC = (Complexe&)ptEntier->toComplexe();
            Complexe* res = new Complexe( mRe->soustraction(*refC.mRe) ,mIm->soustraction(*refC.mIm));
            Nombre& ref = *res;
            return(ref);
        }
    } else {  // Complexe
        Complexe* res = new Complexe(mRe->soustraction(*ptComplexe->mRe), mIm->soustraction(*ptComplexe->mIm));
        Nombre& ref = *res;
        return(ref);
    }
}

// C(re1*re2-im1*im2, re1*im2+im1*re2)
Nombre& Complexe::multiplication(const Nombre& n) const {
    // Nombre -> Complexe
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&n);
    if (ptComplexe == 0) {
        // Nombre -> Entier
        const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
        if (ptEntier == 0) {
            // Nombre -> Reel
            const Reel* ptReel = dynamic_cast<const Reel*>(&n);
            if (ptReel == 0) {
                // Nombre -> Rationnel
                const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
                if (ptRationnel == 0) {
                    throw CalculatriceException("Complexe : multiplication : Impossible d'effectuer le dynamic cast!");
                } else { // Rationnel
                    Complexe& refC= (Complexe&)ptRationnel->toComplexe();
                    Complexe* res = new Complexe(mRe->multiplication(*refC.mRe) - mIm->multiplication(*refC.mIm),mRe->multiplication(*refC.mIm) + mIm->multiplication(*refC.mRe));
                    Nombre& ref = *res;
                    return(ref);
               }
            } else { // Reel
                Complexe& refC = (Complexe&)ptReel->toComplexe();
                Complexe* res = new Complexe(mRe->multiplication(*refC.mRe) - mIm->multiplication(*refC.mIm),mRe->multiplication(*refC.mIm) + mIm->multiplication(*refC.mRe));
                Nombre& ref = *res;
                return(ref);
            }
        } else { // Entier
            Complexe& refC = (Complexe&)ptEntier->toComplexe();
            Complexe* res = new Complexe(mRe->multiplication(*refC.mRe) - mIm->multiplication(*refC.mIm),mRe->multiplication(*refC.mIm) + mIm->multiplication(*refC.mRe));
            Nombre& ref = *res;
            return(ref);
        }
    } else {  // Complexe
        Complexe* res = new Complexe(mRe->multiplication(*ptComplexe->mRe) - mIm->multiplication(*ptComplexe->mIm),mRe->multiplication(*ptComplexe->mIm) + mIm->multiplication(*ptComplexe->mRe));
        Nombre& ref = *res;
        return(ref);
    }
}

// (ac+bd+i(bc-ad)) / (c^2+d^2)
Nombre& Complexe::division(const Nombre& n) const {
    // Nombre -> Complexe
    const Complexe* ptComplexe = dynamic_cast<const Complexe*>(&n);
    if (ptComplexe == 0) {
        // Nombre -> Entier
        const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
        if (ptEntier == 0) {
            // Nombre -> Reel
            const Reel* ptReel = dynamic_cast<const Reel*>(&n);
            if (ptReel == 0) {
                // Nombre -> Rationnel
                const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
                if (ptRationnel == 0) {
                    throw CalculatriceException("Complexe : division : Impossible d'effectuer le dynamic cast!");
                } else { // Rationnel
                    Complexe& refC = (Complexe&)ptRationnel->toComplexe();
                    if (refC.mRe == 0 && refC.mIm == 0) {
                        throw CalculatriceException("Complexe : division : Division par 0 impossible!");
                    }
                    Nombre& tmpRe = ((mRe->multiplication(*refC.mRe)).addition(mIm->multiplication(*refC.mIm))).division((refC.mRe->sqr()).addition(refC.mIm->sqr()));
                    Nombre& tmpIm = ((mIm->multiplication(*refC.mRe)).addition(mRe->multiplication(*refC.mIm))).division((refC.mRe->sqr()).addition(refC.mRe->sqr()));
                    Complexe* res = new Complexe(tmpRe, tmpIm);
                    Nombre& ref = *res;
                    return(ref);
               }
            } else { // Reel
                Complexe& refC = (Complexe&)ptReel->toComplexe();
                if (refC.mRe == 0 && refC.mIm == 0) {
                    throw CalculatriceException("Complexe : division : Division par 0 impossible!");
                }
                Nombre& tmpRe = ((mRe->multiplication(*refC.mRe)).addition(mIm->multiplication(*refC.mIm))).division((refC.mRe->sqr()).addition(refC.mIm->sqr()));
                Nombre& tmpIm = ((mIm->multiplication(*refC.mRe)).addition(mRe->multiplication(*refC.mIm))).division((refC.mRe->sqr()).addition(refC.mIm->sqr()));
                Complexe* res = new Complexe(tmpRe, tmpIm);
                Nombre& ref = *res;
                return(ref);
            }
        } else { // Entier
            Complexe& refC =(Complexe&) ptEntier->toComplexe();
            if (refC.mRe == 0 && refC.mIm == 0) {
                throw CalculatriceException("Complexe : division : Division par 0 impossible!");
            }
            Nombre& tmpRe = ((mRe->multiplication(*refC.mRe)).addition(mIm->multiplication(*refC.mIm))).division((refC.mRe->sqr()).addition(refC.mIm->sqr()));
            Nombre& tmpIm = ((mIm->multiplication(*refC.mRe)).addition(mRe->multiplication(*refC.mIm))).division((refC.mRe->sqr()).addition(refC.mIm->sqr()));
            Complexe* res = new Complexe(tmpRe, tmpIm);
            Nombre& ref = *res;
            return(ref);
        }
    } else {  // Complexe
        if (ptComplexe->mRe == 0 && ptComplexe->mIm == 0) {
            throw CalculatriceException("Complexe : division  : Division par 0 impossible!");
        }

        Nombre& tmpRe = ((mRe->multiplication(*ptComplexe->mRe)).addition(mIm->multiplication(*ptComplexe->mIm))).division((ptComplexe->mRe->sqr()).addition(ptComplexe->mIm->sqr()));
        Nombre& tmpIm = ((mIm->multiplication(*ptComplexe->mRe)).addition(mRe->multiplication(*ptComplexe->mIm))).division((ptComplexe->mRe->sqr()).addition(ptComplexe->mIm->sqr()));
        Complexe* res = new Complexe(tmpRe, tmpIm);
        Nombre& ref = *res;
        return(ref);
  }
}

// méthodes V implémentées depuis la classe Nombre
Nombre& Complexe::sign() const {
    Complexe* res = new Complexe(mRe->sign(),mIm->sign()); // sign sur un réel/entier/rationnel
    Nombre& ref = *res;
    return (ref);
}


Nombre& Complexe::sqr() const {
}

Nombre& Complexe::cube() const {
}

// autres méthodes
Nombre& Complexe::module() const {
    Nombre& tmp = mRe->sqr() + mIm->sqr();
    Reel* res = dynamic_cast<Reel*>(&tmp);
    res->sqrt();
    Nombre& ref = *res;
    return(ref);
}

// affichage
QString Complexe::toString() const {
    return mRe->toString() + "$" + mIm->toString();
}
