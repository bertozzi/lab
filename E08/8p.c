// 8. chieda due parole e verifichi se una e' anagramma dell'altra
// VERSIONE CON FUNZIONE strchr()

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){
  char s1[2000], s2[2000];

  printf("Inserisci due parole: ");
  scanf("%s %s", s1, s2);

  if(strlen(s1) != strlen(s2))
  {
    printf("Le due parole hanno lunghezze differenti e quindi non sono una anagramma dell'altra\n");
    return 1;
  }

  for(int i = 0; i < strlen(s1); ++i) // scandisco tutti i caratteri della prima stringa
  {
    
    char *P = strchr(s2, s1[i]);
    if (p == NULL) // meglio scrivere if(!p)
    {
      printf("Le due parole NON sono anagramma una dell'altra\n");
      return 1;
    }
    *p = '#';
  }

  printf("Le due parole sono anagramma una dell'altra\n");



  return 0;
}

