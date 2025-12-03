/*
1. aprire un file di tipo ASCII di nome "pippo.txt" in lettura.
   Verificare il buon esito dell'operazione. Se avete errore come
   potete capire cosa sia successo? Che funzione dovete usare in
   questo caso?
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  FILE *miofile;

  miofile = fopen("pippo.txt", "r");
  if(!miofile)
  {
    perror("Non sono riuscito ad aprire il file");
    exit(EXIT_FAILURE);
  }

  return 0;
}

