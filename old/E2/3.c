#include<stdio.h>
#include<stdlib.h>

/*
3. implementi il seguente algoritmo:
 a:  input n
 inizializzo un contatore c a 0
 b:  ouput n
 incremento c di 1
 c:  se n = 1, salta a f
 d:  se n è dispari, n <-- 3n+1:  altrimenti, n <-- n/2
 e:  ripeti da b
 f: stampa la lunghezza della sequenza ottenuta ovvero stampa c
 */

int main(int argc, char **argv){

  int n;
  printf("Inserisci un numero >=1: ");
  scanf("%d", &n);

  int c = 0;

  printf("%d ", n);
  c = c + 1;

  while(n!=1)
  {
    if(n%2==1) 
      n = 3*n + 1;
    else
      n = n/2;

    printf("%d ", n);
    c = c + 1;
  }

  // ripeti da b

  printf("\nLa sequenza ottenuta e' lunga %d\n", c);

  return 0;
}

