//   prendere in ingresso tre numeri floating point e stampare il
//   piu' grande dei 3

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  float a, b, c;

  printf("Inserisci un numero a virgola mobile: ");
  scanf("%f", &a);

  printf("Inserisci un numero a virgola mobile: ");
  scanf("%f", &b);

  printf("Inserisci un numero a virgola mobile: ");
  scanf("%f", &c);

  float max;
  if(a > b)
  {
    if(a > c)
      max = a;
    else
      max = c;
  }
  else
  {
    if(b > c)
      max = b;
    else
      max = c;
  }

  // in alternativa potevo scrivere cose del tipo
  // if(a >b && a > c)...
  

  printf("Il valore piu' grande inserito e': %f\n", max);
  return 0;
}

