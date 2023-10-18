/*
 *  Prendere in ingresso da tastiera un numero intero n e quindi
   stampare tutti i numeri interi presenti nell'intervallo [1,n] che
   sono anche cubi di altri numeri interi
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int n;
  printf("Inserisci un numero intero positivo: ");
  scanf("%d", &n);

  for(int x = 1; x <= n; ++x) // provo tutti i valori tra 1 e n estremi inclusi
  {
    for(int j = 1; (j*j*j) <= x; ++j) //  provo tutti i valori per vedere se uno di questi e' cubo di x, mi fermo non appena il cubo di j e' piu' grande di x
      if( x == (j*j*j) )
	printf("Il valore %d e' cubo di %d\n", x, j);
  }

  return 0;
}

