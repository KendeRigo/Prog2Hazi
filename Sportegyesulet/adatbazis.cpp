/**
 *  \file adatbazis.cpp
 *  Adatbazis osztály tagfüggvényeinek megvalósítása
 */

#include "adatbazis.h"
#include "memtrace.h"

Adatbazis& Adatbazis::operator=(const Adatbazis& rhs) {
    if(this != &rhs) {
        delete[] Csapatok;
        Meret = rhs.Meret;
        nCsapat = rhs.nCsapat;
        Csapatok = new Csapat*[Meret];
        for(size_t i = 0; i < rhs.nCsapat; i++) {
            Csapatok[i] = rhs.Csapatok[i]->clone();
        }
    }
    return *this;
}


void Adatbazis::felvesz(Csapat* cs) {
    if(nCsapat < Meret) {
        Csapatok[nCsapat++] = cs;
    } else {
        Csapat** temp = new Csapat*[Meret+3];
        for(size_t i = 0; i < nCsapat; i++) {
            temp[i] = Csapatok[i];
        }

        temp[nCsapat++] = cs;
        Meret += 3;

        delete[] Csapatok;

        Csapatok = temp;
    }
}



void Adatbazis::torol(Csapat* cs) {
    for(size_t i = 0; i < nCsapat; i++) {
        if(Csapatok[i] == cs) {delete *(Csapatok+i);}
    }
}

int Adatbazis::letszam() {
    int ret = 0;
    for(size_t i = 0; i < nCsapat; i++) {
        ret += Csapatok[i]->getTagok();
    }
    return ret;
}

void Adatbazis::listaz() {
    std::cout << "\nCsapatok szama: " << nCsapat << std::endl;
    if(nCsapat == 0) return;
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
            file >> i >> nev >> tag;
            std::replace(nev.begin(), nev.end(), ';', ' ');
            switch(i){
                case 0:         ///Csapat
                    felvesz(new Csapat(nev, tag));
                    break;
                case 1:         ///Foci
                    file >> e1 >> e2;
                    std::replace(e1.begin(), e1.end(), ';', ' ');
                    std::replace(e2.begin(), e2.end(), ';', ' ');
                    felvesz(new Foci(nev, e1, e2, tag));
                    break;
                case 2:         ///Kezi
                    file >> tam;
                    felvesz(new Kezi(nev, tag, tam));
                    break;
                case 3:         ///Kosar
                    file >> ppl;
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


