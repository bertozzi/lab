#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
  FILE *fp;

 // LEGGI FILE  tabella.txt E MEMORIZZALO
  int tabella['Z'-'A'+1]={}; // sufficiente per alfabeto
  fp=fopen("tabella.txt","r");
  if(!fp)
  {
    perror("errore apertura file");
    exit(EXIT_FAILURE);
  }
  // leggi riga file tabella txt come carattere, spazi e numero
  char c; 
  int num;
  while( fscanf(fp, " %c %d", &c, &num) == 2 )
  {
   // memorizza numero in opportuna struttura dati
   // (array in cui la lettera mi permette di calcolare l'indice opportuno con (lettera - 'A')
    tabella[c-'A'] = num;
   // ci sono ancora righe? se si' ripeti
  }
  fclose(fp);

  /* 
  int i;
  for(i=0; i<sizeof(tabella)/sizeof(tabella[0]); ++i)
      printf("%c -> %d\n", i+'A', tabella[i]);
   */

  // LEGGI FILE testo.txt E SOSTITUISCI SEQUENZE
  // leggo un carattere
  fp=fopen("testo.txt", "r");
  if(!fp)
  {
    perror("errore apertura file");
    exit(EXIT_FAILURE);
  }
  int car;
  while( (car=fgetc(fp)) !=EOF)
  {
    // e' un '['?
    if(car!='[')
    {
     // no -> lo stampo
      printf("%c", car);
    }
    else
    {
     // si -> leggo lettera e stampo corrispondente valore da tabella, leggo ulteriore carattere (la ']')
      car = fgetc(fp);
      printf("%d", tabella[car-'A']);
      fgetc(fp);
    }
    // ci sono ancora caratteri? si' -> ripeto
  }

  printf("\n\n");
  return 0;
}

