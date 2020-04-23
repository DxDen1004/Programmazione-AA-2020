#include <iostream>
using namespace std;

int main(){
    cout<<"start\n";

    int SIZE = 50;
    int i = 0;
    char A[SIZE] = {0};

    //PRE:  (i = 0) && (i < SIZE)
    //INVARIANTE:   ( 0 <= i < SIZE) => (valore da stdin inserito in A[i]) && (i++)
    while(i < SIZE){

        cin >> A[i];

        if (A[i] == '0') i = SIZE;
        else i++;
    }
    //POST: A[] contiene n < SIZE elementi X t.c. per ogni X appartenente ad A[], X != '0',
    //      fino ad un certo A[i], dopo il quale per ogni Y appartenente ad A[], Y == '0'.

    int balance = 0;
    i = 0;
    
    //PRE: (i == 0) && (balance == 0)
    //INVARIANTE: (0 <= i < SIZE) && (esaminati valori di A[] ed incr/decr balance t.c balance sempre > 0) 
    while(A[i] != '0' && balance >= 0){

     switch (A[i]){
       case '(':
            balance++;
            break;
        case ')':
            balance--;
            break;
        }
        
        i++;
    }
    //POST: (balance > 0 && balance < 0) allora sbilanciata, (balance == 0) allora bilanciata

    if(balance == 0) cout << "La sequenza e' bilanciata.\n";
    else if(balance < 0) cout << "La sequenza non e' bilanciata, ci sono parentesi chiuse senza match.\n";
    else cout << "La sequenza non e' bilanciata, ci sono parentesi aperte senza match.\n";

    cout << "end\n";
}