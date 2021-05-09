/**
 *  \file adatbazis.cpp
 *  Adatbazis osztály tagfüggvényeinek megvalósítása
 */

#include "adatbazis.h"
#include "memtrace.h"

Adatbazis& Adatbazis::operator=(const Adatbazis& rhs) {
    if(this != &rhs) {
        for(size_t i = 0; i < nCsapat; i++) {
            delete *(Csapatok+i);
        }
        delete[] Csapatok;
        Meret = rhs.Meret;
        nCsapat = 0;
        Csapatok = new Csapat*[Meret];
        for(size_t i = 0; i < rhs.nCsapat; i++) {
            Csapatok[i] = rhs.Csapatok[i];
            nCsapat++;
        }
    }
    return *this;
}

bool Adatbazis::keres(std::string str) {
    for(size_t i = 0; i < nCsapat; i++) {
        if(str == Csapatok[i]->getNev()) return true;
    }
    return false;
}

void Adatbazis::felvesz(Csapat* cs) {
    if(keres(cs->getNev())) {
        std::cout << "Mar letezik ilyen nevu csapat" << std::endl;
        delete cs;
        return;
    }
    if(nCsapat < Meret) {
        Csapatok[nCsapat++] = cs;
    } else {
        Adatbazis temp(Meret+3);
        for(size_t i = 0; i < nCsapat; i++) {
            temp.Csapatok[i] = Csapatok[i];
            temp.nCsapat++;
        }
        temp.Csapatok[nCsapat] = cs;
        Meret = temp.Meret;

        for(size_t i = 0; i < temp.nCsapat; i++) {
            Csapatok[i] = temp.Csapatok[i];
        }
        nCsapat++;
    }
}



void Adatbazis::torol(std::string str) {
    std::string temp;
    for(size_t i = 0; i < nCsapat; i++) {
        temp = Csapatok[i]->getNev();
        if(temp == str) {
            delete *(Csapatok+i);
            for(size_t n = i; n < nCsapat; n++){
                Csapatok[n] = Csapatok[n+1];
            }
        }
    }
    nCsapat--;
}

int Adatbazis::letszam() {
    int ret = 0;
    for(size_t i = 0; i < nCsapat; i++) {
        ret += Csapatok[i]->getTagok();
    }
    return ret;
}

void Adatbazis::listaz() {
    std::cout << "\nCsapatok szama: " << amount() << std::endl;
    if(amount() == 0) return;
    std::cout << "Csapatok listazasa:" << std::endl;
    for(size_t i = 0; i < nCsapat; i++) {
        Csapatok[i]->kiir();
    }
}



void Adatbazis::fbol(const char* fname) {
    int i, tag, tam, ppl;
    std::string nev,  e1, e2;
    std::ifstream file;
    file.open(fname, std::ios::in);
    if(file.is_open()) {
         while(!file.eof()){
            file >> i >> nev >> tag >> e1 >> e2 >> tam >> ppl;
            std::replace(nev.begin(), nev.end(), ';', ' ');
            std::replace(e1.begin(), e1.end(), ';', ' ');
            std::replace(e2.begin(), e2.end(), ';', ' ');
            switch(i){
                case 0:         ///Csapat
                    felvesz(new Csapat(nev, tag));
                    break;
                case 1:         ///Foci
                    felvesz(new Foci(nev, e1, e2, tag));
                    break;
                case 2:         ///Kezi
                    felvesz(new Kezi(nev, tag, tam));
                    break;
                case 3:         ///Kosar
                    felvesz(new Kosar(nev, tag, ppl));
                    break;
                default:
                    break;
            }

         }
    }
    file.close();
}

void Adatbazis::fba(const char* fname) {
    std::ofstream file;
    file.open(fname, std::ios::out);
    if(file.is_open()) {} else {throw "Nem lehetett megnyitni a fajlt!";}
    file.close();
    for(size_t i = 0; i < nCsapat; i++) {
        Csapatok[i]->fba(fname);
    }
    file.open(fname, std::fstream::app);
    if(file.is_open()) {file << "-1"; file.close();}
    else {throw "Nem lehetett megnyitni a fajlt!";}
}


