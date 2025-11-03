/*
2. usi rand() per riempire un array di 100 elementi con numeri interi
casuali tra 10 e 80 e lo stampi
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ASIZE (100)

int main(int argc, char **argv){

  srand(time(0));

  unsigned short a[ASIZE];

  for(int i = 0; i < ASIZE; ++i)
  {
    a[i] = 10 + rand() % 71;
  }

  for(int i = 0; i < ASIZE; ++i)
  {
    printf("L'elemento di indice #%d vale %u\n", i, a[i]);
  }
  return 0;
}

