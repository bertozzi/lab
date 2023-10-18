// prendere ingresso un numero intero N, calcoli la somma di tutti i
//  numeri pari da 0 a N e stamparla

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int n;

  printf("Inserisci un numero intero positivo: ");
  scanf("%d", &n);

  int acc = 0;
  for(int i = 0; i <= n; i += 2)
    acc += i;

  printf("La somma dei numeri pari tra 0 e %d vale %d\n", n, acc);

  return 0;
}

