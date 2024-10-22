// 6. Calcolare il numero piu' grande per cui io riesco a calcolare il fattoriale

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(int argc, char **argv){

  // APPROCCIO DI STIMA A FORZA BRUTA
  // calcolo il fattoriale di n con n a crescere
  // quando il risultato e' minore del precedente c'e' sicuramente stato overflow
  unsigned long long n  = 2;
  unsigned long long prec  = 0;
  unsigned long long fatt = 1;

  do
  {
    prec = fatt;

    fatt = fatt * n;

    printf("Il fattoriale di %2llu vale %llu\n", n, fatt);
    ++n;

  }
  while(fatt > prec);

  // APPROCCIO PIU' CORRETTO
  // ma non esce mai...
  // parto dal massimo numero intero memorizzabile
  // e scendo fino a che non trovo il primo fattoriale...

  n = ULLONG_MAX;
  // n = 2432902008176640000L; // DEBUG per verificare funzioni il tutto...

  do
  {
    unsigned long long tmp = n;
    unsigned long long div = 3;

    do
    {
      tmp = tmp / div;
      ++div;
    }
    while(tmp>2);

    if(tmp == 2)
    {
      printf("Il massimo fattoriale che riesco a calcolare vale %lld\n", n);
    }
    --n; 
  }
  while(1);

  return 0;
}

