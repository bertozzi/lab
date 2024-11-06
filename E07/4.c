/*
4. come il precedente ma inizializzando l'array allocato a 0. Si
verifichi che abbia funzionato stampando il contenuto dell'array prima
di leggere i numeri con cui riempirlo.
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int n;
  printf("Inserisci un numero: ");
  scanf("%d", &n);

  float *myarr;
  myarr = calloc(n, sizeof(float));

  printf("L'array appena allocato contiene: ");
  for(int i = 0; i < n; ++i)
    printf("%f ", myarr[i]);
  printf("\n");

  for(int i = 0; i < n; ++i)
  {
    printf("Inserisci il numero di indice #%d: ", i);
    scanf("%f", &myarr[i]);
  }

  printf("Hai inserito i seguenti numeri (in ordine inverso): ");
  for(int i = n - 1; i >= 0; --i)
  {
    printf("%f ", myarr[i]);
  }
  printf("\n");

  free(myarr);

  return 0;
}

