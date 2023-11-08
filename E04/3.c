#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char **argv){
  int a[100];

  srand(time(0));

  for(int i = 0; i < 100; ++i)
    a[i] = 10 + rand() % (80 - 10 + 1);

  int needle;
  printf("Inserisci un numero tra 10 e 80 da cercare: ");
  scanf("%d", &needle);

  // int found = 0; // flag per capire se ho trovato o meno il valore
  int i; // necessario per usarlo anche fuori del for()
  for(i = 0; i < 100; ++i)
    if(a[i] == needle)
    {
      printf("Valore %d trovato all'indice %d\n", needle, i);
      // found = 1;
      break;
    }

  // if(!found)
  if(i == 100)
    printf("Il valore cercato non e' presente\n");

  printf("\n");

  return 0;
}

