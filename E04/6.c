// 6. Calcolare il numero piu' grande per cui io riesco a calcolare il fattoriale

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(int argc, char **argv){

  // APPROCCIO DI STIMA A FORZA BRUTA
  // calcolo il fattoriale di n con n a crescere
  // quando il risultato e' tale per cui n!/n != (n-1)!  allora vuol dire
  // che c'e' stato overflow
  unsigned long long n  = 2;
  unsigned long long prec;
  unsigned long long fatt = 1;

  do
  {
    prec = fatt;

    fatt = fatt * n;

    printf("Il fattoriale di %2llu vale %llu\n", n, fatt);
    ++n;

  }
  while((fatt / (n - 1)) == prec);

  printf("Nota: %llu/%llu mi fornisce come risultato %llu\n", fatt, n-1, fatt / (n - 1));

  // APPROCCIO PIU' CORRETTO
  // parto dal massimo numero intero memorizzabile
  // e scendo fino a che non trovo il primo fattoriale...

  return 0;
}

