/*
2. scrivere una funzione del tipo max(a,b) che restituisce il valore
   massimo tra a e b Implementare successivamente una seconda funzione
   che, sfruttando la precedente, restituisce il massimo tra 4 valori
*/



#include<stdio.h>
#include<stdlib.h>

// il testo non indica il tipo di dato e quindi per semplicita' scegliamo int ma tutte le altre scelte
// erano comunque valide

// prototipi delle funzioni, indicano al compilatore come e' la fatta la funzione anche prima di incontrarla
int max(int, int);
int max4(int, int, int, int);


int main(int argc, char **argv){

  int n[4];

  printf("Inserisci 4 numeri: ");
  scanf("%d%d%d%d", &n[0], &n[1], &n[2], &n[3]);

  printf("Il piu' alto dei 4 valori inseriti e' %d\n", max4(n[0], n[1], n[2], n[3]) );


  return 0;
}

int max4(int a, int b, int c, int d)
{
  return max(max(a, b),  max(c, d));
}

int max(int a, int b)
{
  if(a > b)
    return a;
  else
    return b;

  // potevo anche usare l'operatore ? del C che e' in pratica un if-else in linea
  // return (a > b)? a : b;
}

