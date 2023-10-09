#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  printf("Inserisci un numero decimale tra 0 e 15: "); // ci fidiamo dell'utente...
  int x;
  scanf("%d", &x);

  // per convertire da decimale a binario si divide per due. 
  // Il resto e' la cifra meno significativa. Ripeto con il risultato e ottengo la seconda cifra meno significativa.
  // Ripeto fino a quando il risultato non diventa 0.
  // Ci limitiamo quindi a calcolare quattro divisioni e il relativo resto

  int b0, b1, b2, b3; // memorizzo i 4 bit per stamparli poi nell'ordine corretto

  b0 = x % 2; // resto divisione per 2 (puo' essere solo 0 o 1)
  x  = x / 2;

  b1 = x % 2; // ripeto per 4 volte
  x  = x / 2;

  b2 = x % 2; // ripeto per 4 volte
  x  = x / 2;

  b3 = x % 2; // ripeto per 4 volte
  // x  = x / 2; // ci fermiamo e quindi non serve

  printf("Le 4 cifre binarie meno significative del numero inserito sono %d%d%d%d\n", b3, b2, b1, b0);


  return 0;
}

