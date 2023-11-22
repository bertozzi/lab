/*
7. scrivere una funzione che viene invocata passando due variabili. La
   funzione deve scambiare il contenuto delle due variabili. Si riesce
   a farlo?
*/

#include<stdio.h>
#include<stdlib.h>

void swap(int, int);

int main(int argc, char **argv){

  int a, b;
  printf("Insersci due numeri: ");
  scanf("%d%d", &a, &b);

  printf("DEBUG: prima della swap() a=%d e b=%d\n", a, b);
  swap(a, b);
  printf("DEBUG: dopo la     swap() a=%d e b=%d\n", a, b);


  swap(88, 99);
  return 0;
}

void swap(int x, int y)
{
  printf("DEBUG: ho ricevuto da scambiare %d e %d\n", x, y);
  int tmp = x; // variabile di appoggio per scambio
  x = y;
  y = tmp;
  printf("DEBUG: dopo lo scambio sono %d e %d\n", x, y);
}

