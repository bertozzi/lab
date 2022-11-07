#include<stdio.h>
#include<stdlib.h>
/*
   1. sviluppare un programma che legga un char da input e scriva se e' una lettera maiuscola, minuscola, cifra oppure, se nessuna delle precedenti si applica, e' un carattere speciale

   */

int main(int argc, char **argv){

  /*
     1 leggere un char
      2a confrontare il codice ASCII del carattere con quelli delle lettere maiuscole
      2a confrontare il codice ASCII del carattere con quelli delle lettere minuscole
      2c ...
     3 stampare di conseguenza
     */

  // 1 leggere un char
  char c;
  printf("Inserisci un carattere: ");
  scanf("%c", &c);


  // 2b confrontare il codice ASCII del carattere con quelli delle lettere maiuscole
  if(c >= 'A' && c <= 'Z') 
    printf("Il codice ASCII del carattere %c vale %d e corrisponde ad una lettera maiuscola\n", c, c);
  else if(c >= 'a' && c <= 'z') 
    printf("Il codice ASCII del carattere %c vale %d e corrisponde ad una lettera minuscole\n", c, c);
  else if(c >= '0' && c <= '9') 
    printf("Il codice ASCII del carattere %c vale %d e corrisponde ad una cifra\n", c, c);
  else if(c < ' ') 
    printf("Il codice ASCII del carattere %c vale %d e corrisponde ad un carattere speciale\n", c, c);
  else
    printf("Il codice ASCII del carattere %c vale %d e corrisponde ad un simbolo\n", c, c);

  return 0;
}

