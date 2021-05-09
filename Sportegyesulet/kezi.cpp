/**
 *  \file kezi.cpp
 *  Kezi osztály tagfüggvényeinek megvalósítása
 */

#include "kezi.h"
#include "memtrace.h"

Kezi& Kezi::operator=(const Kezi& rhs) {
    if(this != &rhs) {
        this->setNev(rhs.getNev());
        this->setTagok(rhs.getTagok());
        Tamogatas = rhs.Tamogatas;
    }
    return *this;
}

void Kezi::setTamogatas(int tam) {
    Tamogatas = tam;
}

void Kezi::kiir() {
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Kezi& rhs_k) {
    os << "Kezicsapat " << (Csapat&)rhs_k << ", Tamogatas: " << rhs_k.getTamogatas() << " Ft";
    return os;
}

void Kezi::fba(const char* fname) {
    std::string nev(getNev());
    std::replace(nev.begin(), nev.end(), ' ', ';');

    std::ofstream file;
    file.open(fname, std::fstream::app);

    if(file.is_open()) {
        file << "2 " << nev << " " << this->getTagok() << " " << Tamogatas << std::endl;
        file.close();
    } else {throw "Nem lehetett megnyitni a fajlt!";}
}

Kezi::~Kezi() {}
