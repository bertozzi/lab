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

  return 0;
}

