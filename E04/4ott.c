// versione leggermente ottimizzata della precedente
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char **argv){
  int a[100];

  srand(time(0));

  for(int i = 0; i < 100; ++i)
    a[i] = 10 + rand() % (80 - 10 + 1);

  for(int i = 0; i < (100 - 1); ++i) // mi fermo al penultimo elemento
  {
    for(int j = i + 1; a[i] != -1  && j < 100; ++j) // considero tutti gli elementi successivi fatto salvo che a[i] non sia gia' stato eliminato
    {
      if(a[i] == a[j])
	a[j] = -1;  // valore fittizio per indicare un elemento non valido
    }
  }




  for(int i = 0; i < 100; ++i)
    if(a[i] != -1)
      printf("%d ", a[i]);

  printf("\n");

  return 0;
}

