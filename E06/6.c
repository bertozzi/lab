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
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){
  char frase[2000];

  printf("Inserisci una frase da tradurre: ");
  scanf("%[^\n]", frase);

  for(int i = 0; i < strlen(frase)  ; ++i)
  {
    /*
    if( frase[i] == 'A')
      frase[i] = '4';
    else if( frase[i] == 'E')
      frase[i] = '3';
    else ... funzionerebbe ma non e' proprio proprio elegante come codice...
    */

    switch( frase[i] )
    {
      case 'a':
      case 'A':
	frase[i] = '4';
	break;
      case 'e':
      case 'E':
	frase[i] = '3';
	break;
      case 'g':
      case 'G':
	frase[i] = '6';
	break;
      case 'i':
      case 'I':
	frase[i] = '1';
	break;
      case 'o':
      case 'O':
	frase[i] = '0';
	break;
      case 's':
      case 'S':
	frase[i] = '5';
	break;
      case 't':
      case 'T':
	frase[i] = '7';
	break;
      default:
	break;
    }
  }

  printf("La frase tradotta in l33t e': %s\n", frase);


  return 0;
}

