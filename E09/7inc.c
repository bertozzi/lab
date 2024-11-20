/*
7. scrivere una funzione che viene invocata passando due variabili. La
   funzione deve scambiare il contenuto delle due variabili. Si riesce
   a farlo?

*/

void scambia(int a, int b)
{
  int tmp;
  tmp = a;
  a   = b;
  b   = tmp;
}

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int a = 10;
  int b = 55;

  printf("Prima  di invocare la funzione a contiene %d e b contiene %d\n", a, b);
  scambia(a, b);
  printf("Dopo aver invocato la funzione a contiene %d e b contiene %d\n", a, b);


  return 0;
}

