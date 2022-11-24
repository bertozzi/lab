#include<stdio.h>
#include<stdlib.h>

void stampa(int n, int pile[n][n], int altezze[])
{
  // stampiamo per debug
  for(int i = 0; i < n; ++i)
  {
    printf("Pila di indice %d: ", i);
    for(int j = 0; j < altezze[i]; ++j)
    {
      printf("%d ", pile[j][i]);
    }
    printf("\n");
  }

}

int main(int argc, char **argv){

  FILE *f = fopen("dati.txt", "r");
  if(!f)
  {
    perror("");
    exit(1);
  }

  int n;
  fscanf(f, "%d", &n);
  printf("Il numero di posizioni da gestire e' %d\n", n);

  int pile[n][n]; // situazione blocchetti, ogni colonna mi contiene i blocchetti nella posizione x
  int altezza[n];   // altezza delle pile, la colonna di indice x mi dice quanti blocchetti ho nella colonna x di pile[][]

  for(int i = 0; i < n; ++i)
  {
    pile[0][i] = i; 
    altezza[i] = 1;
  }

  stampa(n, pile, altezza);

  int a, b;
  while( fscanf(f, "%d%d", &a, &b) == 2 )
  {
    printf("Spostamento da fare %d -> %d\n", a, b);
    // b indice di colonna destinazione nella matrice pile[][]
    // a indice di colonna sorgente
    // la relativa riga la trovo tramite altezza[a]  e altezza[b]

    // prima di fare lo spostamento controllo se nella pila da prelevare ci sono elementi o meno
    if(altezza[a] > 0)
    {
      // riga elemento destinazione (indice prima cella vuota in quella colonna)
      int dest_riga = altezza[b];
      // riga elemento sorgente (decremento di 1 in quanto gli indici partono da 0)
      int src_riga  = altezza[a] - 1; 
      pile[dest_riga][b]  =  pile[src_riga][a];

      altezza[a]--;
      altezza[b]++;
    }

    // stampiamo per debug
    stampa(n, pile, altezza);

  }


  fclose(f);
  return 0;
}

