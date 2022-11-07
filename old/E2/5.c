#include<stdio.h>
#include<stdlib.h>

// 5. legga un char da input, se e' una lettera minuscola lo trasformi in maiuscola, stampi il carattere

// leggere un carattere
// se e' compreso tra i codici ascii di a e z allora e' una lettera minuscola
// aggiungere al codice ascii letto il delta che c'e' tra i codici ascii di a e A
// stamparlo

int main(int argc, char **argv){

  char c,b;
  printf("Inserisci un carattere: ");
  scanf(" %c", &c);

  if(c>='a' && c<= 'z')
    b=c+('A'-'a');
  else
    b=c;

  printf("Il carattere %c l'ho trasformato in %c\n", c, b);


  return 0;
}

