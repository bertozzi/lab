/*
come il (2) in cui però prima della stampa si eliminino gli
elementi duplicati

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ASIZE (100000)
#define NOTVALID (0) // l'intervallo di numeri possibili e' [10,80]. Quindi questo valore mi permette di segnalare elementi
		     // "vuoti"

int main(int argc, char **argv){

  srand(time(0));

  unsigned short a[ASIZE];

  for(int i = 0; i < ASIZE; ++i)
  {
    a[i] = 10 + rand() % 71;
  }

  // devo analizzare nuovamente tutti gli elementi 
  // e per ciascuno trovare se vi siano o meno doppioni
  // ed eliminare i doppioni
  int count = 0; // DEBUG: quante iterazioni ho?
  for(int i = 0; i < ASIZE - 1; ++i) // ciclo su tutti gli elementi   e li confronto 
				     // con i successivi inutile arrivare fino all'ultimo visto che non ha elementi dopo
  {
    for(int j =  i + 1; j < ASIZE; ++j) // ciclo per gli elementi seguenti a quello di indice i
    {
      ++count; // per contare le iterazioni devo incrementare il contatore all'interno del ciclo piu' interno
      if(a[j] == a[i])
	a[j] = NOTVALID;
    }
  }



  for(int i = 0; i < ASIZE; ++i)
  {
    if(a[i] != NOTVALID)
      printf("L'elemento di indice #%d vale %u\n", i, a[i]);
  }

  printf("DEBUG: ho ripetuto i cicli di ricerca dei numeri doppi %d volte\n", count);
  return 0;
}

