/*
   4. prendere in ingresso un numero e stamparne il fattoriale (si rammenta che il fattoriale di n si scrive n! e vale 1*2*3* ... *(n-1)*n)
   Che tipi di dato mi conviene usare?
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  /*
     1. leggere un numero
     2. inizializzare un risultato R a 1
     3. contare per i da 1 a n
       4. moltiplicare ad ogni iterazione R per i
     5. stampare R

     */

  // 1. leggere un numero

  int n;
  printf("Inserisci un numero di cui vuoi calcolare in fattoriale: ");
  scanf("%d", &n);

  // 2. inizializzare un risultato R a 1

  unsigned long long int R=1;

  // 3. contare per i da 1 a n

  for(int i=1; i <= n; ++i)
    // 4. moltiplicare ad ogni iterazione R per i
    R = R*i; // R *= i;

  // 5. stampare R
  printf("Il risultato e' %llu\n", R);

  return 0;
}

