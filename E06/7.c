/*
6. legga da tastiera una frase e la converta in l33t (basic)
   ovvero converta le seguenti lettere (maiuscole e minuscole) con i caratteri o sequenze di caratteri indicati
   A -> 4
   E -> 3
   G -> 6
   I -> 1
   O -> 0
   S -> 5
   T -> 7
 7. come il (6) in cui però si convertono anche:
   B -> |3
   D -> |)
   R -> |2
   U -> (_)

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){
  char frase[2000];
  char l33t[2000];

  printf("Inserisci una frase da tradurre: ");
  scanf("%[^\n]", frase);

  int i, i2 = 0;
  for(i = 0; i < strlen(frase)  ; ++i)
  {

    switch( frase[i] )
    {
      case 'a':
      case 'A':
	l33t[i2++] = '4';
	break;
      case 'e':
      case 'E':
	l33t[i2++] = '3';
	break;
      case 'g':
      case 'G':
	l33t[i2++] = '6';
	break;
      case 'i':
      case 'I':
	l33t[i2++] = '1';
	break;
      case 'o':
      case 'O':
	l33t[i2++] = '0';
	break;
      case 's':
      case 'S':
	l33t[i2++] = '5';
	break;
      case 't':
      case 'T':
	l33t[i2++] = '7';
	break;
      case 'b':
      case 'B':
	//  B -> |3
	l33t[i2++] = '|';
	l33t[i2++] = '3';
	break;

      // TODO aggiungere gli altri casi
      default:
	l33t[i2++] = frase[i];
	break;
    }
  }

  l33t[i2] = '\0';

  printf("La frase tradotta in l33t e': %s\n", l33t);


  return 0;
}

