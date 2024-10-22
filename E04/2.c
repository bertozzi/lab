// 2. sviluppare un programma che legga un char da input e scriva se e' una lettera maiuscola, minuscola, cifra oppure, se nessuna delle precedenti si applica, e' un carattere speciale

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  char x;
  printf("Inserisci un carattere: ");
  scanf("%c", &x);

  if(x >= 'A' && x  <= 'Z')
    printf("[%c] e' una lettera maiuscola\n", x);
  else if(x >= 'a' && x  <= 'z')
    printf("[%c] e' una lettera minuscola\n", x);
  else if(x >= '0' && x  <= '9')
    printf("[%c] e' una cifra\n", x);
  else
    printf("[%c] e' un simbolo\n", x);


  return 0;
}

