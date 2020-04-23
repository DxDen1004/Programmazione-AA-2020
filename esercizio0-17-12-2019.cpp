#include<iostream>
using namespace std;

//PRE: (n > 0)
void Leggi(int A[],int n){

    //INVARIANTE: (0 <= i < n) && (letti i valori inseriti in A[0..i-1])
    for(int i = 0; i < n; i++)
        cin >> A[i];
}
//POST: A[] contiene ALMENO un valore int

//PRE: (A[] contiene n elementi interi definiti) && (n > 0)
int TrovaPorz(int A[], int n){
    int k = 1;
    int i = 0;

    while( (i < n-1) && (A[i] < A[i+1]) ){ 
        k++;
        i++;
    }
    return k;
}
//POST: Ottenuto k >= 0

int main(){
    const int SIZE = 100;
    int A[SIZE] = {0}; 
    int n;

    cin >> n;
    Leggi(A, n);
    cout << "k=" << TrovaPorz(A, n);
    
    return 0;
}