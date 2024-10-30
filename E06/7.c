/*
7. usi un array per memorizzare le caselle di una scacchiera 8x8, lo
inizializzi usando uno o piú cicli mettendo 'N' per le caselle nere e
'B' per quelle chiare e successivamente lo stampi:
*/

#include<stdio.h>
#include<stdlib.h>

#define MSIZE  (8)

int main(int argc, char **argv){

  char sc[MSIZE][MSIZE];

  for(int r = 0; r < MSIZE; ++r)
    for(int c = 0; c < MSIZE; ++c)
    {
      // primo approccio, per le righe pari se colonne dispari faccio una cosa o l'altra
      // e l'inverso per le righe dispari
      if(r%2)
      {
	if(c%2)
	  sc[r][c] = 'N';
	else
	  sc[r][c] = 'B';
      }
      else
      {
	if(c%2)
	  sc[r][c] = 'B';
	else
	  sc[r][c] = 'N';
      }


      // secondo approccio, mi basta discriminare guardando se la somma degli indici e' pari o dispari
      if((r + c) % 2)
	sc[r][c] = 'B';
      else
	sc[r][c] = 'N';

      // terzo approccio, come il precedente ma scritto in maniera piu' compatta grazie
      // all'operatore ternario '?'
      sc[r][c] = ( ((r + c) % 2) ? 'B' : 'N');

      //CAVEAT: i 3 approcci sovrascrivono uno quanto fatto dal precedente, per 
      //        vedere che effettivamente portano tutti allo stesso risultato
      //        eliminate il codice o rahhiudetelo tra /* e */
    }

  // stampa della matrice
  for(int r = 0; r < MSIZE; ++r)
  {
    for(int c = 0; c < MSIZE; ++c)
    {
      printf("%c", sc[r][c]);
    }
    printf("\n");
  }

  return 0;
}

