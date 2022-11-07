#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  FILE *fp=fopen("input.txt", "r");
  if(!fp)
  {
    perror("errore");
    exit(EXIT_FAILURE);
  }

  int min, sec, totmin=0, totsec=0;
  char brano[1000];

  while(fscanf(fp, "%d:%d %[^\n]", &min, &sec, brano)==3)
  {
    totmin += min;
    totsec += sec;
  }
  printf("Minuti totali: %d\t\tSecondi totali: %d\n", totmin, totsec);

  printf("Tempo totale %02d:%02d:%02d\n", (totmin+totsec/60)/60 ,(totmin+totsec/60)%60  , totsec%60);


  return 0;
}

