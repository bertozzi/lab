/*
7. si riprenda l'esercizio E03.7. Si memorizzi la sequenza ottenuta
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

  int *mynumbers = NULL; // obbligatoria l'inizializzazione a NULL se lo uso con realloc()
  int lungh = 0;         // con un array che faccio crescere man mano con realloc()
			 // e' fondamentale usare variabile d'appoggio per memorizzare
			 // la dimensione aggiornata

  while(n != 1)
  {
    //printf("%d ", n);
    ++lungh; // incremento dimensione array
    mynumbers = realloc(mynumbers, sizeof(int) * lungh);
    mynumbers[lungh - 1] = n;    // memorizzo n nell'ultimo elemento (dimensione array - 1)
    printf("DEBUG: ora mynumbers punta all'indirizzo %p e contiene %d elementi, l'ultimo elemento aggiunto vale %d\n", mynumbers, lungh, n);


    if(n%2)
      n = 3*n + 1;
    else
      n = n/2;

  }

  printf("\nLa sequenza ottenuta e' formata da %d numeri\n", lungh);
  for(int i = 0; i < lungh; ++i)
    printf("%d ", mynumbers[i]);
  printf("\n");

  free(mynumbers);

  return 0;
}

