#include "BackUpPiles.h"

BackUpPiles* BackUpPiles::mBackUpPiles = 0;
unsigned int BackUpPiles::mIndexListe = 0;

BackUpPiles* BackUpPiles::getInstance(){
    if (mBackUpPiles == 0) {
        mIndexListe = 0;
        mBackUpPiles = new BackUpPiles();
    }
    return mBackUpPiles;
}

void BackUpPiles::libereInstance(){
    if (mBackUpPiles != 0) {
        delete mBackUpPiles;
    }
    mBackUpPiles = 0;
}

void BackUpPiles::ajouterNouvellePile(Pile::Memento* pile) {
    mListePiles.push(pile);
    mIndexListe++; // apres un premier push, mIndexListe vaut donc 1.
}


const Pile::Memento* BackUpPiles::getDernierePile() const {
    // si liste de piles non vide (l'index vaut au moins 1)
    if (!mListePiles.isEmpty() && mIndexListe > 0){

        // si on se trouve en tête de pile
        if (mIndexListe == mListePiles.size() && mIndexListe > 1) {
            mIndexListe--;
        }

        mIndexListe--; // on descends dans la liste des piles, donc on décrémente notre index.

        return mListePiles.value(mIndexListe); // on retourne le bon élement
    } else { // liste de piles vide
        throw CalculatriceException("BackUpPiles : Impossible de revenir en arrière (undo) car liste piles vide !");
    }
}

const Pile::Memento* BackUpPiles::getPileSuivante() const {
    // si liste de piles non vide et qu'on ne pointe pas la dernière pile
    if (!mListePiles.isEmpty() && (mIndexListe < mListePiles.size()-1)){
        mIndexListe++; // on monte dans la liste des piles, donc on incrémente notre index.
        return mListePiles.value(mIndexListe);
    } else { // liste de piles vide
        throw CalculatriceException("BackUpPiles : Impossible d'aller en avant (redo) car liste piles vide !");
    }
}

void BackUpPiles::clearBackUpPiles() {
    mListePiles.clear();
    mIndexListe = 0;
}


