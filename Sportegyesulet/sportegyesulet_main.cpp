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



///Főprogram standard inputról olvas egész számot, majd
///meghívja az annak megfelelő tesztesetet

int main() {
    #ifdef CPORTA

    #else
    {
    Adatbazis temp(1);
    temp.fbol("Data.txt");
    //temp.torol("FTC");
    Adatbazis temp2;
    temp2 = temp;
    temp.listaz();
    temp2.listaz();
    temp.fba("Data2.txt");

    }
    std::cout << "siker";


    #endif // CPORTA

    return 0;
}

