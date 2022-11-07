#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int comparastringhe(const void *, const void *);

int main(int argc, char **argv){

  FILE *d=fopen("divina.txt", "r");
  if(!d)
  {
    perror("Errore apertura file");
    exit(EXIT_FAILURE);
  }

  int nparole=0;
  char s[51];

  while( fscanf(d, "%s", s)==1 )
    ++nparole;

  printf("Il numero di parole nel file e': %d\n", nparole);
  

  char **parole=malloc(nparole * sizeof(char *));
  if(!parole)
  {
    perror("Problema di allocazione");
    exit(EXIT_FAILURE);
  }

  fseek(d, 0, SEEK_SET);


  int i=0;
  while( fscanf(d, "%s", s)==1 )
  {
    parole[i]=malloc(strlen(s)+1);
    if(!parole[i])
    {
      perror("Problema allocazione elementi array");
      exit(EXIT_FAILURE);
    }
    strcpy(parole[i], s);
    ++i;
  }

  qsort(parole, nparole, sizeof(char *), comparastringhe);

  for(i=0; i<nparole; ++i)
    printf("%s ", parole[i]);



  return 0;
}

int comparastringhe(const void *s1, const void *s2)
{
  char* str1=*((char **)s1);
  char* str2=*((char **)s2);
  return strcmp(str1, str2);
}

