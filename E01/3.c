#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int a, b; // per definire due variabili dello stesso tipo lo posso fare su una riga sola

  printf("Inserisci due numeri: ");
  scanf("%d%d", &a, &b);

  printf("Il risultato della divisione tra %d e %d vale %d\n", a, b, a/b); 
  // eseguendo questo codice cosa notate?
  // i conti tornano?

  // ATTENZIONE: a/b e' una divisione "intera". Spesso non e' quello che si vuole. Prestate quindi SEMPRE attenzione



  return 0;
}

