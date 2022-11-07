#include<stdio.h>
#include<stdlib.h>

/*

6. usi un array per memorizzare le caselle di una scacchiera 8x8, lo inizializzi usando uno o piú cicli mettendo 'N' per le caselle nere e 'B' per quelle chiare e successivamente lo stampi:

NBNBNBNB
BNBNBNBN
NBNBNBNB
BNBNBNBN
NBNBNBNB
BNBNBNBN
NBNBNBNB
BNBNBNBN

*/

int main(int argc, char **argv){

  char scacchiera[8][8];

  for(int r = 0; r < 8; ++r)                  // ciclo su righe
    for(int c = 0; c < 8; ++c)                // ciclo su colonne
    {
      if( (!(r%2) && c%2) || (r%2 && !(c%2)) )    // se riga dispari e colonna pari oppure riga pari e colonna dispari
	scacchiera[r][c] = 'B';
      else
	scacchiera[r][c] = 'N';
    }
  
  for(int r = 0; r < 8; ++r)
  {
    for(int c = 0; c < 8; ++c)
    {
      printf("%c", scacchiera[r][c]);          // stampo elemento
    }
    printf("\n");                              // al termine di ogni riga stampo un a capo
  }

  return 0;
}

