#include<iostream>
using namespace std;

void FillArrays(int (*arr1)[5] , int (*arr2)[5]){
  int count = 0;
  int tmp = 0;
  int i = 0, j = 0;
  int k = 0, l = 0;

  while(count < 50){

    cin >> tmp;

    if(j > 4){ 
      i++; 
      j = 0; 
      arr1[i][j] = tmp; 
      j++;
    }else{ 
      arr1[i][j] = tmp; 
      j++; 
    }

    if(k > 9){
      l++; 
      k = 0; 
      arr2[k][l] = tmp;
      k++;
    }else{ 
      arr2[k][l] = tmp;
      k++;
    }

    count++;
  }
}

void PrintArray(int (*arr)[5]){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 5; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
}

void PrintArray(bool (*arr)[5]){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 5; j++){
      if(arr[i][j]) cout << 1 << " ";
      else cout << 0 << " ";
    }
    cout << endl;
  }
}

int Cross(int (*arr1)[5], int (*arr2)[5], bool (*arrB)[5] ){
    int count = 0;
   while(count < 2500){
    
    //confronto a[0][0] con tutti gli elementi di b[i][0] dove 0 < i < 9

    for(int a = 0; a < 10; a++){

      for(int b = 0; b < 5; b++){

        for(int c = 0; c < 5; c++){

          for(int d = 0; d < 10; d++){
            if(arr1[a][b] == arr2[d][c]){
              arrB[a][c] = true;
              count++;
            } 
          }
        }
      }
    }
  }
}

main(){

  int A1[10][5] = {0};
  int A2[10][5] = {0};
  bool B[10][5] = {false};

  FillArrays(A1, A2);
  Cross(A1, A2, B);
  PrintArray(A1);
  cout << endl;
  PrintArray(A2);
  cout << endl;
  PrintArray(B);

}
