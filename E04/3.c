#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
2. usi rand() per riempire un array di 100 elementi con numeri interi casuali tra 10 e 80 e lo stampi

3. come il precedente in cui però prima della stampa si eliminino gli elementi duplicati
*/


#define NELEM 100

int main(int argc, char **argv){

  srand(time(0));

  int a[NELEM];

  // int *a=malloc(NELEM*sizeof(int));

  for(int i=0; i<NELEM; ++i)
    a[i] = 10 + rand()%71;

  // scandisco array per trovare elementi duplicati
  for(int i=0; i<NELEM-1; ++i)          // itero su tutti elementi
    if(a[i] != -1)                      // se l'elemento in esame e' "valido"
      for(int j=i+1; j<NELEM; ++j)      // itero su elementi successivi
      {
	if(a[i] == a[j])                // controllo se trovo elementi successivi a quello in esame con lo stesso valore
	  a[j] = -1;                    // lo "elimino" usando valore non ammesso (ne terro' conto in fase di stampa, l'elemento continua ad esistere)
      }

  int nval = 0;                       // per debug tengo conto di quanti elementi stampo
  for(int i=0; i<NELEM; ++i)
    if(a[i] != -1)                    // stampo solo valori non "eliminati"
    {
      printf("%2d ", a[i]);
      ++nval;                         // tengo conto di quanti elementi ho stampato (debug)
    }
  printf("\nHo ottenuto solo %d elementi non duplicati\n", nval); // sempre per debug

  return 0;
}

