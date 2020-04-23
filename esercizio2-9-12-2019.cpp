/*
    created by Dennis Preatto - Date: March 11th 2020
    Esercizio 1
*/

#include <iostream>

int main(){
    std::cout << "start\n";
    int PLAYERS = 2, gamesNumber, i = 0;
    bool notValidMove;

    std::cin >> gamesNumber;
    char playersMove[PLAYERS*gamesNumber];
    //Pre: i inizializzata a zero, PLAYERS > i 
    while(i < PLAYERS*gamesNumber){
        notValidMove = true;
        std::cin >> playersMove[i];

        //Pre: notValidMove inizializzata a true, playersMove[i] considerata invalida fino a prova contraria
        while(notValidMove){
            switch(playersMove[i]){
                case 's':
                case 'c':
                case 'f':
                    notValidMove = false;
                    i++;
                    break;
                default:
                    std::cout << "\nInvalid move, insert again (s, c ,f): ";
                    std::cin >> playersMove[i];
                    notValidMove = true;
                    break;
            }
        } //Post: mossa certamente valida in playersMove[i], notValidMove è false
    }//Post: playersMove[] contenente due char t.c. = s V c V f

    i = 0;
    int p1 = 0, p2 = 0;

    while(i < PLAYERS*gamesNumber){
        if(playersMove[i] == playersMove[i+1]){
            p1++;
            p2++;
        }
        else if(
            (playersMove[i] == 's' && playersMove[i+1] == 'f')  ||  
            (playersMove[i] == 'c' && playersMove[i+1] == 's')  || 
            (playersMove[i] == 'f' && playersMove[i+1] == 'c') 
        ) p1++;
        else p2++;
        i = i + 2;
    }

    if(p1 == p2)
        std::cout << "pareggio\n";
    else if (p1 > p2)
        std::cout << "vince il giocatore 1\n";
    else std::cout << "vince il giocatore 2\n";

    return 0;
}