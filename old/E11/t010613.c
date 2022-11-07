#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tart
{
  int x, y;
  int ox, oy; // (x,y) ogni avanzamento si realizza con x+ox e y+oy
  int penna;
};

void stampa_tavola(const int * tavola, const int r, const int c);

int main(int argc, char **argv){

  struct tart tartaruga;

  tartaruga.x=0;
  tartaruga.y=0;

  tartaruga.ox=0;
  tartaruga.oy=1;

  tartaruga.penna=0;

  int size;
  char comandi[1000];

  printf("Inserisci dimensione tavola: ");
  scanf("%d", &size);

  printf("Inserisci comandi: ");
  scanf(" %s", comandi);

  int *tavola=calloc(size*size, sizeof(*tavola));
  if(!tavola)
  {
    perror("Allocazione");
    exit(EXIT_FAILURE);
  }

  int i;
  for(i=0; i<strlen(comandi); ++i)
  {
    switch(comandi[i])
    {
      case 'S':
	tartaruga.penna=0;
	break;
      case 'G':
	tartaruga.penna=1;
	break;
      case 'A':
	tartaruga.x += tartaruga.ox;
	tartaruga.y += tartaruga.oy;
	// TODO controllo confini tavola
	if(tartaruga.penna)
	  tavola[tartaruga.y*size + tartaruga.x] = 1;
	break;
      case 'D': // ruotare in senso orario
	{
	  /*
	     ox=1 oy=0  vado in direzione est
	     ox=0 oy=1  vado in direzione nord
	     ox=-1 oy=0 vado indirezione ovest
	     ox=0 oy=-1 vado in direzione sud

	     (ox,oy)
	     (1,0)  -> (0,-1)
	     (0,-1) -> (-1,0)
	     (-1,0) -> (0,1)
	     (0,1)  -> (1,0)
	   */

	  int tmp=tartaruga.oy;

	  if( tartaruga.ox==1 && tartaruga.oy == 0)        tartaruga.oy=-1;
	  else if( tartaruga.ox==0 && tartaruga.oy == -1)  tartaruga.oy=0;
	  else if( tartaruga.ox==-1 && tartaruga.oy == 0)  tartaruga.oy=1;
	  else if( tartaruga.ox==0 && tartaruga.oy == 1)   tartaruga.oy=0;
	  tartaruga.ox=tmp;

	  break;
	}
      default:
	printf("Comando [%c] sbagliato\n", comandi[i]);
    }
    stampa_tavola(tavola, size, size);
    printf("\n");
  }
//

  return 0;
}

void stampa_tavola(const int * tavola, const int r, const int c)
{
  int i, j;

  for(i=r-1; i>=0; --i)
  {
    for(j=0; j<c; ++j)
    {
      printf("%d ", tavola[i*c +j] );
    }
    printf("\n");
  }
}

