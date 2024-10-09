/*
   prendere in ingresso un numero in formato binario di 4 cifre e stampare il
   relativo valore decimale
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
  
  int b0, b1, b2, b3;
  printf("Inserire un numero binario di 4 cifre: ");
  scanf("%1d%1d%1d%1d", &b3, &b2, &b1, &b0);
  // l'1 negli specificatori di formato e' necessario per far leggere una e una sola cifra per ciascuna variabile

  printf("Il valore decimale del numero in formato binario inserito e' %d\n", b3 * 8 + b2 * 4 + b1 * 2 +  b0);


  return 0;
}

