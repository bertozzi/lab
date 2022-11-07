#include<stdio.h>
#include<stdlib.h>

/* 
   3. legge da tastiera una sequenza di 16 risposte si/no (i soli caratteri S e N) e impacchetti i risultati una variabile short sfruttandone i 16 bit. A tal fine, si consideri N=0 e S=1.
*/

int main(int argc, char **argv){

  unsigned short packed_ris = 0;

  printf("Inserisci le 16 risposte S/N: ");
  for(int i = 0; i<16; ++i)
  {
    char ris; 
    scanf(" %c", &ris);

    short coded_ris;
    if(ris == 'S')
      coded_ris = 1;
    else
      coded_ris = 0;

    packed_ris = (packed_ris << 1) | coded_ris;
  }

  printf("Le risposte codificate valgono %d (%x)\n", packed_ris, packed_ris);

  return 0;
}

