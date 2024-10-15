/*
  si implementi il seguente algoritmo:
   a: input n
   b: fino a che n e' diverso da 1 ripetere i punti c e d:
       c: output n
       d: se n è dispari aggiornare n come
             n <-- 3n+1:
          altrimenti
             n <-- n/2 (divisione intera)
   e: stampare la lunghezza della sequenza ottenuta ovvero quanti
      numeri sono stati stampati
*/


#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int n;
  printf("Dammi un numero n: ");
  scanf("%d", &n);

  int lungh = 0;
  while(n != 1)
  {
    printf("%d ", n);
    ++lungh;
    if(n%2)
      n = 3*n + 1;
    else
      n = n/2;
  }
  printf("\nLa sequenza ottenuta e' formata da %d numeri\n", lungh);

  // anche un for() era utilizzabile
  // for(lungh = 0; n != 1; ++lungh)
  // if(n%2)...

  return 0;
}

