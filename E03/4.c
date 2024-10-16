#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int z;

  do
  {
    printf("Inserisci un numero compreso tra 10 e 20: ");
    scanf("%d", &z);
  } 
  while(z < 10 || z > 20);


  return 0;
}

