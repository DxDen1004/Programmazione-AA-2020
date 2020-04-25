#include<iostream>
using namespace std;

void Leggi(int A[],int dim){
  for (int i = 0; i < dim; i++)
    cin >> A[i];
}

int MaxMatchLenght(int A[], int P[], int dimA, int dimP, int & maxpos){
  int maximumMatchLenght = 0;
  int currentMatchLenght = 0;
  bool matching = true;
  int i = 0;
  int j = 0;

  while(i < dimA-1){

    currentMatchLenght = 0; 
    matching = true;
    j = 0;

    while(j < dimP && matching){

      if(P[j] == A[j+i]){
        currentMatchLenght++;
        matching = true;
        j++;
      }else{ 
        matching = false; 
        j = 0;
      }
    }

    if(currentMatchLenght > maximumMatchLenght){
      maximumMatchLenght = currentMatchLenght;
      maxpos = i;
    }

    i++;

  }

  return maximumMatchLenght;
}

int main(){

  int A[100], P[20];
  int dimA, dimP;
  int lungMax;
  int maxPos = 0;

  cin >> dimA >> dimP;
  Leggi(A, dimA);
  Leggi(P, dimP);
  
  lungMax = MaxMatchLenght(A, P, dimA, dimP, maxPos);

  cout<<"il massimo match ha lunghezza "<< lungMax<< " e inizia in posizione "<< maxPos <<" di A"<<endl;
    	
}
