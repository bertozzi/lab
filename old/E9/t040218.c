#include<stdio.h>
#include<stdlib.h>

#define SIZE (10)
#define VUOTO (0)
#define PIENO (1)

void stampaboard(int board[SIZE][SIZE]);
int nvicini(int board[SIZE][SIZE], int r, int c);
int evoluzione(int cella, int nvicini);
void copyboard(int dest[SIZE][SIZE], const int src[SIZE][SIZE]);

int main(int argc, char **argv){

  // leggi il file e memorizzalo
  // ciclo infinito
   // stampa situazione
   // calcola per ogni cella il numero dei vicini
   // scegli evoluzione cella in base al numero
   // stampa numero evoluzione
   // aspetta <INVIO>

  FILE *fp=fopen("vita1.txt", "r");
  if(!fp)
  {
    perror("Errore");
    exit(EXIT_FAILURE);
  }

  int r, c, contatore_evoluzione=1;
  int board[SIZE][SIZE]={}, tmpboard[SIZE][SIZE]={};


  while(fscanf(fp, "%d %d", &r, &c)==2)
  {
    board[r][c]=PIENO;
  }

  while(1)
  {
    stampaboard(board);

    for(r=0; r<SIZE; ++r)
      for(c=0; c<SIZE; ++c)
      {
	int vicini=nvicini(board, r, c);
	tmpboard[r][c]=evoluzione(board[r][c], vicini);
	//printf("c=%d r=%d vicini=%d evoluzione=%d\n", c,r,vicini,tmpboard[r][c]);
      }

    copyboard(board, tmpboard);

    printf("Evoluzione: %d\n", contatore_evoluzione);
    contatore_evoluzione++;
    getchar();
  }

  return 0;
}

int nvicini(int board[SIZE][SIZE], int r, int c)
{
  int i, j;
  int vicini=0;

  for(i=-1; i<=1; ++i)
    for(j=-1; j<=1; ++j)
    {
      // alternativa alla formola, definirsi due variabili di appoggio con le
      // coordinate aggiustate con degli if()
      // int cc=c+j;
      // if(cc==-1) cc=SIZE-1;
      // else if(cc==SIZE) cc=0;

      if( (i || j) && board[(r+i+SIZE)%SIZE][(c+j+SIZE)%SIZE] == PIENO )
      {
	++vicini;
      }
    }
  return vicini;
}

void stampaboard(int board[SIZE][SIZE])
{
  int c,r;
  for(r=0; r<SIZE; ++r)
  {
    for(c=0; c<SIZE; ++c)
      printf("%c ", (board[r][c]==PIENO ? '*' : '.'));
    printf("\n");
  }
}

int evoluzione(int cella, int nvicini)
{
  // un organismo sopravvive fino alla generazione successiva se ha due o tre vicini;
  // un organismo muore, cioè lascia la cella vuota, se ha più di tre o meno di due vicini;
 // ogni cella vuota con esattamente tre vicini diventa una cella di nascita e alla generazione seguente viene occupata da un organismo.

  if(cella==PIENO && (nvicini==2 || nvicini==3)) return PIENO;
  if(cella==PIENO && (nvicini<2  || nvicini>3))  return VUOTO;
  if(cella==VUOTO && nvicini==3)                 return PIENO;
  return VUOTO;
}

void copyboard(int dest[SIZE][SIZE], const int src[SIZE][SIZE])
{
  int c,r;
  for(r=0; r<SIZE; ++r)
    for(c=0; c<SIZE; ++c)
      dest[r][c]=src[r][c];
}

