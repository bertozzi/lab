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

7. come il precedente ma usando un array monodimensionale... (suggerimento: data una matrice di N righe e M colonne è possibile memorizzarla in un array monodimensionale di dimensioni MxN; l'accesso all'elemento in riga y e colonna x lo posso effettuare accedendo all'elemento di indice x + M*y)

*/

int main(int argc, char **argv){

  char scacchiera[8*8];

  for(int r = 0; r < 8; ++r)                  // ciclo su righe
    for(int c = 0; c < 8; ++c)                // ciclo su colonne
    {
      if( (!(r%2) && c%2) || (r%2 && !(c%2)) )    // se riga dispari e colonna pari oppure riga pari e colonna dispari
	scacchiera[c + r*8] = 'B';
      else
	scacchiera[c + r*8] = 'N';
    }
  
  for(int r = 0; r < 8; ++r)
  {
    for(int c = 0; c < 8; ++c)
    {
      printf("%c", scacchiera[c + r*8]);          // stampo elemento
    }
    printf("\n");                              // al termine di ogni riga stampo un a capo
  }

  return 0;
}

