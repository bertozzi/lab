// 5. prendere in ingresso un numero e stamparne il fattoriale (si rammenta che il fattoriale di n si scrive n! e vale 1*2*3* ... *(n-1)*n)
// Che tipi di dato mi conviene usare?

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  unsigned long long n;
  printf("Inserisci un numero >=1: ");
  scanf("%llu", &n);

  unsigned long long fatt = 1;

  for(unsigned long long i = 2; i <= n; ++i)
    fatt = fatt * i;

  printf("Il fattoriale di %llu vale %llu\n", n, fatt);


  return 0;
}

