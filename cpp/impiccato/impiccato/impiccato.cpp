//  Created by Lorenzo Montanaro

//upgrades:
//si potrebbe implementare che la parola inizale sia casuale e non che venga inserita dall'utente
//una blacklist delle lettere già provate, così da evitare che vengano reinserite

//LIBRERIE
#include <iostream>
#include <string>
//#include <random>     //import for random word
//#include <stdlib.h>   //import for clear screen functionality

using namespace std;

//MACRO DEFINITION
#define ROWS    7
#define COLS    5
#define MAX_WORDS   20


struct screen
{
    char draw[ROWS][COLS] = {
    {'_', '_', '_', '_', ' '},
    {'|', ' ', ' ', '|', ' '},
    {'|', ' ', ' ', ' ', ' '},
    {'|', ' ', ' ', ' ', ' '},
    {'|', ' ', ' ', ' ', ' '},
    {'|', ' ', ' ', ' ', ' '},
    {'|', '_', '_', '_', '_'} };

    void disegna()
    {
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
                cout << draw[r][c];
            cout << '\n';
        }
    }

    void pulisci_terminal()
    {
        //system("clear");    //for linux
        //system("cls");      //for windows
        for (int i = 0; i < 25; i++)    cout << '\n';
    }
};


inline void upToLow(char& c)
{
    if (c >= 'A' && c <= 'Z')
        c = c - 'A' + 'a';
}

inline void updateBlacklist(const char lettera, string* blacklist)
{
    *blacklist += lettera;
}

//int randomWord()
//{
//    auto rand = std::uniform_int_distribution<int>(1, MAX_WORDS);
//    std::mt19937 rng = std::mt19937(std::random_device{}());
//
//    return rand(rng);
//}

void parolaNascosta(const string& p, string& pn)
{
    for (int i = 0; i < p.size(); i++)  pn += '_';

    pn[0] = p[0];
}

void inputLettera(char& lettera, string* blacklist)
{
    do
    {
        cout << "Inserisci una lettera: ";
        cin >> lettera;
        upToLow(lettera);
    } while (lettera < 'a' && lettera > 'z');

    updateBlacklist(lettera, blacklist);
}

const bool checkLettera(screen& sc, const char lettera, const string& p, string& pn)
{
    bool ok = false;
    static int bodyCount = 0;
    const char body[6] = {'O', '|', '/', '\\', '/', '\\'};

    for (int i = 0; i < p.size(); i++)
    {
        if (lettera == p[i])
        {
            pn[i] = lettera;
            ok = true;
        }
    }

    if (!ok)
    {
        bodyCount++;
        cout << "Ops la lettera inserita non è presente nella parola!\n";

        if (bodyCount == 1 || bodyCount == 2)
            sc.draw[2 + bodyCount - 1][COLS - 2] = body[bodyCount - 1];
        else if (bodyCount == 3)
            sc.draw[bodyCount][COLS - 3] = body[bodyCount - 1];
        else if (bodyCount == 4)
            sc.draw[bodyCount - 1][COLS - 1] = body[bodyCount - 1];
        else if (bodyCount == 5)
            sc.draw[bodyCount - 1][COLS - 3] = body[bodyCount - 1];
        else if (bodyCount == 6)
            sc.draw[bodyCount - 2][COLS - 1] = body[bodyCount - 1];

        if (bodyCount >= 6)
        {
            sc.pulisci_terminal();
            sc.disegna();
            return true;
        }
        else   return false;
    }
    else    return false;
}

void checkWin(bool& win, const string p, const string pn)
{
    if (p.size() == pn.size() && p == pn)
    {
        win = true;
        cout << "Hai vinto!\n";
    }
}

inline void printBlacklist(const string blacklist)
{
    cout << blacklist << '\n';
}

int main()
{
    screen sc;
    bool winCheck = false;
    char lettera;
    string parola, parolaN;
    string blacklist;

    cout << "Scrivi una parola: ";
    cin >> parola;

    for (int i = 0; i < parola.size(); i++)
        upToLow(parola[i]);

    sc.pulisci_terminal();

    parolaNascosta(parola, parolaN);

    do
    {
        cout << parolaN << '\n';
        printBlacklist(blacklist);
        sc.disegna();
        inputLettera(lettera, &blacklist);
        if (checkLettera(sc, lettera, parola, parolaN))
        {
            cout << "\n\nHai perso!\n";
            break;
        }
        sc.pulisci_terminal();
        checkWin(winCheck, parola, parolaN);
    }
    while (!winCheck);

    return 0;
}