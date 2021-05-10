/**
 *  \file adatbazis.h
 *  Adatbazis osztály deklarációja
 */


#ifndef ADATBAZIS_H_INCLUDED
#define ADATBAZIS_H_INCLUDED

#include "csapat.h"
#include "foci.h"
#include "kezi.h"
#include "kosar.h"
#include "memtrace.h"

/// Adatbazis osztály
class Adatbazis {
    Csapat** Csapatok;
    size_t Meret;
    size_t nCsapat;
public:
    /// Konstruktor
    /// @param n - adatbázis mérete
    Adatbazis(size_t meret = 0): Meret(meret), nCsapat(0){
        Csapatok = new Csapat*[Meret];
    }

    /// Másoló konstruktor
    /// @param db - objektum amiről a másolatot kell létrehozni
    Adatbazis(const Adatbazis& db):Meret(db.Meret), nCsapat(db.nCsapat){
        Csapatok = new Csapat*[Meret];
        for(size_t i = 0; i < nCsapat; i++) {
            Csapatok[i] = db.Csapatok[i]->clone();
        }
    }

    /// Értékadás
    /// @param rhs - jobb oldali operandus (a bal a *this)
    /// @return - referencia saját magára, hogy fűzhető legyen
    Adatbazis& operator=(const Adatbazis& rhs);

    bool keres(std::string str);

    /// Csapat felvétele
    /// @param cs - fevenni kívánt csapat
    /// @return Adatbazis&
    void felvesz(Csapat* cs);

    /// Csapatok törlése az adatbázisból
    /// @param cs - törlendő csapat
    void torol(std::string str);

    /// Index operator
    /// @param idx - az index értéke
    /// @return Csapat& - az indexelt csapat
    Csapat* operator[](size_t idx) {
        if(idx >= nCsapat || idx < 0) {throw "Index hiba!";}
        return Csapatok[idx];
    }

    /// Konstans index operator
    /// @param idx - az index értéke
    /// @return Csapat& - az indexelt csapat
    const Csapat* operator[](size_t idx) const {
        if(idx >= nCsapat || idx < 0) {throw "Index hiba!";}
        return Csapatok[idx];
    }

    /// Adatbázis méreténel lekérdezése
    /// @return size_t - adatbázis teljes mérete
    size_t size() const {return Meret;}

    /// Adatbázisban lévő csapatok számának lekérdezése
    /// @return size_t - Adatbázisban szereplő csapatok száma
    size_t amount() const {return nCsapat;}

    /// Teljes létszám lekérdezése
    /// @return int - Az adatbázisban szereplő összes csapat létszámának összege
    int letszam();

    /// A teljes adatbázis kiírása
    void listaz();

    /// Adatbázis kiolvasása fájlból
    void fbol(const char* fname);

    /// Adatbázis fájlba írása
    void fba(const char* fname);

    ~Adatbazis() {
        for(size_t i = 0; i < nCsapat; i++) {
            if(Csapatok[i] != NULL) {delete *(Csapatok+i);}
        }
        delete[] Csapatok;
    }
};


#endif // ADATBAZIS_H_INCLUDED
