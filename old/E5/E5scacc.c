#include<stdio.h>
#include<stdlib.h>

/*

3. Si implementi una funzione ?? mosse(??) che prende in ingresso
   la "situazione" della scacchiera, le coordinate di una casella e
   restituisce:
    - NULL se la casella non contiene nessun pezzo
    - un array allocato dinamicamente di "coordinate" in cui il pezzo
      presente si puo' spostare

*/

#define SIZE (8)

int *mosse(const char *s, const int r, const int c)
{
  int *mosse=NULL;
  int nmosse=0;
  int ir,ic;

  switch(s[r*SIZE*c])
  {
    case ' ':
      break;
    case 'b':
    case 'B':
      for(ir=r, ic=c; ir<8 && ic<8 && s[ir*SIZE+ic] == ' ' ;ir++, ic++)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2);
	mosse[nmosse-2]=ir;
	mosse[nmosse-1]=ic;
      }  
      for(ir=r-1, ic=c-1; ir>=0 && ic>=0 && s[ir*SIZE+ic] == ' ' ;ir--, ic--)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2);
	mosse[nmosse-2]=ir;
	mosse[nmosse-1]=ic;
      }
      for(ir=r-1, ic=c+1; ir>=0 && ic<8 && s[ir*SIZE+ic] == ' ' ;ir--, ic++)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2);
	mosse[nmosse-2]=ir;
	mosse[nmosse-1]=ic;
      }

      for(ir=r+1, ic=c-1; ic<8 && ic>=0 && s[ir*SIZE+ic] == ' ' ;ir++, ic--)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2);
	mosse[nmosse-2]=ir;
	mosse[nmosse-1]=ic;
      }
      break;
    case 'r':
    case 'R':
      for(ir=r; ir<8 && s[ir*SIZE+c] == ' ' ;ir++)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2);
	mosse[nmosse-2]=ir;
	mosse[nmosse-1]=c;
      }

      for(ir=r-1; ir>=0 && s[ir*SIZE+c] == ' ' ;ir--)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2);
	mosse[nmosse-2]=ir;
	mosse[nmosse-1]=c;
      }

      for(ic=c+1; ic<8 && s[r*SIZE+ic] == ' ' ;ic++)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2);
	mosse[nmosse-2]=r;
	mosse[nmosse-1]=ic;
      }
      for(ic=c-1; ic>=0 && s[r*SIZE+ic] == ' ' ;ic--)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2);
	mosse[nmosse-2]=r;
	mosse[nmosse-1]=ic;
      }
      break;
    case 'k':
    case 'K':
      for(ic=-1; ic>=1; ++ic)
	for(ir=-1; ir>=1; ++ir)
	  if(c+ic>=0 && c+ic<8 && r+ir>=0 && r+ir <8 && s[(r+ir)*SIZE + (c+ic)] != ' ')
	  {
	    ++nmosse;
	    mosse=realloc(mosse, nmosse*2);
	    mosse[nmosse-2]=r+ir;
	    mosse[nmosse-1]=c+ic;
	  }
      ++nmosse;
      mosse=realloc(mosse, nmosse*2);
      mosse[nmosse-2]=r;
      mosse[nmosse-1]=c;
      break;
    default:
      break;
  }

  return mosse;
}

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

