#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long fstrstr(char *filename, char *sub);

int main(int argc, char **argv){

  char s[1000];

  printf("Inserisci la stringa da cercare: ");
  scanf("%[^\n]", s);

  long pos = fstrstr("testo.txt", s);

  if(pos<0)
    printf("Non ho trovato la stringa\n");
  else
    printf("Ho trovato la stringa in posizione %ld\n", pos);


  return 0;
}

long fstrstr(char *filename, char *sub)
{
  // 1. apri il file

  FILE *fp=fopen(filename, "r");
  if(!fp)
  {
    perror("Errore in apertura file");
    exit(1);
  }

  // 2. calcola lunchezza n di sub
  int n=strlen(sub);

  // 3. leggi n caratteri del file
  long pos=0;
  char *buffer=malloc(n+1);
  
  fread(buffer, 1, n, fp);
  buffer[n]='\0';

  // 4. confronta caratteri letti con sub
  //    se eseito positivo restituisci posizione file
  while(1)
  {
    if(!strcmp(buffer, sub)) return  pos;
    //    se esito negativo leggi ulteriore carattere ed elimina il primo letto, ripeti da 4
    int i;

    // sposto i caratteri letti eliminando il primo e facendo spazio per quello da leggere
    for(i=0; i<n-1; ++i)
      buffer[i]=buffer[i+1];

    // leggo il nuovo carattere
    int newchar=fgetc(fp);
    //if(newchar==EOF) return -1;
    if(feof(fp)) return -1; // equivalente a quella commentata sopra
    ++pos;
    buffer[n-1]=newchar;
    //printf("Ho letto da file [%s]\n", buffer);
  }
}

