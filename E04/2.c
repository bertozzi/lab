#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 2. usi rand() per riempire un array di 100 elementi con numeri interi casuali tra 10 e 80 e lo stampi


int main(int argc, char **argv){

  srand(time(0));

  int a[100];

  // int *a=malloc(100*sizeof(int));

  for(int i=0; i<100; ++i)
    a[i] = 10 + rand()%71;

  for(int i=0; i<100; ++i)
    printf("%2d ", a[i]);
  printf("\n");

  return 0;
}

