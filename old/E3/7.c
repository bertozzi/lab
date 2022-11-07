#include<stdio.h>
#include<stdlib.h>
/*

   7. prende in ingresso un numero a virgola mobile che rappresenta un imponibile e calcoli il netto tenendo presente che:
   - per la quota fino a 15.000 EUR si paga il 23% di tasse
   - per la quota da 15.000,01 a 28.000 si paga il 27%
   - per la quota da 28.000,01 a 55.000 si paga il 38%
   - per la quota da 55.000,01 a 75.000 si paga il 41%
   - per la quota oltre i 75.000 si paga il 43%

   */

int main(int argc, char **argv){

  float imp;
  printf("Inserisci un imponibile: ");
  scanf("%f", &imp);



  return 0;
}

