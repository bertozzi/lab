/*
7. usi un array per memorizzare le caselle di una scacchiera 8x8, lo
inizializzi usando uno o piú cicli mettendo 'N' per le caselle nere e
'B' per quelle chiare e successivamente lo stampi:
*/

#include<stdio.h>
#include<stdlib.h>

#define MSIZE  (8)

int main(int argc, char **argv){

  char sc[MSIZE * MSIZE]; // array monodimensionale (ovviamente il numero di elementi DEVE essere lo stesso)

  for(int r = 0; r < MSIZE; ++r)
    for(int c = 0; c < MSIZE; ++c)
    {
      // secondo approccio visto in esercizio precedente
      if((r + c) % 2)
	sc[r*MSIZE + c] = 'B'; // questa formula mi permette di ricavare l'indice effettivo nell'array monodimensionale
      else                     // in generale e' (indice di riga)*(numero di colonne) + (indice di colonna)
	sc[r*MSIZE + c] = 'N';
    }

  // stampa della matrice
  for(int r = 0; r < MSIZE; ++r)
  {
    for(int c = 0; c < MSIZE; ++c)
    {
      printf("%c", sc[r*MSIZE + c]);
    }
    printf("\n");
  }

  return 0;
}

