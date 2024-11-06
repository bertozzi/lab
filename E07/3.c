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
  printf("Inserisci un numero: ");
  scanf("%d", &n);

  float *myarr;
  myarr = malloc(n * sizeof(float));

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

