#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
2. usi rand() per riempire un array di 100 elementi con numeri interi casuali tra 10 e 80 e lo stampi

3. come il precedente in cui però prima della stampa si eliminino gli elementi duplicati
*/

// in questa versione elimino realmente gli elementi accorciando eventualmente l'array
// in questo caso diventa obbligatoria l'allocazione dinamica della memoria

#define NELEM 100

int main(int argc, char **argv){

  srand(time(0));

  int n = NELEM;  // contiene il numero di elementi dell'array (cambiera' durante l'esecuzione)
  int *a=malloc(n*sizeof(int));
  // qui ci vorrebbe il controllo... durante il corso per semplicita' non lo faremo...

  for(int i=0; i<n; ++i)
    a[i] = 10 + rand()%71;

  // scandisco array per trovare elementi duplicati
  for(int i=0; i<n-1; ++i)          // itero su tutti elementi
      for(int j=i+1; j<n; ++j)      // itero su elementi successivi
      {
	if(a[i] == a[j])                // controllo se trovo elementi successivi a quello in esame con lo stesso valore
	{
	  // 1o passo copio tutti i valori successivi a a[j] spostandoli "indietro"
	  for(int k=j; k<n-1; ++k)
	    a[k] = a[k+1];   // sovrascrivo con l'elemento successivo
	  // 2o passo accorcio l'array usando realloc()
	  a = realloc(a, (n-1)*sizeof(int));
	  --n;   // aggiorno n per tener traccia del nuovo numero di elementi dell'array
	}
      }

  printf("Ho ottenuto un array di %d elementi, il cui contenuto e': ", n);
  for(int i=0; i<n; ++i)
  {
    printf("%2d ", a[i]);
  }
  printf("\n");

  return 0;
}

