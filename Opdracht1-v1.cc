// Enzo Sastrokarijo (s1993895) & Daniël Zee
// Programmeermethoden 2017-2018

#include <iostream>
#include <ctime>

using namespace std;

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

    // Berekening voor leeftijd
    leeftijdCombo = hMaandtotaal - jTotaal;
    leeftijdJaar = leeftijdCombo / 12;
    leeftijdMaand = leeftijdCombo % 12;

    cout << leeftijdJaar << " jaar en " << leeftijdMaand <<" maanden; " << leeftijdCombo << " maanden." << endl;

    if (hdag == geboortedag && hmaand == geboortemaand){

        cout << "Fijne verjaardag!" << endl;
    }
    else if (hdag == geboortedag){

        cout << "Fijne vermaanddag!" << endl;
    }

    // Leeftijdscontrole voor toelating
    if (leeftijdJaar < 10 || leeftijdJaar > 100){

        cout << "U valt helaas niet in de leeftijdscategorie om naar de universiteit te gaan." << endl;
        return 1;
    }

    
    int maandAdd = 1;

    for (int k=1901; k < geboortejaar; k++){
        if (k % 4 ==0){
           maandAdd += 366;
        }
        else{
            maandAdd += 365;
        }
    }

    for(int i=1; i < (geboortemaand); i++){
        switch (1){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                maandAdd += 31;  
            break;
            case 2:
                if (geboortejaar % 4 == 0){
                    maandAdd += 29;
                }
                else{
                    maandAdd += 28;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                maandAdd += 30;
                break;
        }
    }

    maandAdd += geboortedag;


    int dagnummer = maandAdd % 7;



    switch (dagnummer){
        case 0: 
            cout << "di" << endl;
            break;
        case 1: 
            cout << "w" << endl;
            break;
        case 2: 
            cout << "do" << endl;
            break;
        case 3: 
            cout << "v" << endl;
            break;
        case 4: 
            cout << "za" << endl;
            break;
        case 5: 
            cout << "zo" << endl;
            break;
        case 6: 
            cout << "m" << endl;
            break;
    }
    


    return 0;

} //main