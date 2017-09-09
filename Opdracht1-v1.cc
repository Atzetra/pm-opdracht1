// Enzo Sastrokarijo (s1993895) & Daniël Zee
// Programmeermethoden 2017-2018

#include <iostream>
#include <ctime>

using namespace std;

int main(){

    int geboortejaar, geboortemaand, geboortedag;

    cin >> geboortejaar >> geboortemaand >> geboortedag;

    // Testregel om uit te vindeb of de variabelen goed binnenkomen
    cout << geboortejaar << " " << geboortemaand << " " << geboortedag;

    if (geboortemaand > 12 || geboortemaand < 1){
        return 1;
    }

    // Ctime om datum uit te vinden

    int hdag, hmaand, hjaar;

    // Hulpvariabelen voor ctime
    tm s;
    time_t t;

    // Calculatie datum
    time (&t);
    s = ` localtime (&t);
    hdag = s.tm_mday;
    hmaand = s.tm_mon + 1;      // Januari is 0, dus + 1
    hjaar = s.tm_year + 1900;   // Telt vanaf 1900, dus + 1900
    
    return 0;


    //test
} //main