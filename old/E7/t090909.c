#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define BUFF_SIZE 100

FILE *aprifile(char *nome, char *mode)
{
  FILE *fp=fopen(nome, mode);
  if(!fp)
  {
    perror("Errore non riesco ad aprire il file");
    exit(1);
  }
  return fp;
}


int main(int argc, char **argv){

  // analizza linea comando

  if(argc!=3)
  {
    printf("ERRORE: devi passare i nomi dei file di ingresso e di uscita\n");
    exit(1);
  }

  FILE *fin, *fout;
  // apri file 1
  fin=aprifile(argv[1],"r");

  // apri file 2
  fout=aprifile(argv[2],"w");

  int c, conversione=0;
  char buffer[BUFF_SIZE];

  // fino a che si riesce a leggere un carattere
  while( (fgets(buffer, BUFF_SIZE, fin)) != NULL )
  {
    for(c=0; c<strlen(buffer); ++c)
    {
      // e' un < ?
      if(buffer[c]=='<') conversione=1;
      // devo convertire

      // e' un > ?
      if(buffer[c]=='>') conversione=0;
      // devo smettere di convertire

      // nel caso converto il carattere letto
      if(conversione) buffer[c] = tolower(buffer[c]);

      // scrivo sul file destinazione
      fputc(buffer[c], fout);
    }
  }

  // chiudo file 1
  fclose(fin);

  // chiudo file 2
  fclose(fout);

  return 0;
}

