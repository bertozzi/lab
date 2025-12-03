/*
3. copiatevi il file "elezioni.txt" nella dir di progetto. Provate ad
   aprirlo in lettura come file ASCII. Il file in questione contiene
   numeri interi separati da uno o piú caratteri di spaziatura.
   Leggete i primi due numeri e stampateli. Chiudete quindi il file.
   Cosa potete usare per leggere i due numeri? Stampate anche il
   valore restituito dalla funzione che avete usato per leggere quei
   due numeri.

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

  int n1, n2, risultato;

  risultato = fscanf(miofile, "%d%d", &n1, &n2);
  fclose(miofile);

  printf("Dal file ho letto %d e %d\n", n1, n2);
  printf("La fscanf() ha restituito %d come valore\n", risultato);

  return 0;
}

