#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
5. legga da tastiera una frase e la converta in l33t (basic)
   ovvero converta le seguenti lettere (maiuscole e minuscole) con i caratteri o sequenze di caratteri indicati
   A -> 4
   E -> 3
   G -> 6
   I -> 1
   O -> 0
   S -> 5
   T -> 7
*/


char *read_line(void){
  char tmp[2000];
  scanf("%[^\n]", tmp);

  char *p = malloc((strlen(tmp) + 1)*sizeof(char));
  strcpy(p, tmp);
  return p;
}


int main(int argc, char **argv){

  printf("Inserisci una frase da convertire: ");
  char *pa = read_line();
  printf("Hai inserito [%s] e convertita vale [", pa);

  for(int i=0; i<strlen(pa); ++i)
  {
    switch(  pa[i] )
    {
      case 'a':
      case 'A':
	pa[i]='4';
	break;
      case 'e':
      case 'E':
	pa[i]='3';
	break;
      case 'g':
      case 'G':
	pa[i]='6';
	break;
      case 'i':
      case 'I':
	pa[i]='1';
	break;
      case 'o':
      case 'O':
	pa[i]='0';
	break;
      case 't':
      case 'T':
	pa[i]='7';
	break;
      case 's':
      case 'S':
	pa[i]='5';
	break;
    }
  }
  printf("%s]\n", pa);

  return 0;
}

