#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string PlayerName;
int Computer ;
char Player ;
char stop ;

//hello 
void Intro (){
    cout << "Welcome! Insert your name \n";
    getline(cin, PlayerName) ;
    cout << PlayerName << " is very nice name dude!\n" ;
    cout << "Let's start!\n";
}

void InputPlayer (){
    cout << "Choose Rock, Paper o Scissor (R,P o S)" << endl ;
    cin >> Player ;
    Player = toupper(Player);
    while((Player!='R')&&(Player!='P')&&(Player!='S')){
        cout << PlayerName << " are you doumb? Just choose R,P or S" << endl ;
        cin >> Player ;
    }
}

void InputComputer(){
    Computer = rand() % 3;
    if (Computer == 0) Computer = 'R';
    if (Computer == 1) Computer = 'P';
    if (Computer == 2) Computer = 'S';
}

void WinCheck (){
    if((Computer=='R')&&(Player=='R'))
        cout << "TIE" << endl ;
    if((Computer=='P')&&(Player=='P'))
        cout << "TIE" << endl ;
    if((Computer=='S')&&(Player=='S'))
        cout << "TIE" << endl ;
    
    if((Computer=='R')&&(Player=='P'))
    cout <<PlayerName << " WIN" << endl ;
    if((Computer=='R')&&(Player=='S'))
    cout << "Computer WIN" << endl ;
    
    if((Computer=='P')&&(Player=='R'))
    cout << "Computer WIN" << endl ;
    if((Computer=='P')&&(Player=='S'))
    cout <<PlayerName<< " WIN" << endl ;
    
    if((Computer=='S')&&(Player=='R'))
    cout <<PlayerName<< " WIN" << endl ;
    if((Computer=='S')&&(Player=='P'))
    cout << "Computer WIN" << endl ;
    
}
int main() {
    Intro();
    do{
    InputPlayer();
    InputComputer();
    WinCheck();
    cout << "If you want to continue digit y" << endl ;
    cin >> stop;
    stop = toupper(stop);
    }while(stop=='Y');
    
    
    
    
    return 0;
}
