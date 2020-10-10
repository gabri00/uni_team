//
//  main.cpp
//  Impiccato1.0
//
//  Created by Lorenzo Montanaro on 25/01/2020.
//  Copyright © 2020 Lorenzo Montanaro. All rights reserved.
//

//                                LIBRERIE
#include <iostream>
using namespace std;

//                                VARIABILI
char parola[10];
char Draw[10][10]= {
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
char parolaN[10];
bool winCheck = 0;
char lettera ;
int err =0;
char Tab [6][3] = { {'2','8','O'},
                    {'3','8','|'},
                    {'3','7','/'},
                    {'3','9','\\'},
                    {'4','7','/'},
                    {'4','9','\\'},
    
};

//                                FUNZIONI
void Disegno(){
    for (int r = 0 ; r<10; r++){
        for (int c = 0 ; c<10; c++){
            cout << Draw[r][c];
        } cout << endl ;
    };
}

void Pulisci(){
    for (int i = 0; i<25;i++)
        cout << endl ;
}

void ParolaNascosta(){
    for (int j= 0;parola[j]!='\0';j++){
        parolaN[j] = '_';
    }
    
    if (parola[0]=='a') parolaN[0]='a';
    if (parola[0]=='b') parolaN[0]='b';
    if (parola[0]=='c') parolaN[0]='c';
    if (parola[0]=='d') parolaN[0]='d';
    if (parola[0]=='e') parolaN[0]='e';
    if (parola[0]=='f') parolaN[0]='f';
    if (parola[0]=='g') parolaN[0]='g';
    if (parola[0]=='h') parolaN[0]='h';
    if (parola[0]=='i') parolaN[0]='i';
    if (parola[0]=='j') parolaN[0]='j';
    if (parola[0]=='k') parolaN[0]='k';
    if (parola[0]=='l') parolaN[0]='l';
    if (parola[0]=='m') parolaN[0]='m';
    if (parola[0]=='n') parolaN[0]='n';
    if (parola[0]=='o') parolaN[0]='o';
    if (parola[0]=='p') parolaN[0]='p';
    if (parola[0]=='q') parolaN[0]='q';
    if (parola[0]=='r') parolaN[0]='r';
    if (parola[0]=='s') parolaN[0]='s';
    if (parola[0]=='t') parolaN[0]='t';
    if (parola[0]=='u') parolaN[0]='u';
    if (parola[0]=='v') parolaN[0]='v';
    if (parola[0]=='w') parolaN[0]='w';
    if (parola[0]=='x') parolaN[0]='x';
    if (parola[0]=='y') parolaN[0]='y';
    if (parola[0]=='z') parolaN[0]='z';

    
    cout << parolaN << endl ;
    
    cout << endl ;
    cout << endl ;
    cout << endl ;
    
}

void immssioneLettera(){
    cout << "Dimmi una lettera" << endl ;
    cin >> lettera ;
}

void checkLettera()
{
    int ok = 0;
    
    for (int i =0; parola[i]!='\0'; i++)
    {
        if (lettera==parola[i]) ok++;
    }
    
    if (ok != 0)
    {
        for (int j=0;parola[j]!='\0';j++)
        {
            if(lettera==parola[j])  parolaN[j]=lettera;
        }
        
    }
    else
    { cout << "Ops la lettera inserita non è presente nella parola!" << endl;
        ++err;
        Draw[Tab[err-1][0]][Tab[err-1][1]]= Tab[err-1][2];
    }
    
    
    
}

inline void aggiornaParolaNascosta()
{
    cout << parolaN << endl ;
}

void checkWin()
{
    for (int i = 0; i<10; i++)
        if (parola[i]==parolaN[i]){cout << "Hai vinto!" << endl;}
            }

//                                  MAIN
int main() {
    
    cout << "Scrivi una parola(al massimo 10 lettere)" << endl ;
    cin >> parola;
    Pulisci();
    
    
    
    
    ParolaNascosta();
    do {
        aggiornaParolaNascosta();
        
        Disegno();
        immssioneLettera();
        checkLettera();
        //checkWin();
        Pulisci();
    }while (winCheck==0);
    
    return 0;
}
