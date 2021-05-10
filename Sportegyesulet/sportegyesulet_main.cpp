/**
 *  \file sportegyesulet_mail.cpp
 *  Demó a program kipróbálására
 */

#include <iostream>
#include <cstring>

#include "csapat.h"
#include "foci.h"
#include "kosar.h"
#include "kezi.h"
#include "adatbazis.h"
#include "gtest_lite.h"
#include "memtrace.h"
using namespace std;

void runtest();

void teszt() {
    Adatbazis tmp;
    tmp.fbol("Teszt.txt");
    //tmp.listaz();

    TEST(Adatbazis, Fajlbol) {
        EXPECT_EQ("Teszt0", tmp[0]->getNev());
        EXPECT_EQ(0, tmp[0]->getTagok());
        EXPECT_THROW(tmp[0]->getPomPom(), const char*);
        EXPECT_TRUE(tmp.keres(tmp[0]->getNev()));
        EXPECT_EQ("Teszt6", tmp[6]->getNev());
        EXPECT_EQ(6, tmp[6]->getTagok());
        EXPECT_EQ(66, tmp[6]->getPomPom());
        EXPECT_THROW(tmp[6]->getEdzo1(), const char*);
        EXPECT_TRUE(tmp.keres(tmp[6]->getNev()));
        size_t tmp_size = 10;
        EXPECT_EQ(tmp_size, tmp.amount());
        EXPECT_EQ(tmp_size, tmp.size());
    } END
    TEST(Adatbazis, Index) {
        EXPECT_NO_THROW(tmp[0]);
        EXPECT_NO_THROW(tmp[9]);
        EXPECT_THROW(tmp[10], const char*);
        EXPECT_THROW(tmp[-1], const char*);
    }END
    TEST(Adatbazis, Felvesz) {
        {Csapat* tmpcs = new Csapat("Teszt10", 10);
        tmp.felvesz(tmpcs);}
        EXPECT_NO_THROW(tmp[10]);
        EXPECT_EQ("Teszt10", tmp[10]->getNev());
        EXPECT_EQ(10, tmp[10]->getTagok());
        EXPECT_THROW(tmp[10]->getPomPom(), const char*);
    }END
    TEST(Adatbazis, Keres) {
        EXPECT_TRUE(tmp.keres("Teszt0"));
        EXPECT_FALSE(tmp.keres("Teszt11"));
    }END
    TEST(Adatbazis, Meretek) {
        EXPECT_EQ(11, tmp.size());
        EXPECT_EQ(11, tmp.amount());
        EXPECT_EQ(10+9+8+7+6+5+4+3+2+1, tmp.letszam());
    }END
    TEST(Adatbazis, Ertekadas) {
        Adatbazis db;
        db = tmp;
        EXPECT_EQ(tmp.size(), db.size());
        EXPECT_EQ(tmp.amount(), db.amount());
        for(size_t i = 0; i < db.amount(); i++){
            EXPECT_EQ(tmp[i]->getNev(), db[i]->getNev());
            EXPECT_EQ(tmp[i]->getTagok(), db[i]->getTagok());
        }
    }END

    return;
}

void mode2(Adatbazis& db) {

    cout << "\nMit szeretne csinalni?\n\t(1)Adatbazis listazasa\n\t(2)Csapat felvetele\n\t(3)Csapat keresese\n\t(4)Csapat torlese" << endl;
    cout << "\t(5)A sportegyesulet teljes lezszamanak lekerdezese\n\t(0)Visszateres a menube" << endl;
    int mode;
    string keres;
    while (true) {
        cin >> mode;
        if (!cin || mode < 0 || mode > 5) {
            cout << "\n****Hibas ertek. Uj szamot kerek.****" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch(mode){
        case 0:
            return;
        case 1:
            db.listaz();
            cout << "\nMit szeretne csinalni?\n\t(1)Adatbazis listazasa\n\t(2)Csapat felvetele\n\t(3)Csapat keresese\n\t(4)Csapat torlese" << endl;
            cout << "\t(5)A sportegyesulet teljes lezszamanak lekerdezese\n\t(0)Visszateres a menube" << endl;
            break;
        case 2:
            cout << "\nMilyen tipusu csapatot?\n\t(1)Csapat\n\t(2)Foci\n\t(3)Kezi\n\t(4)Kosar\n\t(0)Visszalepes" << endl;
            cin >> mode;
            if(mode == 1) {
                string nev;
                int tag;
                cout << "\nCsapat felvetele:";
                Csapat tempcs;
                cout << "\nCsapatnev: "; cin >> nev; tempcs.setNev(nev);
                cout << "\nTagok: "; cin >>tag; tempcs.setTagok(tag);
                db.felvesz(tempcs.clone());
            }
            if(mode == 2) {
                string nev, e1, e2;
                int tag;
                cout << "Foci csapat felvetele:";
                Foci tempcs;
                cout << "\nCsapatnev: "; cin >> nev; tempcs.setNev(nev);
                cout << "\nTagok: "; cin >>tag; tempcs.setTagok(tag);
                cout << "\nEdzo1: "; cin >> e1; tempcs.setEdzo1(e1);
                cout << "\nEdzo2: "; cin >> e2; tempcs.setEdzo2(e2);
                db.felvesz(tempcs.clone());
            }
            if(mode == 3) {
                string nev;
                int tag, tam;
                cout << "Kezi csapat felvetele:";
                Kezi tempcs;
                cout << "\nCsapatnev: "; cin >> nev; tempcs.setNev(nev);
                cout << "\nTagok: "; cin >>tag; tempcs.setTagok(tag);
                cout << "\nTamogatas(Ft): "; cin >> tam; tempcs.setTamogatas(tam);
                db.felvesz(tempcs.clone());
            }
            if(mode == 4) {
                string nev;
                int tag, ppl;
                cout << "Kezi csapat felvetele:";
                Kosar tempcs;
                cout << "\nCsapatnev: "; cin >> nev; tempcs.setNev(nev);
                cout << "\nTagok: "; cin >>tag; tempcs.setTagok(tag);
                cout << "\nPom-Pom lanyok: "; cin >> ppl; tempcs.setPomPom(ppl);
                db.felvesz(tempcs.clone());
            }
            cout << "\nMit szeretne csinalni?\n\t(1)Adatbazis listazasa\n\t(2)Csapat felvetele\n\t(3)Csapat keresese\n\t(4)Csapat torlese" << endl;
            cout << "\t(5)A sportegyesulet teljes lezszamanak lekerdezese\n\t(0)Visszateres a menube" << endl;
            break;
        case 3:
            cout << "\nCsapat keresese..." << endl;
            cout << "\nKeresendo csapat neve: ";
            cin >> keres;
            if(db.keres(keres)) {cout << "Van " << keres << " nevu csapat." << endl;}
            else {cout << "Nincs " << keres << " nevu csapat.";}
            cout << "\nMit szeretne csinalni?\n\t(1)Adatbazis listazasa\n\t(2)Csapat felvetele\n\t(3)Csapat keresese\n\t(4)Csapat torlese" << endl;
            cout << "\t(5)A sportegyesulet teljes lezszamanak lekerdezese\n\t(0)Visszateres a menube" << endl;
            break;
        case 4:
            cout << "\nCsapat torlese." << endl;
            db.listaz();
            cout << "Torlendo csapat neve:";
            cin >> keres;
            db.torol(keres);
            cout << "Nincs tobbe a(z) " << keres << "nevu csapat az adatbazisban." << endl;
            cout << "\nMit szeretne csinalni?\n\t(1)Adatbazis listazasa\n\t(2)Csapat felvetele\n\t(3)Csapat keresese\n\t(4)Csapat torlese" << endl;
            cout << "\t(5)A sportegyesulet teljes lezszamanak lekerdezese\n\t(0)Visszateres a menube" << endl;
            break;
        case 5:
            cout << "\nA sportegyesulet teljes letszama: " << db.letszam() << " fo." << endl;
            cout << "\nMit szeretne csinalni?\n\t(1)Adatbazis listazasa\n\t(2)Csapat felvetele\n\t(3)Csapat keresese\n\t(4)Csapat torlese" << endl;
            cout << "\t(5)A sportegyesulet teljes lezszamanak lekerdezese\n\t(0)Visszateres a menube" << endl;
            break;
        default:
            break;
        }
    }
}




///Főprogram standard inputról olvas egész számot, majd
///meghívja az annak megfelelő tesztesetet

int main() {
    #ifdef CPORTA
    runtest()
    #else

    cout << "Mit szeretne csinalni?\n\t(1)Tesztek futtatasa\n\t(2)Program hasznalata\n\t(0)Kilepes" << endl;
    int mode = 0;
    Adatbazis temp;
    temp.fbol("Teszt.txt");
    while (true) {
        cin >> mode;
        if (!cin || mode < 0 || mode > 2) {
            cout << "\n****Hibas ertek. Uj szamot kerek.****" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
            }

        switch(mode) {
        case 0:     ///Kilépés
            temp.fba("Data2.txt");
            return 0;
        case 1:     ///Tesztek futtatása
            teszt();
            cout << "\nMit szeretne csinalni?\n\t(1)Tesztek futtatasa\n\t(2)Program hasznalata\n\t(0)Kilepes" << endl;
            break;
        case 2:     ///Program használata
            mode2(temp);
            cout << "\nMit szeretne csinalni?\n\t(1)Tesztek futtatasa\n\t(2)Program hasznalata\n\t(0)Kilepes" << endl;
            break;
        default:
            break;
        }
    }




    #endif // CPORTA

    return 0;
}

