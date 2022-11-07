#include<stdio.h>
#include<stdlib.h>

/* 2. legge da tastiera 4 char, stampa il loro valore numerico in esadecimale, li impacchetta in un int e stampa il valore dell'int cosi' ottenuto sempre in esadecimale
*/

int main(int argc, char **argv){
  
  char c1, c2, c3, c4;
  printf("Inserisci 4 caratteri: ");
  scanf("%c %c %c %c", &c1, &c2, &c3, &c4);

  printf("Il valore del codice ASCII di %c e': %X\n", c1 ,c1);
  printf("Il valore del codice ASCII di %c e': %X\n", c2 ,c2);
  printf("Il valore del codice ASCII di %c e': %X\n", c3 ,c3);
  printf("Il valore del codice ASCII di %c e': %X\n", c4 ,c4);

  int x=0;

  x = x | c1;
  printf("Dopo l'inserimento di %X il mio int vale %X\n", c1, x);

  x = (x << 8) | c2;
  printf("Dopo l'inserimento di %X il mio int vale %X\n", c2, x);

  x = (x << 8) | c3;
  printf("Dopo l'inserimento di %X il mio int vale %X\n", c3, x);

  x = (x << 8) | c4;
  printf("Dopo l'inserimento di %X il mio int vale %X\n", c4, x);


  return 0;
}

