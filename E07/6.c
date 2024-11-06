/*
6. si allochino dinamicamente due array di 100 elementi mediante
calloc() e si stampino gli indirizzi di dove si trovano in memoria.
Utilizzando realloc() si estendano gli array in modo da poter
contenere 200 elementi e si stampino nuovamente gli indirizzi di
dove si trovano. Sempre usando realloc() si "accorcino" gli array di
modo da poter contenere 50 elementi e si stampi nuovamente il loro
indirizzo in memoria. Cosa notate?
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  // nulla  viene detto sul tipo di dato, scelgo arpitrariamente il char
  char *a1, *a2;

  a1 = calloc(100, sizeof(char));
  a2 = calloc(100, sizeof(char));

  printf("Appena allocati i due arry si trovano in           %p e %p\n", a1, a2);

  a1 = realloc(a1, 200*sizeof(char));
  a2 = realloc(a2, 200*sizeof(char));

  printf("Dopo la realloc() i due arry si trovano in         %p e %p\n", a1, a2);

  a1 = realloc(a1, 50*sizeof(char));
  a2 = realloc(a2, 50*sizeof(char));

  printf("Dopo l'altra realloc() i due arry si trovano in    %p e %p\n", a1, a2);

  free(a1);
  free(a2);

  return 0;
}

