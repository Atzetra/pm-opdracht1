// Enzo Sastrokarijo (s1993895) & Daniël Zee(s2063131)
// Programmeermethoden 2017-2018
// g++ compiler zonder optimalisation flags (Fedora 26 (Linux))

// Dit programma test of een gebruiker geschikt is voor een studie
// aan Universiteit Leiden. Er zit een test in voor een beta en een alfa
// studie.

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    // Initialiseren rand met de tijd als seed
    srand(time(NULL));

    // Infoblok
    cout << "Enzo Sastrokarijo (s1993895) & Daniël Zee (" << endl;
    cout << "Programmeermethoden 2017-2018" << endl;
    cout << "Opgave 1\n" << endl;

    cout << "---\n" << endl;

    //Welkomstscherm
    cout << "Welkom bij de toelatingstest van Universiteit Leiden." << endl;
    cout << "Aan de hand van dit programma zoeken wij uit of een studie aan deze\nuniversiteit wel een geschikte keuze is.\n"
         << endl;

    string aanhef;
    int geboortejaar, geboortemaand, geboortedag;

    // Invoer geboortedatum
    cout << "Voer uw geboortejaar in: ";
    cin >> geboortejaar;
    cout << "Voer uw geboortemaand in: ";
    cin >> geboortemaand;

    // Controle voor geldigheid maand
    if (geboortemaand > 12 || geboortemaand < 1)
    {
        cout << "\nDat is geen geldige maand." << endl;
        cout << "Dit programma stopt nu." << endl;
        return 1;
    }

    // Continue invoer
    cout << "Voer uw geboortedag in: ";
    cin >> geboortedag;

    // Controle geldigheid datum
    switch (geboortemaand)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        if (geboortedag > 0 && geboortedag <= 31)
        {
            break;
        }
        else
        {
            cout << "\nDat is geen geldige datum!" << endl;
            cout << "Dit programma stopt nu." << endl;
            return 1;
            break;
        }
    }
    break;
    case 2:
    {
        if (geboortejaar % 4 == 0)
        {
            if (geboortedag > 0 && geboortedag <= 29)
            {
                break;
            }
            else
            {
                cout << "\nDat is geen geldige datum!" << endl;
                cout << "Dit programma stopt nu." << endl;
                return 1;
                break;
            }
        }
        else
        {
            if (geboortedag > 0 && geboortedag <= 28)
            {
                break;
            }
            else
            {
                cout << "\nDat is geen geldige datum!" << endl;
                cout << "Dit programma stopt nu." << endl;
                return 1;
                break;
            }
        }
    }
    break;
    case 4:
    case 6:
    case 9:
    case 11:
    {
        if (geboortedag > 0 && geboortedag <= 30)
        {
            break;
        }
        else
        {
            cout << "\nDat is geen geldige datum!" << endl;
            cout << "Dit programma stopt nu." << endl;
            return 1;
            break;
        }
    }
    }

    // Berekening aantal maanden vanaf geboorte
    int jTotaal = geboortemaand + geboortejaar * 12;

    // Ctime om datum uit te vinden
    int hdag, hmaand, hjaar;

    // Hulpvariabelen voor ctime
    tm s;
    time_t t;

    // Calculatie datum
    time(&t);
    s = *localtime(&t);
    hdag = s.tm_mday;
    hmaand = s.tm_mon + 1;    // Januari is 0, dus + 1
    hjaar = s.tm_year + 1900; // Telt vanaf 1900, dus + 1900

    int hMaandtotaal = hmaand + hjaar * 12;

    int leeftijdJaar, leeftijdMaand, leeftijdCombo;

    // Berekening voor leeftijd
    leeftijdCombo = hMaandtotaal - jTotaal;
    leeftijdJaar = leeftijdCombo / 12;
    leeftijdMaand = leeftijdCombo % 12;

    cout << "\n"
         << leeftijdJaar << " jaar en " << leeftijdMaand << " maanden; " << leeftijdCombo << " maanden.\n"
         << endl;

    // Berichtgeving bij verjaar- maanddag
    if (hdag == geboortedag && hmaand == geboortemaand)
    {

        cout << "Fijne verjaardag!\n"
             << endl;
    }
    else if (hdag == geboortedag)
    {

        cout << "Fijne vermaanddag!\n"
             << endl;
    }

    // Leeftijdscontrole voor toelating
    if (leeftijdJaar < 10 || leeftijdJaar > 100)
    {

        cout << "U valt helaas niet in de leeftijdscategorie om naar de universiteit te gaan." << endl;
        return 1;
    }

    int dagCalc = 0;

    for (int k = 1901; k < geboortejaar; k++)
    {
        if (k % 4 == 0)
        {
            dagCalc += 366;
        }
        else
        {
            dagCalc += 365;
        }
    }

    for (int i = 1; i < (geboortemaand); i++)
    {
        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dagCalc += 31;
            break;
        case 2:
        {
            if (geboortejaar % 4 == 0)
            {
                dagCalc += 29;
            }
            else
            {
                dagCalc += 28;
            }
        }
        break;
        case 4:
        case 6:
        case 9:
        case 11:
            dagCalc += 30;
            break;
        }
    }

    // Aangezien de eerste van de maand al 1 is, tellen vanaf 0
    dagCalc += geboortedag - 1;

    // Met modulus dag van week uitvinden
    int dagnummer = dagCalc % 7;

    int dagcheck;
    char letter1;
    char letter2;

    // Invoer voor dagcontrolle
    cout << "Voer de eerste letter van uw geboortedag in (bijvoorbeeld woensdag = w): ";
    cin >> letter1;
    cout << endl;

    // Extra letter voor tweeletterige dagen
    if (letter1 == 'd' || letter1 == 'z')
    {
        cout << "Voer de tweede letter van de dag in:";
        cin >> letter2;
        cout << endl;

        if (letter1 == 'd' && letter2 == 'i')
        {
            dagcheck = 0;
        }
        else if (letter1 == 'd' && letter2 == 'o')
        {
            dagcheck = 2;
        }
        else if (letter1 == 'z' && letter2 == 'a')
        {
            dagcheck = 4;
        }
        else if (letter1 == 'z' && letter2 == 'o')
        {
            dagcheck = 5;
        }
        else
        {
            return 1;
        }
    }
    else if (letter1 == 'm')
    {
        dagcheck = 6;
    }
    else if (letter1 == 'w')
    {
        dagcheck = 1;
    }
    else if (letter1 == 'v')
    {
        dagcheck = 3;
    }

    // Aanhef in string voor betere UX
    if (leeftijdJaar >= 30)
    {
        aanhef = 'u';
    }
    else
    {
        aanhef = "je";
    }

    // Controle dagtest
    if (dagcheck == dagnummer)
    {
        cout << "Correct, " << aanhef << " wordt nu naar de betastudie test gestuurd.\n"
             << endl;
    }
    else
    {
        return 1;
    }

    // Variabelen abc-test
    int a, b, c, oplossingen, input;
    double D;

    // rand() voor abc formule
    a = rand() % 40000;
    b = (rand() % 40000) - 20000;
    c = (rand() % 40000) - 20000;

    D = b ^ 2 - 4 * a * c;

    // Test voor het aantal oplossingen
    if (D < 0)
    {
        oplossingen = 0;
    }
    else if (D == 0)
    {
        oplossingen = 1;
    }
    else
    {
        oplossingen = 2;
    }

    cout << "Vul in hoeveel oplossingen " << aanhef << " denkt dat er zijn voor:\n"
         << a << "x² + " << b << "x + " << c << " = 0" << endl;

    cin >> input;

    if (input == oplossingen)
    {
        cout << "\nCorrect! Wij heten " << aanhef << " welkom bij deze betastudie aan Universiteit Leiden!" << endl;
        return 0;
    }

    // Begin van het "Alfablok"

    // Multiple choice vraag voor alfastudies
    else
    {
        cout << "\nDe algebrarische vraag is helaas niet goed ingevuld.\n\nNu wordt aan " << aanhef << " een vraag over kunst gesteld om te kijken\nof een alfa studie beter bij " << aanhef << " past." << endl;

        if (leeftijdJaar < 30)
        {
            cout << "\nDe vraag luidt: Welke van deze schilders is niet van Nederlandse afkomst?" << endl;
            cout << "A. Jan van Eyck" << endl;
            cout << "B. Rembrandt van Rijn" << endl;
            cout << "C. Piet Mondriaan" << endl;
            cout << "D. Vincent Van Gogh" << endl;
        }
        else
        {
            cout << "\nDe vraag luidt: Hoe heet het literaire werk over de slechte situatie in Nederlands Indië geschreven in de 19e eeuw?" << endl;
            cout << "A. Max Havelaar" << endl;
            cout << "B. Spinoza" << endl;
            cout << "C. De kleine Johannes" << endl;
            cout << "D. Ik kom terug" << endl;
        }

        cout << "\nVul het antwoord in: ";

        char lantwoord;
        cin >> lantwoord;

        switch (lantwoord)
        {
        case 'a':
        case 'A':
            cout << "Correct: Welkom bij de alfastudies aan de Universiteit Leiden!" << endl;
            break;
        default:
            cout << "\nHelaas, " << aanhef << " bent niet gekwalificeerd voor een studie aan de Universiteit Leiden." << endl;
            cout << "Het antwoord was: A." << endl;
            cout << "\nDit programma is nu ten einde gekomen." << endl;
            return 1;
            break;
        }
    }

    return 0;

} //main