// 3. scrivere una funzione che restituisce il numero di cifre del numero
// intero passato come argomento

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int num_cifre(int x)
{
  int n = 0;
  do
  {
    ++n;
    x  = x/10;
  }
  while(x);

  return n;
}

int main(int argc, char **argv){
  srand(time(NULL));

  int y = rand(); // numero grande a piacere
  
  printf("Il numero di cifre di %d e' %d\n", y, num_cifre(y));


  return 0;
}

