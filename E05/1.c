/*
1. Leggere da tastiera un numero decimale memorizzandolo in opportuna
variabile x. Definire un puntatore p che possa contenere l'indirizzo
di x e inizializzarlo con tale indirizzo. Stampare: l'indirizzo di
x, il contenuto di p, l'indirizzo di p, il contenuto di x, il valore
contenuto all'indirizzo contenuto in p.
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  float x;
  printf("Inserisci un numero: ");
  scanf("%f", &x);

  float *p;

  p = &x;

  printf("L'indirizzo di x e'   %p\n", &x);
  printf("Il contenuto di p e'  %p\n", p);
  printf("L'indirizzo di p e'   %p\n", &p);
  printf("Il valore contenuto all'indirizzo contenuto in p e' %f\n", *p);

  return 0;
}

