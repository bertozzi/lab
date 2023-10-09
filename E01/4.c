#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  float raggio;

  printf("Inserisci il raggio della sfera: ");
  // per leggere un float si deve usare %f come specificatore di formato
  scanf("%f", &raggio);


  printf("Il volume della sfera di raggio %f e' %f\n", raggio, 4/3*3.14*raggio*raggio*raggio);
  // se eseguite questo codice noterete che sbaglia i calcoli. Eppure la formula e' corretta.

  // Vero, ma ancora una volta ci scontriamo con una divisione intera 4/3 che viene fatta prima delle altre
  // Come vedremo nel pacco di slide 07 esiste un ordine ben preciso con cui il sistema
  // calcola il valore di una epsressione. Nello specifico da sinistra a destra...
  // Per ovviare basterebbe scrivere 4*3.14/3*raggio*raggio*raggio



  return 0;
}

