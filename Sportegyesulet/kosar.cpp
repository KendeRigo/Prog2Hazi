/**
 *  \file kosar.cpp
 *  Kosar osztály tagfüggvényeinek megvalósítása
 */

#include "kosar.h"
#include "memtrace.h"

Kosar& Kosar::operator=(const Kosar& rhs) {
    if(this != &rhs) {
        this->setNev(rhs.getNev());
        this->setTagok(rhs.getTagok());
        PomPom = rhs.PomPom;
    }
    return *this;
}

void Kosar::setPomPom(int pp) {
    PomPom = pp;
}

void Kosar::kiir() {
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Kosar& rhs_k) {
    os << "Kosarcsapat " << (Csapat&)rhs_k << ", Pom-Pom lanyok: " << rhs_k.getPomPom();
    return os;
}

void Kosar::fba(const char* fname) {
    std::string nev(getNev());
    std::replace(nev.begin(), nev.end(), ' ', ';');

    std::ofstream file;
    file.open(fname, std::fstream::app);

    if(file.is_open()) {
        file << "3 " << nev << " " << this->getTagok() << " " << PomPom << std:: endl;
        file.close();
    } else {throw "Nem lehetett megnyitni a fajlt!";}
}

Kosar::~Kosar() {}
