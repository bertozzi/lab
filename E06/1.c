// usi rand() per riempire un array di 100 elementi con numeri interi
// casuali tra 0 e 70 e lo stampi (suggerimento, usare "%")

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ASIZE (100)

int main(int argc, char **argv){

  srand(time(0));

  unsigned short a[ASIZE];

  for(int i = 0; i < ASIZE; ++i)
  {
    a[i] = rand() % 71;
  }

  for(int i = 0; i < ASIZE; ++i)
  {
    printf("L'elemento di indice #%d vale %u\n", i, a[i]);
  }
  return 0;
}

