/*
5. usi rand() per riempire un array di 100 elementi con numeri interi
univoci tra 1 e 300 e lo stampi
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ASIZE (100)

int main(int argc, char **argv){

  srand(time(0));

  int a[ASIZE];

  for(int i = 0; i < ASIZE; ++i)
  {
    int n, trovato;
    do
    {
      n = 1 + rand() % 300;
      trovato = 0;  // trovato lo inizializzo a falso, rimarra' falso se effettivamente non trovo il 
		    // valore di n nell'array
      for(int j = 0; j < i; ++j)
      {
        if(a[j] == n)
	{
	  trovato = 1; // segno che il valore di n era gia' presente
	  break;       // interrompo il for(j) che tanto e' inutile continuare
	}
      }
    }
    while(trovato); // equivalente a while(trovato == 1); 

    a[i] = n;       // arrivo qui se e solo se il valore di n non era presente nell'array
  }

  for(int i = 0; i < ASIZE; ++i)
  {
    printf("L'elemento di indice #%d vale %d\n", i, a[i]);
  }
  return 0;
}

