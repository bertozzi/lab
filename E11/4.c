/*
3. Array statico di stringhe: si definisca un array di stringhe,
   inizializzandolo con i nomi dei sette nani: Mammolo, Brontolo,
   Eolo, Pisolo, Dotto, Gongolo, Cucciolo Quali sintassi posso usare?

4. Si modifichi il precedente esercizio di modo che il programma
   confronti quanto passato sulla linea di comando con gli elementi
   nell'array e stampi le parole presenti sulla linea di comando che
   non corrispondono al nome di alcun nano

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){

  char *nani[] = { "Mammolo", "Brontolo", "Eolo", "Pisolo", "Dotto", "Gongolo", "Cucciolo" };

  // primo ciclo su parole su linea di comando
  for(int j = 1; j < argc; ++j)
  {
    int parolatrovata = 0;  // flag che mi permette di capire se la parola c'e' nell'elenco dei nani
			    //
    // secondo ciclo sui nomi dei nani
    for(int i = 0; i < sizeof(nani)/sizeof(nani[0]); ++i) // uso il rapporto dimensioni array e dimensioni singolo elemento (o riga nel caso dell'array statico) per
    {
      if(!strcmp(argv[j], nani[i]))
      {
	parolatrovata = 1;
	break;
      }
    }

    if(!parolatrovata) // non corrispondeva a nessun nome di nano quindi...
      printf("La parola %s non corrisponde a nessun nome di nano\n", argv[j]);
  }

  return 0;
}

// PROBLEMI APERTI: maiuscole e minuscole vengono trattate differentemente. 
// Esercizio per casa: modificatelo di modo che maiuscole e minuscole non facciano differenza

