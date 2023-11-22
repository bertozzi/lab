// 1. scrivere una funzione di nome "isprime" che restituisce vero o
//    falso a seconda che le sia passato un numero primo o meno

#include<stdio.h>
#include<stdlib.h>


int isprime(int n)
{

  // provo i possibili divisori di n (ad eccezione di 1 e n stesso), se n e' esattamente divisibile da uno di questi sicuramente non e' un numero primo
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

  int primo = isprime(a);

  if(primo)
  {
    printf("Il numero inserito e' un numero primo\n");
  }
  else
  {
    printf("Il numero inserito NON e' un numero primo\n");
  }

  return 0;
}

