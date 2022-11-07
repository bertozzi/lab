#include<stdio.h>
#include<stdlib.h>

// 1. accetti un numero intero in ingresso e stampi se il numero e' pari o dispari

// leggere un numero
// calcolo r come resto della divisione per 2
// se r=0 stampa che e' pari
// altrimenti stampa che e' dispari

int main(int argc, char **argv){

  int n;
  printf("inserisci un numero: ");
  scanf("%d", &n);

  int r;
  r=n%2;

  if(r==0) printf("Il numero %d e' pari\n", n);
  else     printf("Il numero %d e' dispari\n", n);

  return 0;
}

