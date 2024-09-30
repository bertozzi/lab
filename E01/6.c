#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
  
  float x;
  printf("Inserisci il valore di x: ");
  scanf("%f", &x);

  printf("Il valore del polinomio 4x^5 + 2x^3 + 7x +5 in %f e' %f\n", x, 4*x*x*x*x*x + 2*x*x*x + 7*x + 5);


  return 0;
}

