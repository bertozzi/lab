/*
6. si allochino dinamicamente due array di 100 elementi mediante
calloc() e si stampino gli indirizzi di dove si trovano in memoria.
Utilizzando realloc() si estendano gli array in modo da poter
contenere 200 elementi e si stampino nuovamente gli indirizzi di
dove si trovano. Sempre usando realloc() si "accorcino" gli array di
modo da poter contenere 50 elementi e si stampi nuovamente il loro
indirizzo in memoria. Cosa notate?
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char **argv){

  int *p1, *p2;


  p1=malloc(100*sizeof(int));
  p2=malloc(100*sizeof(int));
  printf("p1:                %p\n", p1);
  printf("p2:                %p\n", p2);

  p2=realloc(p2, 200*sizeof(int));
  p1=realloc(p1,200*sizeof(int));
  printf("p1 dopo realloc(): %p\n", p1);
  printf("p2 dopo realloc(): %p\n", p2);


  p2=realloc(p2, 50*sizeof(int));
  p1=realloc(p1,50*sizeof(int));
  printf("p1 dopo realloc(): %p\n", p1);
  printf("p2 dopo realloc(): %p\n", p2);
}

/* ESEMPIO ESECUZIONE

p1:                0x55ed0e0cb2a0
p2:                0x55ed0e0cb440
p1 dopo realloc(): 0x55ed0e0cbd20
p2 dopo realloc(): 0x55ed0e0cb9f0
p1 dopo realloc(): 0x55ed0e0cbd20
p2 dopo realloc(): 0x55ed0e0cb9f0

*/

