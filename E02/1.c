/*
 1 leggere da tastiera un numero intero non negativo tra 0 e 15.
   Stampare le 4 cifre della sua rappresentazione binaria dalla
   meno significativa alla piú significativa (suggerimento: usare
   l'operatore % e la divisione e non la funzione pow())
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int num;
  printf("Inserisci un numero non negativo in [0,15]: ");
  scanf("%d", &num);

  printf("Cifra binaria 1: %d\n", num%2);
  num = num / 2;

  printf("Cifra binaria 2: %d\n", num%2);
  num = num / 2;

  printf("Cifra binaria 3: %d\n", num%2);
  num = num / 2;

  printf("Cifra binaria 4: %d\n", num%2);

  return 0;
}

