/*
    3 leggere da tastiera una cifra come char. Stamparne il codice
   ASCII. Successivamente, memorizzare il valore che rappresenta
   (quindi non il codice ASCII ma un valore tra 0 e 9) in una
   variabile di tipo int e stamparla.
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  char cifra;
  printf("Inserire una cifra: ");
  scanf("%c", &cifra); // in cifra non finisce il valore della cifra che ho inserito ma il relatico codice ASCII
  printf("DEBUG: l'utente ha inserito '%c' con codice ASCII %d\n", cifra, cifra);

  // per convertire il codice ASCII di una cifra nel relativo valore che rappresenta
  // basta sottrarre il codice ASCII del simbolo '0' (che vale 48).
  // infatti i codici ASCII delle cifre sono tutti consecutivi
  
  int valore = cifra - 48; 
  // ATTENZIONE non e' necessario conoscere il codice ASCII a memoria, potevo scrivere
  // int valore = cifra - '0';
  // un singolo carattere tra apici singoli (') equivale al suo codice ASCII

  printf("La cifra inserita e letta come simbolo rappresenta il numero %d\n", valore);


  return 0;
}

