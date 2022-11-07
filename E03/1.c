#include<stdio.h>
#include<stdlib.h>
/*
   1. prenda in ingresso un long int N e stampi in esadecimale i byte che lo compongono (si usi un ciclo for(), scorrimento e and bit a bit)

   */

int main(int argc, char **argv){

  // prendiamo  in ingresso un long int

  long x;
  printf("Inserisci un numero intero: ");
  scanf("%ld", &x);

  // ciclo sul numero di byte
  for(int i=0; i<sizeof(x); ++i)
  {
    // scorrimento a destra del redlativo numero di bit e and bit a bit con ...00011111111 di modo
    // da isolare il primo byte
    printf("Il byte di indice %d di %ld vale in esadecimale %X\n", i, x, (unsigned int)(x >> (i*8)) & 0xff);
  }

  return 0;
}

