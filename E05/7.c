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
6. come il precedente in cui però si convertono anche:
   B -> |3
   D -> |)
   R -> |2
   U -> (_)

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

  char conv[2000];
  for(int i=0; i<strlen(pa); ++i)
  {
    switch(  pa[i] )
    {
      case 'a':
      case 'A':
	conv[i]='4';
	break;
      case 'e':
      case 'E':
	conv[i]='3';
	break;
      case 'g':
      case 'G':
	conv[i]='6';
	break;
      case 'i':
      case 'I':
	conv[i]='1';
	break;
      case 'o':
      case 'O':
	conv[i]='0';
	break;
      case 't':
      case 'T':
	conv[i]='7';
	break;
      case 's':
      case 'S':
	conv[i]='5';
	break;
      default:
	conv[i]=pa[i];
    }
  }
  printf("%s]\n", pa);

  return 0;
}

