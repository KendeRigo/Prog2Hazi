/**
 *  \file csapat.cpp
 *  Csapat alaposztály tagfüggvényeinek megvalósítása
 */

#include "csapat.h"
#include "memtrace.h"

Csapat& Csapat::operator=(const Csapat& rhs) {
    if(this != &rhs) {
        Csapatnev = rhs.getNev();
        Tagok = rhs.Tagok;
    }
    return *this;
}

void Csapat::setTagok(int t) {
    Tagok = t;
}

void Csapat::setNev(const std::string& nev) {
    Csapatnev = nev;
}

void Csapat::kiir() {
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Csapat& rhs_cs) {
    os << "Csapatnev: " << rhs_cs.getNev() << ", Tagok szama: " << rhs_cs.getTagok();
    return os;
}

void Csapat::fba(const char* fname) {
    std::replace(Csapatnev.begin(), Csapatnev.end(), ' ', ';');
    std::ofstream file;
    file.open(fname, std::fstream::app);
    if(file.is_open()){
        file << "0 " << Csapatnev << " " << Tagok << std::endl;
        file.close();
        std::replace(Csapatnev.begin(), Csapatnev.end(), ';', ' ');
    } else {throw "Nem lehetett megnyitni a fajlt!";}
}
 Csapat::~Csapat() {}
