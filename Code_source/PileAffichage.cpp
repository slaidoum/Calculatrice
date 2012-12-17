#include "PileAffichage.h"

PileAffichage* PileAffichage::mPile = 0;

PileAffichage& PileAffichage::getInstance() {
    if (mPile==0) {
        mPile = new PileAffichage();
    }
    return *mPile;
}

void PileAffichage::libereInstance(){
    if (mPile!=0) {
        delete mPile;
    }
    mPile = 0;
}
