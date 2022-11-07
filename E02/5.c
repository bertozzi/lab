/*
   Calcolare il numero piu' grande per cui io riesco a calcolare il fattoriale
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  /*
     1. Conto da 1 fino ad un numero sufficientemente grande
     2. Ne calcolo il fattoriale come fatto nell'esercizio precedente
     3. Lo confronto con il fattoriale calcolato al giro precedente
     4. C'e' stato overflow?
      5. Si' stampo il numero per cui ero riuscito a calcolare il fattoriale ed esco

     */

  unsigned long long int Rprecedente=0;

  // 1. Conto da 1 fino ad un numero sufficientemente grande
  for(int n=1; n<100; ++n)
  {

    // 2. Ne calcolo il fattoriale come fatto nell'esercizio precedente
    unsigned long long int R=1;
    for(int i=1; i <= n; ++i)
      R = R*i; 

    // 3. Lo confronto con il fattoriale calcolato al giro precedente
    if(R <= Rprecedente)
    {
      // C'e' stato overflow
      // 5. Si' stampo il numero per cui ero riuscito a calcolare il fattoriale ed esco
      printf("Il massimo valore per cui riesco a calcolare il fattoriale e': %d\n", n-1);
      exit(0);
    }

    Rprecedente = R;
  }

  return 0;
}

