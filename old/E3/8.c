#include<stdio.h>
#include<stdlib.h>
/*

 8. che controlli la validità di una password.
  Si supponga che, perché una password sia valida, debbano essere soddisfatte tutte le seguenti regole:
    1. deve contenere una combinazione di lettere minuscole e di cifre, con almeno un carattere di ciascun insieme;
    2. deve avere una lunghezza compresa tra 5 e 12 caratteri;
    3. non possono esserci due caratteri contigui uguali.

   Il programma deve iterativamente chiedere l'introduzione di una password e stampare VALIDA o NON VALIDA (e la motivazione) ad ogni introduzione.

   */

int main(int argc, char **argv){

  char c;


  printf("Inserisci una password: ");


  while(1)
  {
    c=0;
    int minuscolo=0, cifra=0, contigui=0;
    int numchar=0;
    char prec=0;
    do
    {
      int res=scanf("%c", &c);
      if(!res)
	return 0;
      //printf("%c", c); // DEBUG

      // analizzo se e' una lettera minuscola
      if(c>='a' && c<='z') minuscolo=1;

      // analizzo se e' una cifra
      if(c>='0' && c<='9') cifra=1;

      // confronto con carattere precedente e lo aggiorno
      if(c==prec) contigui=1;
      prec=c;

      // conto caratteri
      ++numchar;
    }while(c!='\n');
    --numchar;

    if(numchar<5 || numchar>12)
    {
      printf("NON VALIDA: lunghezza sbagliata\n");
    }
    else if(minuscolo==0)
    {
      printf("NON VALIDA: non ci sono lettere minuscole\n");
    }
    else if(cifra==0)
    {
      printf("NON VALIDA: non ci sono cifre\n");
    }
    else if(contigui==1)
    {
      printf("NON VALIDA: ci sono caratteri ripetuti\n");
    }
    else
      printf("VALIDA\n");
  }



  return 0;
}

