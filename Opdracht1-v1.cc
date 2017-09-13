// Enzo Sastrokarijo (s1993895) & Daniël Zee
// Programmeermethoden 2017-2018

#include <iostream>
#include <ctime>

using namespace std;

void calcLeeftijd(int& a, int& b, int&c, int& d, int& e);

int main(){

    int geboortejaar, geboortemaand, geboortedag;

    cin >> geboortejaar >> geboortemaand >> geboortedag;

    // Testregel om uit te vinden of de variabelen goed binnenkomen
    // cout << geboortejaar << " " << geboortemaand << " " << geboortedag;

    // Controle voor geldigheid maand
    if (geboortemaand > 12 || geboortemaand < 1){
        return 1;
    }

    int jTotaal = geboortemaand + geboortejaar * 12;

    // Ctime om datum uit te vinden

    int hdag, hmaand, hjaar;

    // Hulpvariabelen voor ctime
    tm s;
    time_t t;

    // Calculatie datum
    time (&t);
    s = * localtime (&t);
    hdag = s.tm_mday;
    hmaand = s.tm_mon + 1;      // Januari is 0, dus + 1
    hjaar = s.tm_year + 1900;   // Telt vanaf 1900, dus + 1900

    int hMaandtotaal = hmaand + hjaar * 12;

    int leeftijdJaar, leeftijdMaand, leeftijdCombo;

    calcLeeftijd(hMaandtotaal, jTotaal, leeftijdJaar, leeftijdMaand, leeftijdCombo);

    cout << leeftijdJaar << " jaar en " << leeftijdMaand <<" maanden; " << leeftijdCombo << " maanden." << endl;

    if (hdag == geboortedag && hmaand == geboortemaand){

        cout << "Fijne verjaardag!" << endl;
    }
    else if (hdag == geboortedag){

        cout << "Fijne vermaanddag!" << endl;
    }

    // Leeftijdscontrole voor toelating
    if (leeftijdJaar < 10 || leeftijdJaar > 100){

        cout << "U valt helaas niet in de categorie om naar de universiteit te gaan." << endl;
        return 1;
    }
    

    return 0;


    //test
} //main

void calcLeeftijd(int& a, int& b, int&c, int& d, int& e){
    
    e = a - b;
    c = e / 12;
    d = e % 12;

}