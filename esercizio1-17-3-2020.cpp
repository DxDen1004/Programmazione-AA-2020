#include <iostream>
using namespace std;

void DeleteValueFromArray(int * array, int value, int & size){
  int i = size;
  int deleted = 0;
  //int array[size] = {2,2,2,2,2,3,2,2,2,1};

  for(int i = 0; i < size-1; i++){
    
    if(*(array+i) == value){
      deleted++;
      for(int j = i; j < size-deleted; j++)
        *(array+j) = *(array+j+1);
      i--;
    }
  }

  for(int i = size-deleted; i < size; i++)
    *(array+i) = 0;
  size-=deleted;
}

void FillArray(int * array, int size){
  for(int i = 0; i < size; i++)
    cin >> array[i];
}

void PrintArray(int * array, int size){
  for (int i = 0; i < size; i++)
    cout << *(array+i) << " ";
}

int main()
{

  int dimA;
  cin >> dimA;

  int A[dimA];
  FillArray(A, dimA);

  int x;
  cin >> x;

// eliminare tutte le occorrenze di x in A[0 ... dimA-1]
// assumendo che ∃ x in A, rimarranno i = dimA - nx elementi < dimA
// t.c. ∀ y , y contenuto in A[0 ... i - 1]

  DeleteValueFromArray(A, x, dimA);

  PrintArray(A, dimA);
} 
