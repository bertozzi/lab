/*
   Leggere da tastiera un simbolo. Sommare a quel simbolo 1 e
   stamparlo sia come simbolo che come codice ASCII. Cosa succede? E
   perche'?
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  char sym;
  printf("Inserisci un simbolo da tastiera: ");
  scanf("%c", &sym);

  printf("Il symbolo inserito ha codice ASCII %d e rappresenta '%c'\n", sym, sym);

  sym = sym + 1; // andava bene anche ++sym
  
  printf("Il symbolo dopo l'incremento ha codice ASCII %d e rappresenta '%c'\n", sym, sym);



  return 0;
}

