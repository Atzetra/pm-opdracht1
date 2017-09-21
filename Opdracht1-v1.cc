// Enzo Sastrokarijo (s1993895) & Daniël Zee
// Programmeermethoden 2017-2018

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main(){

    string aanhef;
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

    
    int dagAdd = 0;

    for (int k=1901; k < geboortejaar; k++){
        if (k % 4 ==0){
           dagAdd += 366;
        }
        else{
            dagAdd += 365;
        }
    }

    for(int i=1; i < (geboortemaand); i++){
        switch (i){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                dagAdd += 31;  
            break;
            case 2:{
                if (geboortejaar % 4 == 0){
                    dagAdd += 29;
                }
                else{
                    dagAdd += 28;
                }
            }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                dagAdd += 30;
                break;
        }
    }

    // Aangezien de eerste van de maand al 1 is, tellen vanaf 0
    dagAdd += geboortedag - 1;

    cout << dagAdd;

    int dagnummer = dagAdd % 7;




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

    int dagcheck;
    char letter1;
    char letter2;
    cout << "Voer de eerste letter van de dag in:" << endl;
    cin >> letter1;


        if (letter1 == 'd' || letter1 == 'z'){
            cout << "Voer de tweede letter van de dag in:" << endl;
            cin >> letter2;

            if (letter1 == 'd' && letter2 == 'i'){
                dagcheck = 0;
            }
            else if (letter1 == 'd' && letter2 == 'o'){
                dagcheck = 2;
            }
            else if (letter1 == 'z' && letter2 == 'a'){
                dagcheck = 4;
            }
            else if (letter1 == 'z' && letter2 == 'o'){
                dagcheck = 5;
            }
            else{
                return 1;
            }
            
        }
        else if (letter1 == 'm'){
            dagcheck = 6;
        }
        else if (letter1 == 'w'){
            dagcheck = 1;
        }
        else if (letter1 == 'v'){
            dagcheck = 3;
        }

        if (dagcheck == dagnummer){
            cout << "Zeker aan uw/je moeder gevraagd?" << endl;
        }
        else{
            return 1;
        }

        if (leeftijdJaar >= 30){
            aanhef = 'u';
        }
        else{
            aanhef = "je";
        }


        int hdag, hmaand, hjaar;
        

    return 0;

} //main