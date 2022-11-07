#include<stdio.h>
#include<stdlib.h>

// 2. prenda in ingresso un numero intero N, calcoli la somma di tutti i numeri pari da 0 a N e la stampi

// leggo N

// inizializzo somma a 0

// inizializzo i a 0
// aggiorno somma aggiungendo i
// aggiorno i aggiungendo 2
// e' i <= N?
// si' devo ripetere
// no ho finito

// stampo il risultato

int main(int argc, char **argv){

  int N;
  printf("Inserisci un numero: ");
  scanf("%d", &N);

  int somma=0;
  int i=0;

  while(i<=N)
  {
    somma = somma + i;
    i = i + 2;
  }

  /* ALTERNATIVA AL while()
  int i;
  int somma = 0;
  for(i=0; i<=N; i=i+2)
    somma = somma + i;
   */

  /* ALTERNATIVA CRIPTICA AL while()
  int i, somma;
  for(i=0, somma=0; i<=N; somma=somma+i, i=i+2);
  */

  printf("Il risultato e' %d\n", somma);

  return 0;
}

