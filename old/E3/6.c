#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// 6. prende in ingresso le coordinate cartesiane di due punti nel formato "(x,y)" e stampa il quadrato della distanza tra i due punti (o la distanza per chi lo sa fare)

int main(int argc, char **argv){
  float x1,y1,x2,y2;

  printf("Inserisci le coordinate di un punto nel formato (x,y): ");
  scanf("(%f,%f)", &x1, &y1);

  printf("Inserisci le coordinate di un punto nel formato (x,y): ");
  scanf(" (%f,%f)", &x2, &y2);

  float qdist=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);

  printf("La distanza tra i due punti inseriti e' %f\n", sqrt(qdist));



  return 0;
}

