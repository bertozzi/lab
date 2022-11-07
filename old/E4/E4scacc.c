#include<stdio.h>
#include<stdlib.h>

/*

1. usi un array bidimensionale per memorizzare una scacchiera e le possibili posizioni dei pezzi.

2. inizializzi tale array con la posizione iniziale come sopra indicata e la stampi.

3. iterativamente:

 3a. chieda all'utente 5 caratteri che codificano una mossa. Il primo carattere è la codifica del pezzo spostato, gli altri le coordinate di partenza e arrivo (esempio: Pb2b4)

 3b. aggiorni la struttura dati e ristampi la scacchiera

 3c. esca dal ciclo se il primo carattere è '0'

4. modificare quanto sviluppato sostituendo all'array bidimensionale un array monodimensionale

*/

#define SIZE (8)

int main(int argc, char **argv){

  char s[SIZE*SIZE]=

  {
    'R','N','B','Q','K','B','N','R',
    'P','P','P','P','P','P','P','P',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',
    'p','p','p','p','p','p','p','p',
    'r','n','b','q','k','b','n','r'
  };

  // stampo coordinate colonne
  char i;
  printf("  ");
  for(i='a'; i<='h'; ++i)
    printf(" %c  ", i);
  printf("\n");

  int r,c;
  for(r=0; r<SIZE; ++r) // ciclo su righe
  {
    printf(" +---+---+---+---+---+---+---+---+\n");
    printf("%d", r+1);
    for(c=0; c<SIZE; ++c) // ciclo su elementi colonna
    {
      printf("| %c ", s[r*SIZE + c]);
    }
    printf("|\n");
  }
  printf(" +---+---+---+---+---+---+---+---+\n");

  while(1)
  {
    char pezzo, c1, r1, c2, r2;
    printf("Inserisci mossa: ");
    scanf(" %c%c%c%c%c", &pezzo, &c1, &r1, &c2, &r2);

    if(pezzo=='0')
      exit(EXIT_SUCCESS);

    r=r1-'1';
    c=c1-'a';
    if(s[r*SIZE + c] != pezzo)
    {
      printf("In %c%c non c'e' il pezzo %c richiesto\n", c1, r1, pezzo);
      exit(EXIT_FAILURE);
    }

    s[r*SIZE + c]=' ';

    r=r2-'1';
    c=c2-'a';
    s[r*SIZE + c]=pezzo;

    // stampo coordinate colonne
    printf("  ");
    for(i='a'; i<='h'; ++i)
      printf(" %c  ", i);
    printf("\n");

    for(r=0; r<SIZE; ++r) // ciclo su righe
    {
      printf(" +---+---+---+---+---+---+---+---+\n");
      printf("%d", r+1);
      for(c=0; c<SIZE; ++c) // ciclo su elementi colonna
      {
	printf("| %c ", s[r*SIZE + c]);
      }
      printf("|\n");
    }
    printf(" +---+---+---+---+---+---+---+---+\n");

  }

  return 0;
}

