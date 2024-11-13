// 8. chieda due parole e verifichi se una e' anagramma dell'altra

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

  for(int i1 = 0; i1 < strlen(s1); ++i1) // scandisco tutti i caratteri della prima stringa
  {
    
    int found = 0;
    for(int i2 = 0; i2 < strlen(s1); ++i2) // lo cerco tra i caratteri della seconda stringa
    {
      if( s1[i1] == s2[i2] )
      {
	found = 1;    // segno che l'ho trovata
	s2[i2] = '#'; // la cancello nella seconda parola di modo che non vegna piu' trovata
	break;        // inutile proseguire
      }
    }

    if( !found )
    {
      printf("Le due parole NON sono anagramma una dell'altra\n");
      return 1;
    }
  }

  printf("Le due parole sono anagramma una dell'altra\n");



  return 0;
}

