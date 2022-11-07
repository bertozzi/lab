#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE (8)
#define END_MOSSE (-1)


void converti_coord(char *cmd, int indice, int *r, int *c);
void stampa_scacchiera(const char *s);
void stampa_mosse(const char *s, char *cmd);



int *mosse(const char *s, const int r, const int c)
{
  int *mosse=NULL; // conterra' le possibili coordinate di dove si puo' spostare il pezzo
  int nmosse=0; // man mano trovo i possibili spostamenti tengo traccia di quanti ne ho trovati
  int ir,ic;   // contatori di appoggio per calcolo coordinate

  switch(s[r*SIZE+c]) // ogni pezzo si sposta in modo differente
  {
    case ' ':
      break;
    case 'p':
      if(r==0 && s[(r-1)*SIZE+c]!=' ') 
	break;
      ++nmosse;
      mosse=realloc(mosse, nmosse*2*sizeof(int));
      mosse[nmosse*2-2]=r-1;
      mosse[nmosse*2-1]=c;
      if(r==6 && s[4*SIZE+c]!=' ')
      {
	++nmosse;
        mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=4;
	mosse[nmosse*2-1]=c;
      }
      break;
    case 'P':
      if(r==7 && s[(r+1)*SIZE+c]!=' ') 
	break;
      ++nmosse;
      mosse=realloc(mosse, nmosse*2*sizeof(int));
      mosse[nmosse*2-2]=r+1;
      mosse[nmosse*2-1]=c;
      if(r==1 && s[3*SIZE+c]!=' ')
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=3;
	mosse[nmosse*2-1]=c;
      }
      break;
    case 'b':
    case 'B': // si sposta solo in diagonale
      for(ir=r+1, ic=c+1; ir<8 && ic<8 && s[ir*SIZE+ic] == ' ' ;ir++, ic++)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=ir;
	mosse[nmosse*2-1]=ic;
      }  
      for(ir=r-1, ic=c-1; ir>=0 && ic>=0 && s[ir*SIZE+ic] == ' ' ;ir--, ic--)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=ir;
	mosse[nmosse*2-1]=ic;
      }
      for(ir=r-1, ic=c+1; ir>=0 && ic<8 && s[ir*SIZE+ic] == ' ' ;ir--, ic++)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=ir;
	mosse[nmosse*2-1]=ic;
      }

      for(ir=r+1, ic=c-1; ir<8 && ic>=0 && s[ir*SIZE+ic] == ' ' ;ir++, ic--)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=ir;
	mosse[nmosse*2-1]=ic;
      }
      break;
    case 'r':
    case 'R':
      for(ir=r+1; ir<8 && s[ir*SIZE+c] == ' ' ;ir++)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=ir;
	mosse[nmosse*2-1]=c;
      }

      for(ir=r-1; ir>=0 && s[ir*SIZE+c] == ' ' ;ir--)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=ir;
	mosse[nmosse*2-1]=c;
      }

      for(ic=c+1; ic<8 && s[r*SIZE+ic] == ' ' ;ic++)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=r;
	mosse[nmosse*2-1]=ic;
      }
      for(ic=c-1; ic>=0 && s[r*SIZE+ic] == ' ' ;ic--)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=r;
	mosse[nmosse*2-1]=ic;
      }
      break;
    case 'n':
    case 'N':
      for(ic=-2; ic<=2; ic = ic +4)
	for(ir=-1; ir<=1; ir = ir +2)
	  if((c+ic)>=0 && (c+ic)<8 && (r+ir)>=0 && (r+ir)<8 && s[(r+ir)*SIZE + (c+ic)] == ' ')
	  {
	    ++nmosse;
	    mosse=realloc(mosse, nmosse*2*sizeof(int));
	    mosse[nmosse*2-2]=r+ir;
	    mosse[nmosse*2-1]=c+ic;
	  }
      for(ir=-2; ir<=2; ir = ir +4)
	for(ic=-1; ic<=1; ic = ic +2)
	  if((c+ic)>=0 && (c+ic)<8 && (r+ir)>=0 && (r+ir)<8 && s[(r+ir)*SIZE + (c+ic)] == ' ')
	  {
	    ++nmosse;
	    mosse=realloc(mosse, nmosse*2*sizeof(int));
	    mosse[nmosse*2-2]=r+ir;
	    mosse[nmosse*2-1]=c+ic;
	  }
      break;
    case 'k':
    case 'K':
      for(ic=-1; ic<=1; ++ic)
	for(ir=-1; ir<=1; ++ir)
	{
	  if((c+ic)>=0 && (c+ic)<8 && (r+ir)>=0 && (r+ir)<8 && s[(r+ir)*SIZE + (c+ic)] == ' ')
	  {
	    ++nmosse;
	    mosse=realloc(mosse, nmosse*2*sizeof(int));
	    mosse[nmosse*2-2]=r+ir;
	    mosse[nmosse*2-1]=c+ic;
	  }
	}
      break;
    default:
      break;
  }

  // se devo restituire qualcosa di non vuoto lo "termino" con un -1
  // in questo modo chi riceve il dato puo' capire dove finisce
  if(mosse)
  {
    mosse=realloc(mosse, nmosse*2*sizeof(int)+1);
    mosse[nmosse*2] = END_MOSSE;
  }

  return mosse;
}

int main(int argc, char **argv){

  int r,c;

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

  stampa_scacchiera(s);

  while(1)
  {
    //char pezzo, c1, r1, c2, r2;
    char comando[7];
    printf("Inserisci mossa: ");
    scanf(" %s", comando);
    // Pa2a4 

    if(comando[0]=='0')
      exit(EXIT_SUCCESS);

    if(strlen(comando) == 2)
    {
      stampa_mosse(s, comando);
    }
    else
    {
      converti_coord(comando, 1, &r, &c);
      if(s[r*SIZE + c] != comando[0])
      {
	printf("In %c%c non c'e' il pezzo %c richiesto\n", comando[1], comando[2], comando[0]);
	exit(EXIT_FAILURE);
      }

      s[r*SIZE + c]=' ';

      char *x = strchr(comando, 'x');
      if(!x)
      {
	converti_coord(comando, 3, &r, &c);
	if(s[r*SIZE + c] != ' ')
	{
	  printf("ERRORE: casella destinazione non vuota\n");
	  exit(EXIT_FAILURE);
	}
      }
      else
      {
	converti_coord(comando, 4, &r, &c);
	if(s[r*SIZE + c] == ' ' || (isupper(comando[0]) == isupper(s[r*SIZE + c])) )
	{
	  printf("ERRORE: mossa invalida\n");
	  exit(EXIT_FAILURE);
	}
	else
	  printf("E' stato mangiato il pezzo [%c]\n", s[r*SIZE + c]);
      }
      s[r*SIZE + c]=comando[0];

      stampa_scacchiera(s);
    }
  }

  return 0;
}

//void stampa_scacchiera(char s[])
void stampa_scacchiera(const char *s)
{
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
}

void converti_coord(char *cmd, int indice, int *r, int *c)
{
  *r = cmd[indice+1]-'1';
  *c = cmd[indice]-'a';
}














































void stampa_mosse(const char *s, char *cmd)
{
      int r,c;
      converti_coord(cmd, 0, &r, &c);
      int *p = mosse(s, r, c);

      if(!p)
      {
	printf("Non ci sono pedine nella posizione indicata\n");
	return;
      }

      int i, posx, posy;

      char *ns = malloc(SIZE*SIZE*sizeof(char));
      memcpy(ns, s, SIZE*SIZE*sizeof(char));

      for(i=0; p[i] != END_MOSSE ; i = i +2)
      {
	posy=p[i];
	posx=p[i+1];
	ns[posy*SIZE+posx] = '*';
      }

      stampa_scacchiera(ns);
      free(ns);
}

























