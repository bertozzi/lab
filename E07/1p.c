// 1. scrivere una funzione di nome "isprime" che restituisce vero o
//    falso a seconda che le sia passato un numero primo o meno

#include<stdio.h>
#include<stdlib.h>


int isprime(int n)
{
  for(int i = 2; i < n/2; ++i) // inutile cercare divisori tra n/2 e n
  {
    if( !(n%i) )
    {
      printf("DEBUG: %d risulta divisore esatto di %d\n", i, n);
      return 0;
    }
  }

  return 1;
}

int main(int argc, char **argv){

  printf("Inserisci un numero intero: ");
  int a;
  scanf("%d", &a);

  if( isprime(a) )
  {
    printf("Il numero inserito e' un numero primo\n");
  }
  else
  {
    printf("Il numero inserito NON e' un numero primo\n");
  }

  return 0;
}

