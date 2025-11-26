/*
5. Allocazione dinamica array bidimensionali: si chieda all'utente le
   dimensioni di una matrice, si allochi dinamicamente una matrice di
   float avente quelle dimensioni (usando **), si leggano da tastiera
   gli elementi della matrice e la si stampi (in maniera ordinata)
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int r,c;
  printf("Inserire righe e colonne della matrice desiderata: ");
  scanf("%d%d", &r, &c);

  float **matr;

  // 1. alloco array di r puntatori per ciascuna riga
  matr = malloc(r * sizeof(float *));

  // 2. alloco le r righe usando il precedente array
  for(int ir = 0; ir < r; ++ir)
    matr[ir] = malloc(c * sizeof(float));


  // da questo momento in poi la sintassi per l'uso
  // degli elementi allocati dinamicamente e' la stessa
  // di un array bidimensionale!



  // chiedo all'utente i valori della matrice
  for(int ir = 0; ir < r; ++ir)
    for(int ic = 0; ic < c; ++ic)
    {
      printf("Inserisci il valore di indici  (%d, %d): ", ir, ic);
      scanf("%f", &matr[ir][ic] );  // sintassi identica array bidimensionali statici
    }


  // TODO completare



  return 0;
}

