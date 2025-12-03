/*
4. modificate l'esercizio 3 di modo da leggere e stampare a schermo
   tutti i numeri presenti nel file. Non fate assunzioni su quanti
   numeri vi siano nel file. Verificate, aprendo il file con un
   editor, che tutti i numeri siano stampati una e una sola volta.

*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  FILE *miofile;

  miofile = fopen("elezioni.txt", "r");
  if(!miofile)
  {
    perror("Non sono riuscito ad aprire il file");
    exit(EXIT_FAILURE);
  }

  int n;

  while( fscanf(miofile, "%d", &n) == 1 )
  {
    printf("Dal file ho letto %d\n", n);
  }

  fclose(miofile);
  return 0;
}

