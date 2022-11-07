#include<stdio.h>
#include<stdlib.h>


int controllariga(int *riga)
{
  // DEBUG

  int i;
  int presenze[9]={};

  for(i=0; i<9; ++i) 
  {
    if(presenze[riga[i]-1])
      return 1;
    presenze[riga[i]-1]=1;
  }

  return 0;
}

int main(int argc, char **argv){
  int sud[9][9];

  // controlla linea di comando
  if(argc<2)
  {
    fprintf(stderr, "Errore devi passare il nome del file da aprire\n");
    exit(1);
  }

  // apri file
  FILE *fp=fopen(argv[1], "r");
  if(!fp)
  {
    perror("Errore in apertura file");
    exit(1);
  }

  // leggi dati
  int r, c;
  for(r=0; r<9; ++r)
    for(c=0; c<9; ++c)
      fscanf(fp,"%d",&sud[r][c]);

  // DEBUG
  printf("MATRICE LETTA:\n");
  for(r=0; r<9; ++r)
  {
    printf("#%d\t", r+1);
    for(c=0; c<9; ++c)
      printf("%d ", sud[r][c]);
    printf("\n");
  }


  // controlla righe
  for(r=0; r<9; ++r)
    if(controllariga(sud[r]))
    {
      printf("Matrice non valida\n");
      printf("Errore in riga %d\n", r+1);
      exit(1);
    }

  // controlla colonne

  // controlla blocchi

  // chiudi file



  return 0;
}

