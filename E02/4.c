// 4. sviluppare un programma che prenda in ingresso un carattere e ripeta fintanto che non sia stato inserito S o N

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  char r;

  do
  {
  printf("Inserisci un carattere: ");
  scanf(" %c", &r);
  }
  while(r != 'S' && r !='N');

  return 0;
}

