/*
6. riempa un array di 100 elementi con i numeri tra 1 e 100 in ordine
e successivamente lo "mescoli", ovvero scambi di posizione in maniera
casuale i vari elementi dell'array, e poi lo stampi. Suggerimento: si
scorra l'array elemento per elemento e per ciascun elemento generare
casualmente (rand()) l'indice di un altro elemento con cui scambiarlo.
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
    a[i] = i + 1;  // riempo l'array con numeri da 1 a 100 in ordine
  }
  
  // ciclo nuovamente su array e genero indice a caso con cui scambiare
  // l'elemento in esame
  for(int i = 0; i < ASIZE; ++i)
  {
    // genero indice di altro elemento con cui scambiare l'elemento di indice i
    int j = rand()%ASIZE;

    // per lo scambio mi devo appoggiare a un'altra variabile temporanea
    int tmp = a[j];
    a[j]    = a[i];
    a[i]    = tmp;
  }

  for(int i = 0; i < ASIZE; ++i)
  {
    printf("L'elemento di indice #%d vale %d\n", i, a[i]);
  }
  return 0;
}

