/*
come il (2) in cui però prima della stampa si eliminino gli
elementi duplicati

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ASIZE (100)
#define NOTVALID (-1)

int main(int argc, char **argv){

  srand(time(0));

  int a[ASIZE];

  for(int i = 0; i < ASIZE; ++i)
  {
    a[i] = 10 + rand() % 71;
  }

  // devo analizzare nuovamente tutti gli elementi 
  // e per ciascuno trovare se vi siano o meno doppioni
  // ed eliminare i doppioni
  for(int i = 0; i < ASIZE - 1; ++i) // ciclo su tutti gli elementi   e li confronto 
				     // con i successivi inutile arrivare fino all'ultimo visto che non ha elementi dopo
  {
    for(int j =  i + 1; j < ASIZE; ++j) // ciclo per gli elementi seguenti a quello di indice i
    {
      if(a[j] == a[i])
	a[j] = NOTVALID;
    }
  }



  for(int i = 0; i < ASIZE; ++i)
  {
    if(a[i] != NOTVALID)
      printf("L'elemento di indice #%d vale %d\n", i, a[i]);
  }
  return 0;
}

