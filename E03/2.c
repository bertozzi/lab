//  B prendere un numero intero in ingresso e stampare se il numero e'
//   pari o dispari

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int x;
  printf("Inserisci un numero intero: ");
  scanf("%d", &x);

  if(x % 2)
    printf("Il numero %d e' dispari\n", x);
  else
    printf("Il numero %d e' pari\n", x);

  return 0;
}

