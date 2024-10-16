/*
   Prendere in ingresso da tastiera un numero intero n e quindi
   stampare tutti i numeri interi presenti nell'intervallo [1,n] che
   sono anche cubi di altri numeri interi
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int n;
  printf("Inserisci un numero intero positivo: ");
  scanf("%d", &n);

  // approccio molto a forza bruta
  printf("Primo approccio\n");
  for(int x = 1; x <= n; ++x) // provo tutti i valori tra 1 e n estremi inclusi
  {
    for(int j = 1; (j*j*j) <= x; ++j) 
      //  provo tutti i valori per vedere se uno di questi e' cubo di x, mi fermo non appena il cubo di j e' piu' grande di x
      if( x == (j*j*j) )
        printf("Il valore %d e' cubo di %d\n", x, j);
  }

  // approccio piu' intelligente
  printf("Secondo approccio\n");
  // provo tutti i valori e ne calcolo il cubo, se il cubo in esame e' minore uguale di n allora lo stampo
  for(int x = 1; (x*x*x) <= n; ++x) // provo tutti i valori tra 1 e n estremi inclusi
    printf("Il valore %d e' cubo di %d\n", x*x*x, x);

  return 0;
}

