/*
2. aprire un file di tipo ASCII di nome "pippo.txt" in scrittura,
   controllate il buon esito dell'operazione e successivamente
   chiudete il file. Il file è stato creato? E con che dimensione?

*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  FILE *miofile;

  miofile = fopen("pippo.txt", "w");
  if(!miofile)
  {
    perror("Non sono riuscito ad aprire il file");
    exit(EXIT_FAILURE);
  }

  fclose(miofile);

  return 0;
}

