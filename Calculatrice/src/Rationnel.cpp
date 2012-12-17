
#include "Rationnel.h"

// constructeurs
Rationnel::Rationnel(const Entier& num, const Entier& den) {
    if (den.getX() == 0) {
        throw CalculatriceException("Rationnel : Rationnel : Impossible de construire le rationnel (Denominateur nul)!");
    } else {
        mNum = new Entier(num.getX());
        mDen = new Entier(den.getX());
    }
}

Rationnel::Rationnel(const NonComplexe& num, const NonComplexe& den) {
    const Entier* tmpNum = dynamic_cast<const Entier*>(&num);
    const Entier* tmpDen = dynamic_cast<const Entier*>(&den);
    if (tmpNum == 0 || tmpDen == 0) {
        throw CalculatriceException("Rationnel : Rationnel : Impossible de construire le rationnel (2 Nombres Entier nécessaires !)");
    } else {
        if (tmpDen->getX() == 0) {
            throw CalculatriceException("Rationnel : Rationnel : Impossible de construire le rationnel (Denominateur nul)!");
        } else {
            mNum = new Entier(tmpNum->getX());
            mDen = new Entier(tmpDen->getX());
        }
    }
}

Rationnel::Rationnel(unsigned int num, unsigned int den) {
    if (den == 0) {
        throw CalculatriceException("Rationnel : Rationnel : Impossible de construire le rationnel (Denominateur nul)!");
    } else {
        mNum = new Entier(num);
        mDen = new Entier(den);
    }
}

// destructeur
Rationnel::~Rationnel() {
    delete mNum;
    delete mDen;
}

// méthodes VP héritées et implémentées depuis la classe Nombre
Nombre& Rationnel::addition(const Nombre& n) const {
    // Nombre -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
    if (ptEntier == 0) {
        // Nombre -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&n);
        if (ptReel == 0) {
            // Nombre -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
            if (ptRationnel == 0) {
                throw CalculatriceException("Rationnel : addition : Impossible d'effectuer le dynamic cast!");
            } else { // Rationnel + Rationnel

                Entier e1 = Entier((mNum->getX() * ptRationnel->getDen().getX()) + (mDen->getX() * ptRationnel->getNum().getX()));
                Entier e2 = Entier(mDen->getX() * ptRationnel->getDen().getX());

                Rationnel* res= new Rationnel(e1, e2);
                res->simplifier();
                Nombre& ref = *res;
                return(ref);
           }
        } else { // Rationnel + Reel
            Nombre& ref = ptReel->addition(*this);
            return(ref);
        }
    } else { // Rationnel + Entier
        Nombre& ref = ptEntier->addition(*this);
        return(ref);
    }
}
Nombre& Rationnel::soustraction(const Nombre& n) const {
    // Nombre -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
    if (ptEntier == 0) {
        // Nombre -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&n);
        if (ptReel == 0) {
            // Nombre -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
            if (ptRationnel == 0) {
                throw CalculatriceException("Rationnel : soustraction : Impossible d'effectuer le dynamic cast!");
            } else { // Rationnel - Rationnel
                Entier e1 = Entier((mNum->getX() * ptRationnel->getDen().getX()) - (mDen->getX() * ptRationnel->getNum().getX()));
                Entier e2 = Entier(mDen->getX() * ptRationnel->getDen().getX());


                Rationnel* res= new Rationnel(e1, e2);
                res->simplifier();
                Nombre& ref = *res;
                return(ref);
           }
        } else { // Rationnel - Reel
            Nombre& ref = ptReel->soustraction(*this).sign();
            return(ref);
        }
    } else { // Rationnel - Entier
        Nombre& ref = ptEntier->soustraction(*this).sign();
        return(ref);
    }
}
Nombre& Rationnel::multiplication(const Nombre& n) const {
    // Nombre -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
    if (ptEntier == 0) {
        // Nombre -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&n);
        if (ptReel == 0) {
            // Nombre -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
            if (ptRationnel == 0) {
                throw CalculatriceException("Rationnel : multiplication : Impossible d'effectuer le dynamic cast!");
            } else { //  Rationnel * Rationnel
                Entier e1 = Entier(mNum->getX() * ptRationnel->mNum->getX());
                Entier e2 = Entier(mDen->getX() * ptRationnel->mDen->getX());
                Rationnel* res= new Rationnel(e1, e2);
                res->simplifier();
                Nombre& ref = *res;
                return(ref);
           }
        } else { // Rationnel * Reel
            Nombre& ref = ptReel->multiplication(*this);
            return(ref);
        }
    } else { // Rationnel * Entier
        Nombre& ref = ptEntier->multiplication(*this);
        return(ref);
    }
}
Nombre& Rationnel::division(const Nombre& n) const {
    // Nombre -> Entier
    const Entier* ptEntier = dynamic_cast<const Entier*>(&n);
    if (ptEntier == 0) {
        // Nombre -> Reel
        const Reel* ptReel = dynamic_cast<const Reel*>(&n);
        if (ptReel == 0) {
            // Nombre -> Rationnel
            const Rationnel* ptRationnel = dynamic_cast<const Rationnel*>(&n);
            if (ptRationnel == 0) {
                throw CalculatriceException("Rationnel : division : Impossible d'effectuer le dynamic cast!");
            } else { //  Rationnel / Rationnel
                NonComplexe& reff = ptRationnel->inv();
                Rationnel* ptInv=dynamic_cast<Rationnel*>(&reff);

                Nombre& n1 = this->mNum->multiplication((Nombre&)ptInv->getNum());
                Nombre& n2 = this->mDen->multiplication((Nombre&)ptInv->getDen());

                const Entier* ptNum = dynamic_cast<const Entier *>(&n1);
                const Entier* ptDen = dynamic_cast<const Entier *>(&n2);

                if (ptNum==0 || ptDen==0) {
                    throw CalculatriceException("Rationnel : division : Impossible d'effectuer le dynamic cast!");
                }

                Rationnel* res= new Rationnel(*ptNum, *ptDen);
                res->simplifier();
                Nombre& ref = *res;
                return(ref);
           }
        } else { // Rationnel / Reel
            Nombre& pt = ptReel->division(*this);
            NonComplexe* pt2 =  dynamic_cast<NonComplexe *>(&pt);
            Nombre& ref = pt2->inv();
            return(ref);
        }
    } else { // Rationnel / Entier
        Nombre& pt = ptEntier->division(*this);
        NonComplexe* pt2 =  dynamic_cast<NonComplexe *>(&pt);
        Nombre& ref = pt2->inv();
        return(ref);
    }
}

// méthodes VP implémentées depuis la classe NonComplexe
NonComplexe& Rationnel::toEntier() const {
    // Rationnel -> Réel
    Entier* res = new Entier(mNum->getX() / mDen->getX());
    NonComplexe& ref = *res;
    return (ref);
}

NonComplexe& Rationnel::toReel() const {
    // Rationnel -> Réel
    float n = (float)mNum->getX();
    float d = (float)mDen->getX();
    Reel* res= new Reel(n/d);
    NonComplexe& ref = *res;
    return (ref);
}

NonComplexe& Rationnel::toRationnel() const {
    NonComplexe& ref = (NonComplexe&)*this;
    return (ref);
}


NonComplexe& Rationnel::toComplexe() const {
    // Rationnel -> Complexe
    Nombre& re = (Nombre&)*this;
    Nombre& im = (Nombre&)*(new Rationnel(0,0));
    Complexe* res = new Complexe(re,im);
    NonComplexe& ref = (NonComplexe&)*res;
    return (ref);
}


// pgcd
Entier pgcd(const Entier& a, const Entier& b){
    Entier x(a.getX());
    Entier y(b.getX());

    if ((y.getX())==0) {
        return x;
    } else {
        return pgcd(Entier(y.getX()),Entier(x.getX() % y.getX()));
    }
}

// simplification
void Rationnel::simplifier() {
    Entier vpgcd = pgcd(getNum(), getDen());

    const Reel* pNumDiv = dynamic_cast<const Reel*>(&getNum().division(vpgcd));
    const Reel* pDenDiv = dynamic_cast<const Reel*>(&getDen().division(vpgcd));

    if (pNumDiv==0 || pDenDiv==0) {
        throw CalculatriceException("Rationnel : simplifier : Impossible d'effectuer le dynamic cast!");
    }

    mNum = (const Entier*)&pNumDiv->toEntier();
    mDen = (const Entier*)&pDenDiv->toEntier();
}

// affichage
QString Rationnel::toString() const {
    QString str1, str2;
    str1.setNum(mNum->getX());
    str2.setNum(mDen->getX());
    return QString(str1+"/"+str2);
}
