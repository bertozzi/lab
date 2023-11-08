/*
3. chiedere all'utente un numero intero n, allocare array di n float
dinamicamente con malloc(), leggere n numeri a virgola mobile e
memorizzarli nell'array. Al termine stampare i numeri nell'ordine
inverso rispetto a quando li si e' letti. Liberare la memoria prima di
uscire dal programma.
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int n;
  printf("Quanti numeri vuoi inserire? ");
  scanf("%d", &n);

  float *f;

  f = malloc(n * sizeof(float));
  if(! f)
  {
    printf("Errore in allocazione\n");
    exit(EXIT_FAILURE);
  }

  // stampo l'array prima di riempirlo. Cosa conterra'?
  for(int i=0; i<n; ++i)
    printf("L'elemento di indice %d e' %f\n", i, f[i]);

  for(int i=0; i<n; ++i)
  {
    printf("Inserisci il numero di indice #%d: ", i);
    scanf("%f", &f[i]);
  }

  for(int i=n-1; i >= 0; --i)
    printf("Il numero di indice %d e' %f\n", i, f[i]);

  free(f);

  return 0;
}

