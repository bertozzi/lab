#include<stdio.h>
#include<stdlib.h>

// 4. legga un char da input e scriva se e' una lettera maiuscola, minuscola, cifra oppure, se nessuna delle precedenti si applica, e' un carattere speciale


// leggere un carattere c
// se c e' compreso nella tabella ASCII tra i valori delle lettere maiuscole stampa "e' una maiuscola"
// come sopra per le minuscole
// come sopra per le cifre
// altrimenti stampa che e' un carattere speciale


int main(int argc, char **argv){

  char c;
  printf("Inserisci un carattere: ");
  scanf(" %c", &c);

  if(c>='A'  &&   c<= 'Z')
    printf("[%c] e' un carattere maiuscolo\n", c);
  else if(c>='a'  &&   c<= 'z')
    printf("[%c] e' un carattere minuscolo\n", c);
  else if(c>='0'  &&   c<= '9')
    printf("[%c] e' una cifra\n", c);
  else 
    printf("[%c] e' un carattere speciale\n", c);


  return 0;
}

