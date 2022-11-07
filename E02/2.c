/*
   2. sviluppare un programma che legga un char da input, se e' una lettera minuscola lo trasformi in maiuscola, stampi il carattere
*/

#include<stdio.h>
#include<stdlib.h>

/*

   1 leggere un char da tastiera
   2 capire dal codice ASCII se e' una lettera minuscola
    se vero -> trasformarla in maniuscola
   3 stampare

   */

int main(int argc, char **argv){

  //  leggere un char da tastiera

  char a;
  printf("Inserisci un carattere: ");
  scanf("%c", &a);

  // 2 capire dal codice ASCII se e' una lettera minuscola
  if(a>='a' && a<='z')
    // vero
    a = a - 'a' + 'A';

  // 3 stampare
  printf("Il carattere inserito (eventualmente trasformato in maiuscola) e': %c\n", a);

  return 0;
}

