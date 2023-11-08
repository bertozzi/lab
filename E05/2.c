/*
2. Leggere da tastiera due numeri interi nelle variabili i1 e i2.
Si definiscano e inizializzino due puntatori di modo da contenere
gli indirizzi delle due variabili i1 e i2. Si definisca una terza
variabile sum e relativo puntatore ad essa. Si memorizzi in sum il
risultato della somma di i1 e i2 usando esclusivamente i puntatori. Si
stampi per verifica il contenuto di sum.
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int i1, i2;
  printf("Inserisci due numeri: ");
  scanf("%d%d", &i1, &i2);

  int *p1, *p2;
  p1 = &i1;
  p2 = &i2;

  int sum, *psum = &sum;

  *psum = *p1 + *p2;

  printf("sum contiene %d\n", sum);


  return 0;
}

