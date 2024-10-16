//   Iterativamente chiedere all'utente un numero intero positivo fino a che
//   l'utente non inserisce 0. Stampare quindi il piu' grande e il piu'
//   piccolo dei numeri inseriti dall'utente.

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int n;

  int min = 2000000000, max = 0;
  do
  {
    printf("Inserisci un numero (0 per terminare): ");
    scanf("%d", &n);
    if(n > max)
      max = n;
    if(n < min && n != 0)
      min = n;
  }
  while(n);

  printf("Il numero piu' alto inserito vale %d, il piu' piccolo %d\n", max, min);

  return 0;
}

