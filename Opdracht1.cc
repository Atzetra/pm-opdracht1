#include <iostream>
#include <ctime>
using namespace std;

int leeftijdOutputMaanden(int x, int y);

int main()
{

    tm s;
    time_t t;

    //Opslaan datum uit cmake in variabelen
    int dag, maand, jaar;
    time(&t);
    s = *localtime(&t);
    dag = s.tm_mday;
    maand = s.tm_mon + 1;    // 0 voor januari, dus + 1 voor makkelijker gebruik
    jaar = s.tm_year + 1900; // Telt vanaf 1900, dus dit erbij om op het huidige jaar te komen

    int geboorteJaar = -1;  //Initialiseer variabel geboorteJaar met -1 om bij geen input niks terug te sturen
    int geboorteMaand = -1; //Idem voor geboorteMaand
    int geboorteDag = -1;   //Idem voor geboorteDag

    cin >> geboorteJaar;
    cin >> geboorteMaand;
    cin >> geboorteDag;

    geboorteJaar = geboorteJaar - jaar;

    // Controleren of maanden wel geldig zijn
    if (geboorteMaand > 12 || geboorteMaand < 1)
    {

        return 1;
    }

    //cout << geboorteJaar << " " << geboorteMaand;

    int totaalMaanden = leeftijdOutputMaanden(geboorteJaar, geboorteMaand);

    cout << geboorteJaar << " jaar " << geboorteMaand << " maanden, " << totaalMaanden << " maanden." << endl;

    //Uitvinden datum m.b.v. ctime

    if (geboorteDag == dag && geboorteMaand == maand)
    {
        cout << "Fijne Verjaardag!" << endl;
    }
    else if (geboorteDag == dag)
    {
        cout << "Fijna vermaanddag!" << endl;
    }

    return 0;
}

int leeftijdOutputMaanden(int x, int y)
{
    int maandJaar = x * 12;
    int maandtotaal = maandJaar + y;

    return maandtotaal;
}