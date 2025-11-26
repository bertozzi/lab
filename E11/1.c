/*
1. Sintassi: si definisca una variabile di tipo double, si definisca
   un puntatore a double e lo si inizializzi con l'indirizzo della
   variabile. Si definisca un puntatore a puntatore double e lo si
   inizializzi con l'indirizzo del precedente puntatore. Si usi il
   puntatore a puntatore per memorizzare dentro la variabile il valore
   3.14
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  double myvar;

  double *mypunt   = &myvar; 

  double **my2punt = &mypunt;

  **my2punt = 3.14;

  printf("Il valore della variabile myvar adesso e' %g\n", myvar);

  return 0;
}

