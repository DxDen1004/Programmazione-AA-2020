#include <iostream>
using namespace std;

void X2B(int X, int B[], int S){
    int i = S;


    while(i > 0){
        B[--S] = X % 2;
        X = X/2;
        i--;
    }
}

void Y2B(float Y, int B[], int S){
    int i = S;
    int tmp = 0;

    while(i > 0){
        Y = Y*2;
        if( (tmp = Y) ==  1 )
            Y--;
        B[10-i] = tmp;
        i--;

    }
}

int main(){
    int X;
    int B[10] = {0};
    float Y;

    cin >> X >> Y;

    X2B(X,B,4);
    Y2B(Y,B,6);

   

    for (int i = 0; i < 10; i++)
        cout << B[i] << ' ';
    cout << endl;
}