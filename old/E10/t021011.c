#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int memorizza_parole(char nomefile[], char * parole[]);

int main(int argc, char **argv){

  char *articoli[100];
  char *nomi[100];
  char *verbi[100];
  char *preposiz[100];
  int narticoli, nnomi, nverbi, npreposiz;


  srand(time(NULL));


  narticoli=memorizza_parole("articoli.txt", articoli);
  nnomi=memorizza_parole("nomi.txt", nomi);
  nverbi=memorizza_parole("verbi.txt", verbi);
  npreposiz=memorizza_parole("preposiz.txt", preposiz);


  //articolo, nome, verbo, preposizione, articolo, nome.

  printf("%s %s %s %s %s %s\n", 
      articoli[rand()%narticoli],
      nomi[rand()%nnomi],
      verbi[rand()%nverbi],
      preposiz[rand()%npreposiz],
      articoli[rand()%narticoli],
      nomi[rand()%nnomi]
      );

  int i;
  for(i=0; i<narticoli; ++i) free(articoli[i]);
  for(i=0; i<nnomi; ++i) free(nomi[i]);
  for(i=0; i<nverbi; ++i) free(verbi[i]);
  for(i=0; i<npreposiz; ++i) free(preposiz[i]);

  return 0;
}


int memorizza_parole(char nomefile[], char * parole[])
{
  FILE *fp=fopen(nomefile, "r");
  if(!fp)
  {
    char errore[400];
    sprintf(errore, "Errore in apertura file %s", nomefile);
    perror(errore);
    exit(EXIT_FAILURE);
  }

  char tmp[16];

  int i=0;
  while(fscanf(fp, "%s", tmp)==1)
  {
    parole[i]=malloc(strlen(tmp)+1);
    if(!parole[i])
    {
      perror("errore in allocazione");
      exit(EXIT_FAILURE);
    }
    strcpy(parole[i], tmp);
    ++i;
  }
  fclose(fp);

  return i;
}
