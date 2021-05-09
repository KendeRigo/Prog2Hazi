/**
 *  \file kezi.h
 *  Kezi osztály deklarációja
 */

#ifndef KEZI_H_INCLUDED
#define KEZI_H_INCLUDED

#include "csapat.h"
#include "memtrace.h"

/// Kezi osztály deklarációja
/// Az alaposztály adatait a csapat támogatásával bővítjük
class Kezi: public Csapat {
    int Tamogatas;
public:
    Kezi(): Csapat(), Tamogatas(0) {}

    /// Konstruktor
    /// @param nev - csapatnév
    /// @param tag - sportolók száma
    /// @param tam - támogatás összege
    Kezi(const std::string& nev, int tag = 0, int tam = 0): Csapat(nev, tag), Tamogatas(tam) {}

    /// Másoló konstruktor
    /// @param k - objektum amiről a másolatot kell létrehozni
    Kezi(const Kezi& k): Csapat(k.getNev(), k.getTagok()), Tamogatas(k.Tamogatas) {}

    /// Értékadás
    /// @param rhs - jobb oldali operandus (a bal a *this)
    /// @return - referencia saját magára, hogy fűzhető legyen
    Kezi& operator=(const Kezi& rhs);

    std::string getType() const {return "Kezi";}

    /// Csapat támogatásának lekérdezése
    /// @return - támogatás
    int getTamogatas() const {return Tamogatas;}

    /// Csapat támogatásának beállítása
    /// @param tam -támogatás összege
    void setTamogatas(int tam);

    /// Kiírás
    void kiir();

    /// Fájlba írás
    void fba(const char* fname);

    Kezi* clone() {return new Kezi(*this);}

    ~Kezi();
};

/// Globális << operátor az Kezi adatainak kiírásához
/// @param os - bal oldali operandus (ostream)
/// @param rhs_k - jobb oldali operandus (Kezi)
/// @return ostream&, hogy fűzhető legyen
std::ostream& operator<<(std::ostream& os, const Kezi& rhs_k);

/// Globális >> operátor az Kezi adatainak beolvasásához
/// @param is - bal oldali operandus (istream)
/// @param rhs_k - jobb oldali operandus (Kezi)
/// @return istream&, hogy fűzhető legyen
std::istream& operator>>(std::istream& is, Kezi& rhs_k);

#endif // KEZI_H_INCLUDED
