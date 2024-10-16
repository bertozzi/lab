//   leggere da tastiera un numero, stampare quante cifre ha
//   (suggerimento, dividere per 10 fino a che il risultato non è 0)


#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int n;

  printf("Inserisci un numero intero positivo: ");
  scanf("%d", &n);

  int ncifre = 0;

  printf("Il numero di cifre di %d e' ", n);

  do
  {
    n = n/10;  // potevo scrivere come n /= 10;
    ++ncifre;
  }
  while(n);

  printf("%d\n", ncifre);


  return 0;
}

