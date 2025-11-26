/*
3. Array statico di stringhe: si definisca un array di stringhe,
   inizializzandolo con i nomi dei sette nani: Mammolo, Brontolo,
   Eolo, Pisolo, Dotto, Gongolo, Cucciolo Quali sintassi posso usare?
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  // prima possibilita' array bidimensionale "puro"
  //char nani[7][15] = { "Mammolo", "Brontolo", "Eolo", "Pisolo", "Dotto", "Gongolo", "Cucciolo" };
  // non si usa in quanto spreco spazio

  // seconda possibilita' array di array
  //char *nani[7] = { "Mammolo", "Brontolo", "Eolo", "Pisolo", "Dotto", "Gongolo", "Cucciolo" };

  // terza possibilita' come la precedente ma visto che inizializzo array posso omettere dimensioni
  char *nani[] = { "Mammolo", "Brontolo", "Eolo", "Pisolo", "Dotto", "Gongolo", "Cucciolo", "Fuffolo" };

  for(int i = 0; i < sizeof(nani)/sizeof(nani[0]); ++i) // uso il rapporto dimensioni array e dimensioni singolo elemento (o riga nel caso dell'array statico) per
							// calcolare quanti elementi ho
    printf("Il nano di indice #%d e' %s\n", i, nani[i]);

  return 0;
}


