#include<stdio.h>
#include<stdlib.h>

/* 
   3. legge da tastiera una sequenza di 16 risposte si/no (i soli caratteri S e N) e impacchetti i risultati una variabile short sfruttandone i 16 bit. A tal fine, si consideri N=0 e S=1.
   4. integri quanto sviluppato al punto precedente considerando di confrontare le risposte con il risultato. Si assegni 1 punto per ciascuna risposta corretta e 0 per ciascuna risposta sbagliata.
   Le risposte fornite vanno estratte dalla variabile in cui sono state impacchettate al punto precedente e confrontate con la soluzione del quiz che è 14571

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

    // coded_ris = (ris == 'S' ? 1 : 0);

    packed_ris = (packed_ris << 1) | coded_ris;
  }

  printf("Le risposte codificate valgono %d (%x)\n", packed_ris, packed_ris);

  unsigned short packed_corrette = 14571;

  int punteggio = 0;
  for(int i = 0; i<16; ++i)
  {
    int ris    = (packed_ris >> i) & 1;
    int giusta = (packed_corrette >> i) & 1;

    if(ris == giusta) 
      ++punteggio;
  }

  printf("Hai ottenuto %d punti\n", punteggio);

  return 0;
}

