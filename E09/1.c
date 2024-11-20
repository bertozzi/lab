// 1. scrivere una funzione di nome "isprime" che restituisce vero o
// falso a seconda che le sia passato un numero primo o meno

#include<stdio.h>
#include<stdlib.h>

// approccio semplificato a forza bruta
int isprime(int x)
{
  for(int i = 2; i < x/2; ++i)
  {
    if(!(x%i)) // equivalente a  if(x % i == 0)
      return 0;  // mi fa uscire subito dalla funzione e il ciclo quindi non termina
  }
  return 1; //  se il ciclo termina vuol dire che non ho trovato nessun divisore esatto
}



int main(int argc, char **argv){

  printf("Il risultato di isprime(8) e' %d\n", isprime(8));
  printf("Il risultato di isprime(17) e' %d\n", isprime(17));

  return 0;
}

