#include<iostream>
using namespace std;

void Leggi(int A[],int dim){
  for (int i = 0; i < dim; i++)
    cin >> A[i];
}


int main()
{
  int A[100],P[20],dimA,dimP;

  cin>>dimA>>dimP;

  Leggi(A,dimA);
  Leggi(P,dimP);

  int i = 0, j = 0;
  bool matching = true;

  while(j < dimA){
    if(P[i] == A[j]){
      matching = true;
      i++; j++;
    } else {
      matching = false;
      j++;
    }
    if(i == dimP && matching) cout << "trovato match che inizia in posizione " << j-dimP << " di A\n";
    else if (i == dimP) i = 0;
  }
}

