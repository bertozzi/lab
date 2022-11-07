#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 1. usi rand() per riempire un array di 100 elementi con numeri interi casuali tra 0 e 70 e lo stampi (suggerimento, usare "%")


int main(int argc, char **argv){

  srand(time(0));

  int a[100];

  // int *a=malloc(100*sizeof(int));

  for(int i=0; i<100; ++i)
    a[i] = rand()%71;

  for(int i=0; i<100; ++i)
    printf("%2d ", a[i]);
  printf("\n");

  return 0;
}

