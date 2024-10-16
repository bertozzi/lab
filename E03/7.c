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

  // PUNTO a
  int n;
  printf("Dammi un numero n: ");
  scanf("%d", &n);

  int lungh = 0; //  anche se non esplicitato nella descrizione dell'algoritmo mi serve per tener conto di quante volte ripeto

  // PUNTO b
  while(n != 1)
  {
    // PUNTO c
    printf("%d ", n);

    // PUNTO d
    if(n%2)
      n = 3*n + 1;
    else
      n = n/2;


    ++lungh; // incremento il numero di ripetizioni
  }
  printf("\nLa sequenza ottenuta e' formata da %d numeri\n", lungh);

  // anche un for() era utilizzabile
  // for(lungh = 0; n != 1; ++lungh)
  //   if(n%2)...

  return 0;
}

/* ESEMPIO ESECUZIONE
Dammi un numero n: 55
55 166 83 250 125 376 188 94 47 142 71 214 107 322 161 484 242 121 364 182 91 274 137 412 206 103 310 155 466 233 700 350 175 526 263 790 395 1186 593 1780 890 445 1336 668 334 167 502 251 754 377 1132 566 283 850 425 1276 638 319 958 479 1438 719 2158 1079 3238 1619 4858 2429 7288 3644 1822 911 2734 1367 4102 2051 6154 3077 9232 4616 2308 1154 577 1732 866 433 1300 650 325 976 488 244 122 61 184 92 46 23 70 35 106 53 160 80 40 20 10 5 16 8 4 2 
La sequenza ottenuta e' formata da 112 numeri
*/
