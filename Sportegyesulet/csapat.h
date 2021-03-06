/**
 *  \file csapat.h
 *  Csapat alaposztály deklarációja
 */

#ifndef CSAPAT_H_INCLUDED
#define CSAPAT_H_INCLUDED
#include <fstream>
#include <cstring>
#include "memtrace.h"

/// Csapat alaposztály
class Csapat {
    std::string Csapatnev;
    int Tagok;
public:
    ///Paraméter nélküli konstruktor
    Csapat(): Csapatnev(""), Tagok(0) {}

    /// Konstruktor
    /// @param nev - csapatnév
    /// @param t - sportolók száma
    Csapat(const std::string& nev, int t = 0): Csapatnev(nev), Tagok(t) {}

    /// Másoló konstruktor
    /// @param cs - objektum amiről a másolatot kell létrehozni
    Csapat(const Csapat& cs): Csapatnev(cs.Csapatnev), Tagok(cs.Tagok) {}

    /// Értékadás
    /// @param rhs - jobb oldali operandus (a bal a *this)
    /// @return - referencia saját magára, hogy fűzhető legyen
    Csapat& operator=(const Csapat& rhs);


    /// Sportolók számának lekérdezése
    /// @return - sportolók száma
    int getTagok() const {return Tagok;}

    /// Csapat nevének lekérdezése
    /// @return - csapatnév
    std::string getNev() const {return Csapatnev;}

    virtual std::string getEdzo1() const {throw "Nincs ilyen adattagom";}
    virtual std::string getEdzo2() const {throw "Nincs ilyen adattagom";}
    virtual int getTamogatas() const {throw "Nincs ilyen adattagom";}
    virtual int getPomPom() const {throw "Nincs ilyen adattagom";}

    /// Sportolók számának beállítása
    /// @param t - sportolók száma
    void setTagok(int t);

    /// Csapat nevének beállítása
    /// @param nev - csapatnév
    void setNev(const std::string& nev);

    /// Kiírás
    virtual void kiir();

    /// Fájlba írás
    virtual void fba(const char* fname);

    virtual Csapat* clone() {return new Csapat(*this);}

    virtual ~Csapat();



};

/// Globális << operátor az Csapat adatainak kiírásához
/// @param os - bal oldali operandus (ostream)
/// @param rhs_cs - jobb oldali operandus (Csapat)
/// @return ostream&, hogy fűzhető legyen
std::ostream& operator<<(std::ostream& os, const Csapat& rhs_cs);

/// Globális >> operátor az Csapat adatainak beolvasásához
/// @param is - bal oldali operandus (istream)
/// @param rhs_cs - jobb oldali operandus (Csapat)
/// @return istream&, hogy fűzhető legyen
std::istream& operator>>(std::istream& is, Csapat& rhs_cs);

#endif // CSAPAT_H_INCLUDED
