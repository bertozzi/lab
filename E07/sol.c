#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stampa(char a[4][4]);

int main(int argc, char **argv){

  char tabella[4][4];
  int  sr, sc; // riga e colonna di dove si trova lo ' '
  char spostamenti[100];

  FILE *t = fopen("input.txt", "r");
  if(!t)
  {
    perror("");
    exit(EXIT_FAILURE);
  }

  for(int r=0; r<4; ++r)
  {
    for(int c=0; c<4; ++c)
    {
      tabella[r][c] = fgetc(t);
      if( tabella[r][c] == ' ' ) // memorizzo a parte le coordinate della casella vuota ovvero dello spazio
      {
	sr = r;
	sc = c;
      }
    }
    fgetc(t); // remove the \n
  }
  fscanf(t, "%s", spostamenti);
  fclose(t);
  printf("Gli spostamenti da eseguire sono [%s]\n", spostamenti);

  for(int i=0; i < strlen(spostamenti); ++i)
  {
    int nsr = sr, nsc = sc; // nuove coordinate dello spazio che aggiornero' in base al 'comando'
    switch( spostamenti[i] )
    {
      case 'A':
	--nsr;
	break;
      case 'B':
	++nsr;
	break;
      case 'D':
	++nsc;
	break;
      case 'S':
	--nsc;
	break;
    }
    if(nsc < 0 || nsc > 3 || nsr < 0 || nsr > 3  ) // controllo che dopo spostamento le coordinate destinazione siano sensate
    {
      printf("Errore: non riesco ad eseguire il comando [%c]\n", spostamenti[i]);
      exit(EXIT_FAILURE);
    }

    tabella[sr][sc]  = tabella[nsr][nsc];
    tabella[nsr][nsc] = ' ';
    sr = nsr;
    sc = nsc;
  }
  stampa(tabella);


  return 0;
}

void stampa(char  a[4][4])
{
  for(int r=0; r<4; ++r)
  {
    for(int c=0; c<4; ++c)
      printf("%c", a[r][c]);
    printf("\n");
  }
}

