#include<iostream>
using namespace std;

void superC(int X[][10], int righe, int & sc, int & rip){
    int currentColumn = 0, i = 0, j = 0;
    int tmpArray[5] = {0};
    int occurences[10] = {0};
    bool ready = false;

    do{
        i = 0, j = 0;

        for(j; j < 5; j++)
            tmpArray[j] = X[j][currentColumn];
        
        for(int c = 0; c < 10; c++){

            for(i; i < 10; i++){
                
                j = 0;
                ready = true;

                for(j; j < righe; j++){

                    if(ready && tmpArray[j] == X[j][i])
                        cout << tmpArray[j] << ' ' << X[j][i] << endl;
                    else ready = false;

                    if(j == righe-1 && ready)
                        occurences[currentColumn]++;
                }
            }
        }
        currentColumn++;
    }while(currentColumn < 10);
    
    int max = 0;
    for(int i = 0; i < 10; i++){
        if(occurences[i] > max){
            max = occurences[i];
            sc = i;
        }
    }
    
    rip = occurences[sc];
}   

int main()
{
    int X[5][10];
    for(int i=0; i<5; i++)
        for(int j=0; j<10; j++)
        cin >> X[i][j];
    int supc, rip;
    superC(X,5,supc,rip);
    cout<<"la super colonna è "<< supc<<" e ripete "<<rip<<" volte"<<endl;
    
}
