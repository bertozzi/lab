/*
9. Redigere un programma C che controlli la validità di una password.
    Si supponga che, perché una password sia valida, debbano essere      soddisfatte tutte le seguenti regole:

    1. deve contenere una combinazione di lettere minuscole e di cifre, con almeno un carattere di ciascun insieme;

    2. deve avere una lunghezza compresa tra 5 e 12 caratteri;

    3. non possono esserci due caratteri contigui uguali.

    Il programma deve iterativamente chiedere l'introduzione di una password e stampare VALIDA o NON VALIDA (e la motivazione) ad ogni introduzione.
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
  
  char c, prec = 0;
  int hasdigit = 0, hasletter = 0, hasother = 0, hascont=0, len  = 0;

  printf("Inserisci una password: ");
  do
  {
    scanf("%c", &c);

    // incremento lunghezza
    ++len;

    // controllo se e' una cifra
    if(c >= '0' && c <= '9')
      hasdigit = 1;
    else if( (c >= 'a' && c <= 'z') )
      hasletter = 1;
    else if(c != '\n') // lo \n entra comunque nel ciclo e lo devo ignorare
      hasother = 1;

    // controllo cartteri contigui uguali
    if( c == prec )
      hascont = 1;

    // mi salvo il carattere letto per sfruttarlo alla iterazione successiva
    prec = c;
  }
  while(c != '\n');

  //  decremento lunghezza password per non tener conto dell'invio
  --len;

  // controllo condizioni e stampa motivazione
  if(hasletter && hasdigit && !hascont && !hasother && (len >=5 && len <= 12))
    printf("VALIDA\n");
  else
  {
    printf("NON VALIDA\n");
    if(!hasletter)
      printf("non contiene lettere\n");
    if(!hasdigit)
      printf("non contiene cifre\n");
    // TODO completare...

  }

  return 0;
}

