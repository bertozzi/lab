#include<stdio.h>
#include<stdlib.h>

// 4. legge da tastiera 4 char, stampa il loro valore numerico in esadecimale, li impacchetta in un int e stampa il valore dell'int cosi' ottenuto sempre in esadecimale

int main(int argc, char **argv){
  char a, b, c, d;

  printf("Inserisci 4 char: ");
  scanf(" %c %c %c %c", &a, &b, &c, &d);

  printf("Hai inserito i seguenti caratteri [%c] [%c] [%c] [%c]\n", a,b,c,d);
  printf("Che hanno i seguenti codici ASCII %d %d %d %d\n", a,b,c,d);
  printf("In esadecimale: %02x %02x %02x %02x\n", a,b,c,d);

  int packed=0;
  //printf("Packed in esadecimale %08x\n", packed);

  packed = packed | a;
  //printf("Packed in esadecimale %08x\n", packed);

  packed = packed << 8;
  //printf("Packed in esadecimale %08x\n", packed);

  packed = packed | b;
  packed = packed << 8;

  packed = packed | c;
  packed = packed << 8;

  packed = packed | d;
  
  printf("Packed in esadecimale %08x\n", packed);

  return 0;
}

