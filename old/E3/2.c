#include<stdio.h>
#include<stdlib.h>

// 2. prenda in ingresso un long int N e stampi in esadecimale gli 8 byte che lo compongono (si usi un ciclo for(), scorrimento e and bit a bit)


int main(int argc, char **argv){

  long int N;
  printf("Inserisci un numero intero: ");
  scanf("%ld", &N);
  
  printf("Il numero che hai inserito e' %ld e in esadecimale: %016lx\n", N, N);

  int ii;
  for(ii=(sizeof(N))*8-4;  ii>=0;  ii=ii-4)
  {
    int cifra=((N>>ii)&15);
    if(cifra<=9) 
      printf("%d", cifra);
    else 
      printf("%c", 'A'+(cifra-10));
  }
  printf("\n");


  return 0;
}

