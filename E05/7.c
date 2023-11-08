/*
 11 si implementi il seguente algoritmo:
   a: input n
   b: fino a che n e' diverso da 1 ripetere i punti c e d:
       c: output n
       d: se n è dispari aggiornare n come
             n <-- 3n+1:
          altrimenti
             n <-- n/2 (divisione intera)
   e: stampare la lunghezza della sequenza ottenuta ovvero quanti
      numeri sono stati stampati

7. si riprenda l'esercizio E01.11. Si memorizzi la sequenza ottenuta
nel ciclo (b) usando array allocato dinamicamente. Dato che la
lunghezza della sequenza è ignota a priori si usi realloc() per
estendere l'array man mano che vengono generati i numeri.
Stampare la sequenza ottenuta solo al termine del ciclo.

*/


#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int n;
  printf("Dammi un numero n: ");
  scanf("%d", &n);

  int lungh = 0;
  int *numeri = NULL; // devo inizializzare a NULL se voglio usarlo inizialmente con realloc()
  while(n != 1)
  {
    //printf("%d ", n);
    ++lungh;
    numeri = realloc(numeri, lungh * sizeof(int)); // aggiusto dimensione array "allargandolo"
    numeri[lungh - 1] = n; // memorizzo ultimo numero seguenza nell'ultimo elemento

    if(n%2)
      n = 3*n + 1;
    else
      n = n/2;
  }
  printf("\nLa sequenza ottenuta e' formata da %d numeri\n", lungh);

  for(int i=0; i < lungh; ++i)
    printf("%3d: %i\n", i+1, numeri[i]);

  return 0;
}

