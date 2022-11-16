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
  int j=0;
  for(int i=0; i<strlen(pa); ++i)
  {
    switch(  pa[i] )
    {
      case 'a':
      case 'A':
	conv[j]='4';
	++j;
	break;
      case 'e':
      case 'E':
	conv[j]='3';
	++j;
	break;
      case 'g':
      case 'G':
	conv[j]='6';
	++j;
	break;
      case 'i':
      case 'I':
	conv[j]='1';
	++j;
	break;
      case 'o':
      case 'O':
	conv[j]='0';
	++j;
	break;
      case 't':
      case 'T':
	conv[j]='7';
	++j;
	break;
      case 's':
      case 'S':
	conv[j]='5';
	++j;
	break;
	//  U -> (_)
      case 'u':
      case 'U':
	conv[j]='(';
	++j;
	conv[j]='_';
	++j;
	conv[j]=')';
	++j;
	break;
	// TODO fare le altre lettere...
      default:
	conv[j]=pa[i];
	++j;
    }
  }
  conv[j]='\0'; // conv[] e' solo un array, lo termino per creare una stringa
  printf("%s]\n", conv);

  return 0;
}

