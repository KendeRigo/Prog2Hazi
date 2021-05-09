/**
 *  \file foci.h
 *  Foci osztály deklarációja
 */

#ifndef FOCI_H_INCLUDED
#define FOCI_H_INCLUDED


#include "csapat.h"
#include "memtrace.h"

/// Foci osztály deklarációja
/// Az alaposztály adatait a két edző nevével bővítjük
class Foci: public Csapat {
    std::string Edzo1;
    std::string Edzo2;
public:
    Foci(): Csapat(), Edzo1(), Edzo2() {}

    /// Konstruktor
    /// @param str1 - első edző neve
    /// @param str2 - második edző neve
    /// @param nev - csapatnév
    /// @param t - sportolók száma
    Foci(const std::string& nev, const std::string& str1, const std::string& str2, int t = 0):Csapat(nev, t), Edzo1(str1), Edzo2(str2) {}

    /// Másoló konstruktor
    /// @param f - objektum amiről a másolatot kell létrehozni
    Foci(const Foci& f): Csapat(f.getNev(), f.getTagok()), Edzo1(f.Edzo1), Edzo2(f.Edzo2) {}

    /// Értékadás
    /// @param rhs - jobb oldali operandus (a bal a *this)
    /// @return - referencia saját magára, hogy fűzhető legyen
    Foci& operator=(const Foci& rhs);

    std::string getType() const {return "Foci";}

    /// Első edző nevének lekérdezése
    /// @return - első edző neve
    std::string getEdzo1() const {return Edzo1;}

    /// Második edző nevének lekérdezése
    /// @return - második edző neve
    std::string getEdzo2() const {return Edzo2;}

    /// Első edző nevének beállítása
    /// @param nev - első edző neve
    void setEdzo1(const std::string& nev);

    /// Első edző nevének beállítása
    /// @param nev - első edző neve
    void setEdzo2(const std::string& nev);

    /// Kiírás
    void kiir();

    /// Fájlba írás
    void fba(const char* fname);

    Foci* clone() {return new Foci(*this);}

    ~Foci();
};

/// Globális << operátor a Foci adatainak kiírásához
/// @param os - bal oldali operandus (ostream)
/// @param rhs_f - jobb oldali operandus (Foci)
/// @return ostream&, hogy fűzhető legyen
std::ostream& operator<<(std::ostream& os, const Foci& rhs_f);

/// Globális >> operátor az Foci adatainak beolvasásához
/// @param is - bal oldali operandus (istream)
/// @param rhs_f - jobb oldali operandus (Foci)
/// @return istream&, hogy fűzhető legyen
std::istream& operator>>(std::istream& is, Foci& rhs_f);

#endif // FOCI_H_INCLUDED
