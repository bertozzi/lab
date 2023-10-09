#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  printf("Dammi un numero tra 10 e 99: ");
  int x;
  scanf("%d,", &x);

  printf("Il numero %d scritto invertendo le cifre risulta %d%d\n", x, x % 10, x / 10);

  return 0;
}

