//  main.cpp
//  Impiccato1.0

//  Created by Lorenzo Montanaro on 25/01/2020.
//  Copyright © 2020 Lorenzo Montanaro. All rights reserved.


//LIBRERIE
#include <iostream>
//#include <stdlib.h>   //import for clear screen functionality
using namespace std;

//VARIABILI
const int x = 10;

char parola[x];
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
char parolaN[x];
char lettera;


//FUNZIONI
void Disegno()
{
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
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

void ParolaNascosta()
{
    for (int j = 0; parola[j] != '\0'; j++)
        parolaN[j] = '_';

    for (int i = 'a'; i < 'z'; i++)
        if (parola[0] == i) parolaN[0] = i;

    //{
    //    if (parola[0] == 'a') parolaN[0] = 'a';
    //    if (parola[0] == 'b') parolaN[0] = 'b';
    //    if (parola[0] == 'c') parolaN[0] = 'c';
    //    if (parola[0] == 'd') parolaN[0] = 'd';
    //    if (parola[0] == 'e') parolaN[0] = 'e';
    //    if (parola[0] == 'f') parolaN[0] = 'f';
    //    if (parola[0] == 'g') parolaN[0] = 'g';
    //    if (parola[0] == 'h') parolaN[0] = 'h';
    //    if (parola[0] == 'i') parolaN[0] = 'i';
    //    if (parola[0] == 'j') parolaN[0] = 'j';
    //    if (parola[0] == 'k') parolaN[0] = 'k';
    //    if (parola[0] == 'l') parolaN[0] = 'l';
    //    if (parola[0] == 'm') parolaN[0] = 'm';
    //    if (parola[0] == 'n') parolaN[0] = 'n';
    //    if (parola[0] == 'o') parolaN[0] = 'o';
    //    if (parola[0] == 'p') parolaN[0] = 'p';
    //    if (parola[0] == 'q') parolaN[0] = 'q';
    //    if (parola[0] == 'r') parolaN[0] = 'r';
    //    if (parola[0] == 's') parolaN[0] = 's';
    //    if (parola[0] == 't') parolaN[0] = 't';
    //    if (parola[0] == 'u') parolaN[0] = 'u';
    //    if (parola[0] == 'v') parolaN[0] = 'v';
    //    if (parola[0] == 'w') parolaN[0] = 'w';
    //    if (parola[0] == 'x') parolaN[0] = 'x';
    //    if (parola[0] == 'y') parolaN[0] = 'y';
    //    if (parola[0] == 'z') parolaN[0] = 'z';
    //}

    cout << parolaN << "\n\n\n\n";
}

void inputLettera()
{
    cout << "Dimmi una lettera" << endl;
    cin >> lettera;
}

void checkLettera()
{
    int err = 0,
        ok = 0;
    char Tab[6][3] = {  {'2','8','O'},
                        {'3','8','|'},
                        {'3','7','/'},
                        {'3','9','\\'},
                        {'4','7','/'},
                        {'4','9','\\'}  };

    for (int i = 0; parola[i] != '\0'; i++)
        if (lettera == parola[i]) ok++;

    if (ok != 0)
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
        ++err;
        Draw[Tab[err - 1][0]][Tab[err - 1][1]] = Tab[err - 1][2];
    }
}

inline void aggiornaParolaNascosta() { cout << parolaN << endl; }

void checkWin(bool& win)
{
    int count = 0;

    for (int i = 0; i < 10; i++)
        if (parola[i] == parolaN[i])    count++;

    if (count >= 9)
    {
        win = true;
        cout << "Hai vinto!\n";
    }
}

//MAIN
int main()
{
    bool winCheck = false;

    cout << "Scrivi una parola(al massimo 10 lettere)\n";
    cin >> parola;

    Pulisci();

    ParolaNascosta();

    do
    {
        aggiornaParolaNascosta();
        Disegno();
        inputLettera();
        checkLettera();
        checkWin(winCheck);
        Pulisci();
    } while (winCheck == 0);

    return 0;
}
