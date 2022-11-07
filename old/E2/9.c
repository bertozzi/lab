#include<stdio.h>
#include<stdlib.h>

// 9. legga un intero senza segno < 255 e lo stampi in binario usando un ciclo for()
// va bene anche stamparlo da sinistra a destra ovvero dalla cifra meno significativa

// leggere un intero senza segno

// divido N per 2 e calcolo risultato e resto
// il resto e' la cifra meno significativa in binario e la stampo
// il risultato e' diverso da 0? 
// si' -> ho finito
// no -> ripeto

int main(int argc, char **argv){

  int n;
  printf("Inserisci un numero < 255: ");
  scanf("%d", &n);

  int r=0;

  for( ; n!=0 ; n = n/2)
  {
    printf("%d", n%2);
  }

  printf("\n");

  return 0;
}

