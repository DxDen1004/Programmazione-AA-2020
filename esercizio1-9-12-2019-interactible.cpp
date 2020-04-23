/*
    created by Dennis Preatto - Date: March 11th 2020
    Esercizio 1
*/

#include <iostream>

int main(){
    int PLAYERS = 2, i = 0;
    char playersMove[PLAYERS];
    bool notValidMove;

    //Pre: i inizializzata a zero, PLAYERS > i 
    while(i < PLAYERS){
        notValidMove = true;
        std::cout << "\n\nPlayer " << i + 1 << "chooses (s, c, f): ";
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

    if(playersMove[0] == playersMove[1])
        std::cout << "Draw.\n";
    else if(
        (playersMove[0] == 's' && playersMove[1] == 'f')  ||  
        (playersMove[0] == 'c' && playersMove[1] == 's')  || 
        (playersMove[0] == 'f' && playersMove[1] == 'c') 
    ) std::cout << "Player 1 wins.\n";
    else std::cout << "Player 2 wins.\n";

    return 0;
}