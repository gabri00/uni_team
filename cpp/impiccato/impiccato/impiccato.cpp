//  main.cpp
//  Impiccato1.0

//  Created by Lorenzo Montanaro on 25/01/2020.
//  Copyright © 2020 Lorenzo Montanaro. All rights reserved.


//LIBRERIE
#include <iostream>     //import for basic i/o system
#include <string.h>     //import for strlen()
//#include <stdlib.h>   //import for clear screen functionality

//STANDARD NAMESPACE
using namespace std;

//VARIABILI
const int x = 10;

char parola[x];
char parolaN[x];

struct screen
{
    char Draw[x][x] = {
    {'_','_','_','_','_','_','_','_','_',' '},
    {'|',' ',' ',' ',' ',' ',' ',' ','|',' '},
    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {'|',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {'|','_','_','_','_','_',' ',' ',' ',' '}
    };

    void Disegno()
    {
        for (int r = 0; r < x; r++)
        {
            for (int c = 0; c < x; c++)
                cout << Draw[r][c];
            cout << '\n';
        }
    }

    void Pulisci()
    {
        //system("clear");    //for linux
        //system("cls");      //for windows
        for (int i = 0; i < 25; i++)    cout << '\n';
    }
};


void ParolaNascosta()
{
    for (int j = 1; parola[j] != '\0'; j++)
        parolaN[j] = '_';

    for (int i = 'a'; i <= 'z'; i++)
        if (parola[0] == i) parolaN[0] = i;
}

void upToLow(char& c)
{
    if (c >= 'A' && c <= 'Z')
        c = c - 'A' + 'a';
}

void inputLettera(char& lettera)
{
    cout << "Dimmi una lettera: ";
    cin >> lettera;
    upToLow(lettera);
}

void checkLettera(screen& sc, char lettera)
{
    bool ok = false;
    static int man = 0;
    const char Tab[6] = {'O', '|', '/', '\\', '/', '\\'};

    for (int i = 0; parola[i] != '\0'; i++)
    {
        if (lettera == parola[i])
        {
            ok = true;
            break;
        }
    }

    if (ok)
    {
        for (int j = 0; parola[j] != '\0'; j++)
        {
            if (lettera == parola[j])
                parolaN[j] = lettera;
        }
    }
    else
    {
        cout << "Ops la lettera inserita non è presente nella parola!\n";
        man++;
        sc.Draw[man + 2][x - 1] = Tab[man - 1];
    }
}

inline void aggiornaParolaNascosta() { cout << parolaN << '\n'; }

void checkWin(bool& win)
{
    int cnt = 0;

    for (int i = 0; i < 10; i++)
        if (parola[i] == parolaN[i])    cnt++;

    if (cnt >= 9)
    {
        win = true;
        cout << "Hai vinto!\n";
    }
}

//MAIN
int main()
{
    screen sc;
    bool winCheck = false;
    char lettera;

    do
    {
        cout << "Scrivi una parola(al massimo 10 lettere): ";
        cin >> parola;
        //cout << '\n';
    } while (strlen(parola) > 11);

    for (int i = 0; parola[i] != '\0'; i++)
        upToLow(parola[i]);

    sc.Pulisci();

    ParolaNascosta();

    do
    {
        aggiornaParolaNascosta();
        sc.Disegno();
        inputLettera(lettera);
        checkLettera(sc, lettera);
        checkWin(winCheck);
        sc.Pulisci();
    } while (!winCheck);

    return 0;
}
