/*
5. si definisca un VLA di short dimensionandolo usando rand() per
generare un numero a caso tra 80 e 100. Lo si riempa con numeri
casuali tra 1 e 20. Mediante allocazione dinamica della memoria,
allocare dinamicamente un secondo array di dimensione pari al primo
sempre di short. Si ricopi il contenuto del primo array nel secondo.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char **argv){

  srand(time(NULL));

  int mydim = 80 + rand()%21;
  short vla[mydim]; 

  for(int i = 0; i < mydim; ++i)
    vla[i] = 1 + rand()%20;

  short *dyn = malloc(mydim * sizeof(short));

  for(int i = 0; i < mydim; ++i)
    dyn[i] = vla[i];


  return 0;
}

