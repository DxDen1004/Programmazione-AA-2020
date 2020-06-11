#include<iostream>
using namespace std;

void Read2DBoolArray(bool(*X)[6])
{
  bool * y=*X;
  for(int i=0; i<36;i++)
    cin>>y[i];
}

void Fill2DBoolArray(bool(*X)[6], bool value)
{
  bool * y=*X;
  for(int i=0; i<36;i++)
    y[i] = value;
}

//PRE: L'array passato è definito, 0 <= r < 6
void Print2DBoolArrayRow(bool(*X)[6], int r)
{
  cout<<"riga:"<<r<<'=';
  
  //R: (0 <= i < 6)(stampati elementi in X[r][0..i-1])
  for(int i=0; i<6;i++)
    cout<<X[r][i]<<' ';
  cout << endl;
}
//POST: Stampa ogni elemento di X[r][0..i]


//PRE: L'array passato è definito, 0 <= r < 6
bool IsRowAllFalse(bool (*X)[6], int r){

  //R1: (0<= i < 6)(considerati elementi X[r][0..i-1])
  for(int i = 0; i < 6; i++)
    if(X[r][i]) return false;
  return true;
}
//POST: Ritorna true sse non esiste un elemento true in r

//PRE: Array A definito
void BeginPlay(bool(*A)[6], bool(*B)[6]){
  
  int index = 0;
  int range = 2;

  //R: (0 <= currentRow < 6)(considerati gli elementi in A[0..currentRow-1][...])
  for(int currentRow = 0; currentRow < 6; currentRow ++){
    //R1: (0 <= currentIndex < 6)(considerati gli elementi in A[currentRow][0..currentIndex-1])
    for(int currentIndex = 0; currentIndex < 6; currentIndex++){
      
      if(currentRow == 0 && A[currentRow][currentIndex] == true) 
        B[currentRow][currentIndex] = true;

      if(A[currentRow][currentIndex] == true && A[currentRow][currentIndex] == B[currentRow][currentIndex]){
        
        //R2: (-1 <= rangeIndex < range)(controllato se elemento[0...currentRow][currentIndex+rangeIndex] == true)
        for(int rangeIndex = -1; rangeIndex < range; rangeIndex++){
          if(currentIndex+rangeIndex < 0) rangeIndex++;

          if(!(currentIndex+rangeIndex > 5)){
            if(A[currentRow+1][currentIndex+rangeIndex] == true){
              B[currentRow+1][currentIndex+rangeIndex] = true;
            }
          }
        }
      }
    }
    Print2DBoolArrayRow(B, currentRow);
    if(IsRowAllFalse(B, currentRow)) currentRow = 10;
  }
}
//POST: Ogni elemento di B è true sse è presente un altro valore true nella riga precedente, in un range che va dall'indice elemento -1 a indice elemento +1

//PRE: Array A definito
bool IsPathPresent(bool (*A)[6]){

  //R: (0 <= i < 6)(considerati elementi di A[r][0..i-1])
  for(int i = 0; i < 6; i++)
    if(A[5][i]) return true;
  return false;
}
//POST: al primo elemento true trovato è certo che esiste cammino, quindi ritorna true.

main(){
  
  int dim;
  //bool B[6][6],B1[6][6] = {false};
  bool (*B)[6] = new bool[6][6];
  Read2DBoolArray(B);

  bool (*B1)[6] = new bool[6][6];
  Fill2DBoolArray(B1, false);

  BeginPlay(B, B1);
  delete []B;

  if(IsPathPresent(B1)) cout << "c'e' cammino\n";
  else cout << "non c'e' cammino\n";
}
