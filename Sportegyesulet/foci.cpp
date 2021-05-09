/**
 *  \file foci.cpp
 *  Foci osztály tagfüggvényeinek megvalósítása
 */

#include "foci.h"
#include "memtrace.h"

Foci& Foci::operator=(const Foci& rhs) {
    if(this != &rhs) {
        this->setNev(rhs.getNev());
        this->setTagok(rhs.getTagok());
        Edzo1 = rhs.Edzo1;
        Edzo2 = rhs.Edzo2;
    }
    return *this;
}

void Foci::setEdzo1(const std::string& nev) {
    Edzo1 = nev;
}

void Foci::setEdzo2(const std::string& nev) {
    Edzo2 = nev;
}

void Foci::kiir() {
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Foci& rhs_f) {
    os << "Focicsapat " << (Csapat&)rhs_f << ", Edzo1: " << rhs_f.getEdzo1() <<
    ", Edzo2: " << rhs_f.getEdzo2();
    return os;
}

void Foci::fba(const char* fname) {
    std::string nev(getNev());
    std::replace(nev.begin(), nev.end(), ' ', ';');
    std::replace(Edzo1.begin(), Edzo1.end(), ' ', ';');
    std::replace(Edzo2.begin(), Edzo2.end(), ' ', ';');

    std::ofstream file;
    file.open(fname, std::fstream::app);

    if(file.is_open()) {
        file << "1 " << nev << " " << this->getTagok() << " " << Edzo1 << " " << Edzo2 << std::endl;
        file.close();
        std::replace(Edzo1.begin(), Edzo1.end(), ';', ' ');
        std::replace(Edzo2.begin(), Edzo2.end(), ';', ' ');
    } else {throw "Nem lehetett megnyitni a fajlt!";}
}

Foci::~Foci() {}
