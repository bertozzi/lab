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

int main(int argc, char **argv){
  int a[100];

  srand(time(0));

  // inizializzo array con valori da 1 a 100 in ordine
  for(int i = 0; i < 100; ++i)
    a[i] = i + 1;

  // lo mescolo
  for(int i = 0; i < 100; ++i)
  {
    int pos = rand() % 100;  // genero indice casuale in [0,100[
    // scambio di contenuto di 2 variabili
    int tmp = a[i]; // mi salvo su temporaneo il valore originale di a[i]
    a[i]    = a[pos]; // metto in a[i] il valore con cui lo devo scambiare
    a[pos]  = tmp; // metto in a[pos] il valore originario di a[i]
  }


  for(int i = 0; i < 100; ++i)
    printf("%d ", a[i]);

  printf("\n");

  return 0;
}

