#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 5. usi rand() per riempire un array di 100 elementi con numeri interi univoci tra 1 e 300 e lo stampi



int main(int argc, char **argv){

  srand(time(0));

  int a[100];

  for(int i=0; i<100; ++i)
  {
    int ncaso;              // serve per contenere numero generato casualmente da cercare in array
    int trovato;            // flag che mi permettera' di capire se ho trovato un duplicato
    do                               // ciclo per generazione numero univoco
    {
      ncaso = 1 + rand()%300;        // genero numero casuale in intervallo richiesto
      trovato = 0;                   // assumo sia univoco
      for(int j=0; j<i; ++j)         // ciclo per ricercare se veramente univoco
	if(ncaso == a[j])            // vera se e solo se il numero non era univoco
	{
	  trovato = 1;               // imposto flag
	  break;                     // inutile continuare
	}
    }while(trovato);                 // ripeto fino a che non genero numero che non esisteva di gia' nell'array

    a[i] = ncaso;                    // se sono qui memorizzo valore univoco
  }
  

  for(int i=0; i<100; ++i)
    printf("%3d ", a[i]);
  printf("\n");

  return 0;
}

