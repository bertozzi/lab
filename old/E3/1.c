#include<stdio.h>
#include<stdlib.h>

// 1. prenda in ingresso un numero intero N, ne calcoli e stampi il fattoriale

// leggo n
// inizializzo il fattoriale a 1
// conto da 1 a N
// ad ogni iterazione moltiplico fattoriale per il contatore
// al termine stampo

int main(int argc, char **argv){

  int n;

  printf("Inserisci un numero intero: ");
  scanf("%d", &n);
  
  long long fatt=1;

  int ii;
  for(ii=1; ii <=n; ++ii)
  {
    fatt = fatt * ii;
  }

  printf("Il risultato e': %lld\n", fatt);

  return 0;
}

