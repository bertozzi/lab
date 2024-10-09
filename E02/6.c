/*
   6 prendere in ingresso una singola cifra esadecimale e stamparne
   il valore in formato decimale
   Richiede l'uso del costrutto if()
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  char hex_digit;
  printf("Inserisci una cifra esadecimale [0,9] o [A,F]: ");
  scanf("%c", &hex_digit);

  if( hex_digit <= '9' && hex_digit >= '0')
  {
    printf("La cifra decimale corrispondente all'esadecimale '%c' e' %c\n", hex_digit, hex_digit);
  }
  else
  {
    int dec = (hex_digit - 'A') + 10; // f(hex_digit): 'A' -> 10, 'B' -> 11, ...
    printf("La cifra decimale corrispondente all'esadecimale '%c' e' %d\n", hex_digit, dec);
  }

  return 0;
}

