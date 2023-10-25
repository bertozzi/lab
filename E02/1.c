/*
1. Per calcolare la radice quadrata di un numero si puo' usare l'algoritmo di Newton. Dato un numero n di cui calcolare la radice, inizializzo il risultato r a 1. Ad ogni iterazione aggiorno r come
valor medio tra r stesso e n/r (im pratica (r + n/r)/2 )   Mi fermo quando la differenza tra il valore con cui aggiorno r e il valore precedente di r e' inferiore a 10^-6 Confrontare il risultato con quanto restituito da sqrt(n)
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char **argv){

  float n;
  printf("Inserisci un numero non negativo: ");
  scanf("%f", &n);


  float r = 1, prec_r;

  do
  {
    prec_r = r;
    r = (r + n/r)/2;
  }
  while(r - prec_r > .000001 ||  prec_r - r > .000001);

  printf("La radice quadrata di %f vale %f (sqrt() mi dice %f)\n", n, r, sqrt(n));



  return 0;
}

