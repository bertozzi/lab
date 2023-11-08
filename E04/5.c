// 5. usi rand() per riempire un array di 100 elementi con numeri interi
//    univoci tra 1 e 300 e lo stampi

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char **argv){
  int a[100];

  srand(time(0));

  for(int i = 0; i < 100; ++i)
  {
    int gen;    // variabile che conterra' il valore generato casualmente da ricercarsi tra quelli gia' inseriti nell'array
    int found;  // flag in cui segnero' se il valore generato viene trovato tra i valori precedentemente generati
    do
    {
     gen = 1 + rand() % (300);   // genero valore casuale in [1,300]
     found = 0;
     for(int j = 0; j < i; ++j) // ciclo di ricerca
       if(a[j] == gen)
       {
	 found = 1; // se trovo il valore inserito lo segno e fermo la ricerca
	 break;
       }
    }
    while(found); // ripeto se il valore era gia' presente

    a[i] = gen;

  }

  for(int i = 0; i < 100; ++i)
    printf("%d ", a[i]);

  printf("\n");

  return 0;
}

