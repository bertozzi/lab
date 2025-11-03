/*
3. come il (2) in cui però non si stampa ma, solo dopo aver riempito
l'array, si richiede all'utente un numero, lo si ricerca nell'array
e si stampa se esiste e in quale posizione si trovi (limitarsi alla
prima occorrenza del numero cercato)
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ASIZE (100)

int main(int argc, char **argv){

  srand(time(0));

  unsigned short a[ASIZE];
  int i;

  for(i = 0; i < ASIZE; ++i)
  {
    a[i] = 10 + rand() % 71;
  }

  unsigned short n;
  printf("Inserisci un numero da ricercare: ");
  scanf("%hu", &n);

  for(i = 0; i < ASIZE; ++i)
  {
    if(n == a[i])
      break;
  }

  if(i != ASIZE) // mi sono fermato prima ovvero ho trovato il numero che cercavo
    printf("Il numero che hai inserito si trova in posizione #%d\n", i);
  else
    printf("Il numero che hai inserito non e' presente nell'array\n");


  return 0;
}

