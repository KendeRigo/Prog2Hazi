/**
 *  \file kosar.h
 *  Kosar osztály deklarációja
 */

#ifndef KOSAR_H_INCLUDED
#define KOSAR_H_INCLUDED

#include "csapat.h"
#include "memtrace.h"

/// Kosar osztály deklarációja
/// Az alaposztály adatait a csapathoz tartozó pom-pom lányok számával bővítjük
class Kosar: public Csapat {
    int PomPom;

public:
    Kosar(): Csapat(), PomPom(0) {}

    /// Konstruktor
    /// @param nev - csapatnév
    /// @param tag - sportolók száma
    /// @param pp - pom-pom lányok száma
    Kosar(const std::string& nev, int t = 0, int pp = 0): Csapat(nev, t), PomPom(pp) {}

    /// Másoló konstruktor
    /// @param k - objektum amiről a másolatot kell létrehozni
    Kosar(const Kosar& k): Csapat(k.getNev(), k.getTagok()), PomPom(k.PomPom) {}

    /// Értékadás
    /// @param rhs - jobb oldali operandus (a bal a *this)
    /// @return - referencia saját magára, hogy fűzhető legyen
    Kosar& operator=(const Kosar& rhs);

    std::string getType() const {return "Kosar";}

    /// Pom-pom lányok számának lekérdezése
    /// @return - pom-pom lányok száma
    int getPomPom() const {return PomPom;}

    /// Pom-pom lányok számának beállítása
    /// @param pp - pom-pom lányok száma
    void setPomPom(int pp);

    /// Kiírás
    void kiir();

    /// Fájlba írás
    void fba(const char* fname);

    ~Kosar();
};

/// Globális << operátor az Kosar adatainak kiírásához
/// @param os - bal oldali operandus (ostream)
/// @param rhs_k - jobb oldali operandus (Kosar)
/// @return ostream&, hogy fűzhető legyen
std::ostream& operator<<(std::ostream& os, const Kosar& rhs_k);

/// Globális >> operátor az Kosar adatainak beolvasásához
/// @param is - bal oldali operandus (istream)
/// @param rhs_k - jobb oldali operandus (Kosar)
/// @return istream&, hogy fűzhető legyen
std::istream& operator>>(std::istream& is, Kosar& rhs_k);

#endif // KOSAR_H_INCLUDED
