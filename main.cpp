/*
 * Generatore pseudo-casuale di password.
 * Una password è dotata di 8 caratteri di cui PER FORZA:
 * 1 carattere minuscolo
 * 1 carattere maiuscolo
 * 1 numero
 * 1 simbolo
 * Aggiungere GUI
 *
 *
 *
 *
 * */
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <chrono>
#include <fstream>

using namespace std;

string stringAlphabet[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m",
                           "n","o","p","q","r","s","t","u","v","w","x","y","z",
                           "A","B","C","D","E","F","G","H","I","J","K","L","M",
                           "N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
                           "0","1","2","3","4","5","6","7","8","9",",",";","-","_","!","?",
                           "/","*","<",">","+","=","(",")","[","]","{","}","@","#","%","&","|"};

void createPassword(){

    ofstream pwFile;

    pwFile.open("listaPassword.txt", ofstream::app);

    int ra = 0;

    string stringPassword[8];

    int uppercaseCarNum = 0;

    int lowercaseCarNum = 0;

    int numberNum = 0;

    int symbolNum = 0;

    bool validPassword = false;

    srand(time(NULL));

    string nomeSito;

    string email;

    string nome;

    string cognome;

    string dataNascita;

    string userName;

    cout << "Inserisci il nome del sito per il quale ti serve la password"<<endl;
    getline(cin,nomeSito);
    cout<<endl;
    cout << "Inserisci l' email con cui ti sei registrato"<<endl;
    getline(cin,email);
    cout<<endl;
    cout<<"Inserisci il nome con cui ti sei registrato al sito"<<endl;
    getline(cin,nome);
    cout<<endl;
    cout<<"Inserisci il cognome con cui ti sei registrato al sito"<<endl;
    getline(cin,cognome);
    cout<<endl;
    cout<<"Inserisci la data di nascita con cui ti sei registrato al sito"<<endl;
    getline(cin,dataNascita);
    cout<<endl;
    cout<<"Inserisci l' username  con cui ti sei registrato al sito"<<endl;
    getline(cin,userName);
    cout<<endl;
    while(!validPassword){

        for(int i = 0; i < 9 - 1; i++){
            ra = rand() % 84;
            stringPassword[i] = stringAlphabet[ra];
            if( stringPassword[i]  == "a" || stringPassword[i]  == "b" || stringPassword[i]  == "c" || stringPassword[i]  == "d" || stringPassword[i]  == "e" ||
                    stringPassword[i]  == "f" || stringPassword[i]  == "g" || stringPassword[i]  == "h" || stringPassword[i]  == "i" || stringPassword[i]  == "j" ||
                    stringPassword[i]  == "k" || stringPassword[i]  == "l" || stringPassword[i]  == "m" || stringPassword[i]  == "n" || stringPassword[i]  == "o" ||
                    stringPassword[i]  == "p" || stringPassword[i]  == "q" || stringPassword[i]  == "r" || stringPassword[i]  == "s" || stringPassword[i]  == "t" ||
                    stringPassword[i]  == "u" || stringPassword[i]  == "v" || stringPassword[i]  == "w" || stringPassword[i]  == "x" || stringPassword[i]  == "y" ||
                    stringPassword[i]  == "z"){
                ++lowercaseCarNum;
            }
            if(stringPassword[i]  == "A" || stringPassword[i]  == "B" || stringPassword[i]  == "C" || stringPassword[i]  == "D" || stringPassword[i]  == "E" ||
                    stringPassword[i]  == "F" || stringPassword[i]  == "G" || stringPassword[i]  == "H" || stringPassword[i]  == "I" || stringPassword[i]  == "J" ||
                    stringPassword[i]  == "K" || stringPassword[i]  == "L" || stringPassword[i]  == "M" || stringPassword[i]  == "N" || stringPassword[i]  == "O" ||
                    stringPassword[i]  == "P" || stringPassword[i]  == "Q" || stringPassword[i]  == "R" || stringPassword[i]  == "S" || stringPassword[i]  == "T" ||
                    stringPassword[i]  == "U" || stringPassword[i]  == "V" || stringPassword[i]  == "W" || stringPassword[i]  == "X" || stringPassword[i]  == "Y" ||
                    stringPassword[i]  == "Z"){
                ++uppercaseCarNum;
            }
            if(stringPassword[i] == "0" || stringPassword[i] == "1" || stringPassword[i] == "2" ||
                    stringPassword[i] == "3" || stringPassword[i] == "4" || stringPassword[i] == "5" ||
                    stringPassword[i] == "6" || stringPassword[i] == "7" || stringPassword[i] == "8" ||
                    stringPassword[i] == "9"){
                ++numberNum;
            }
            if(stringPassword[i] == "-" || stringPassword[i] == "_" || stringPassword[i] == "!" || stringPassword[i] == "?" || stringPassword[i] == "/" ||
                    stringPassword[i] == "*" || stringPassword[i] == "<" || stringPassword[i] == ">" || stringPassword[i] == "+" || stringPassword[i] == "=" ||
                    stringPassword[i] == "(" || stringPassword[i] == ")" || stringPassword[i] == "[" || stringPassword[i] == "]" || stringPassword[i] == "{" ||
                    stringPassword[i] == "}" || stringPassword[i] == "@" || stringPassword[i] == "#" || stringPassword[i] == "%" ||
                    stringPassword[i] == "&" || stringPassword[i] == "|"){
                ++symbolNum;
            }
        }


        if( lowercaseCarNum >= 1 && uppercaseCarNum >= 1 && numberNum >= 1 && symbolNum >= 1){
            cout <<"La tua password per: "<< nomeSito<<" e': ";
            pwFile << "Dati di accesso al sito: "<<nomeSito;
            pwFile << endl;
            pwFile << "Email: "<<email;
            pwFile << endl;
            pwFile << "Nome: "<<nome;
            pwFile << endl;
            pwFile << "Cognome: "<< cognome;
            pwFile << endl;
            pwFile << "Data di nascita: "<<dataNascita;
            pwFile << endl;
            pwFile << "Username: "<< userName;
            pwFile << endl;
            pwFile << "Password: ";
            for(int i = 0; i < 9-1; i++){
                cout<<stringPassword[i];
                pwFile << stringPassword[i];
            }
            pwFile << endl;
            pwFile.close();
            cout << endl;
            validPassword = true;
        }
    }
}


int main()
{
    //std::clock_t startcputime = std::clock();
    createPassword();
    //double cpu_duration = (std::clock() - startcputime) / (double)CLOCKS_PER_SEC;
    //std::cout << "Programma finito in: " << cpu_duration << " secondi [CPU Clock] " << std::endl;

    return 0;
}
