#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 7. che chieda due parole e verifichi se una e' anagramma dell'altra

char *read_word(void){
  char tmp[2000];
  scanf("%s", tmp);

  char *p = malloc((strlen(tmp) + 1)*sizeof(char));
  strcpy(p, tmp);
  return p;
}


int main(int argc, char **argv){

  printf("Inserisci due parole: ");
  char *p1 = read_word();
  char *p2 = read_word();
  printf("Hai inserito [%s] e [%s]\n", p1, p2);

  if(strlen(p1) != strlen(p2))
  {
    printf("Le due parole non sono una anagramma dell'altra\n");
    return 0;
  }

  for(int i=0; i<strlen(p1); ++i)
  {
    // analizziamo p1 lettera per lettera > p1[i]
    // la cerco nell'altra parola
    int trovato = 0;
    for(int j=0; j<strlen(p2); ++j)
    {
      if(p1[i]==p2[j])
      {
	trovato = 1;
	p2[j] = '*'; // "cancello" il carattere della seconda parola in quanto "gia' usato"
	break;
      }
    }
    if(!trovato)
    {
      printf("Le due parole non sono una anagramma dell'altra\n");
      return 0;
    }
  }

  printf("Le due parole sono uno anagramma dell'altra!\n");

  return 0;
}

