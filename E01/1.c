#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  // definisco variabile di tipo intero per memorizzare il numero lettto da tastiera
  int numero;

  // stampo messaggio
  printf("Inserisci un numero intero: ");

  // leggo int da tastiera, si noti il "&" davanti al nome di variabile
  scanf("%d", &numero);

  // stampo in formato decimale
  printf("Il numero inserito in base 10          e': %d\n", numero);

  // stampo in formato ottale
  printf("Il numero inserito in base ottale      e': %o\n", numero);

  // stampo in formato esadecimale
  printf("Il numero inserito in base esadecimale e': %x\n", numero);

  // stampo in formato esadecimale (con caratteri maiuscoli)
  printf("Il numero inserito in base esadecimale e': %X\n", numero);


  return 0;
}

