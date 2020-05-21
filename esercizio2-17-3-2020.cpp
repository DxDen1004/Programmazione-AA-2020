#include<iostream>
using namespace std;

void FillArray(int * array, int size){
  for(int i = 0; i < size; i++)
    cin >> array[i];
}

void RemoveDoubles(int * array, int & size){
   int deleted = 0;
   //int array[10] = {2,2,2,2,2,3,2,2,2,1};

   for(int i = 0; i < size-deleted; i++){
      for(int j = i+1; j < size-deleted; j++){

         if( *(array+i) == *(array+j)){
            deleted++;
            int k = j;

            do{ 
               *(array+k) = *(array+k+1);
               k++;
            }while(k < size-deleted);
            *(array+(size-deleted)) = 0;
            j--;
         }
      }
   }
   size -= deleted;
}

void PrintArray(int * array, int size){
  for (int i = 0; i < size; i++)
    cout << *(array+i) << " ";
}

main(){

   int size;
   cin >> size;
   int A[size];

   FillArray(A, size);
   
   RemoveDoubles(A,size);
   
   PrintArray(A,size);
}