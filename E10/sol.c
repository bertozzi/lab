#include<stdio.h>
#include<stdlib.h>

/* POSSIBILE ALGORITMO PER UNA SINGOLA RIGA

   Devo tener traccia di quanti numeri leggo
   inizializzo n_num = 0
   Devo tener traccia di lunghezze sequenze crescenti o decrescenti
   Inizializzo l_cresc = 0 e l_decr = 0
   Ma anche di quante sono
   Inizializzo n_cresc = 0 e n_decr = 0
   Caso particolare: eventuali numeri uguali ad inizio sequenza, li conto
   inizializzo l_eq = 0
   L'idea e' confrontare i numeri due alla volta partendo ad inizio riga
   Devo anche tener traccia se ero all'interno di una sequenza crescente o decrescente
   uso variabile di stato che assumera' i valori 1 -> sequenza crescente, -1 -> sequenza decrescente, 0 -> iniziale sequenza di numero uguali
   Inizializzo stato = 0

   Leggo primo numero A
   incremento n_num
X: Leggo secondo numero B
   B == 0?
     termino analisi riga, calcolo e stampo i risultati

   incremento n_num

   Se B>A vuol dire sequenza crescente
   incremento l_cresc
   Ero gia' in sequenza crescente? Ovvero stato era == 1?
    No: 
        nuova sequenza quindi incremento n_cresc
	c'era una sequenza precedente di numeri uguali (ovvero stato == 0)?
	SI':
	     sommo a l_cresc l_eq
        aggiorno stato di modo da tener traccia che sono in sequenza crescente stato = 1

   Se B<A vuol dire sequenza decrescente
   incremento l_decr
   Ero gia' in sequenza decrescente? Ovvero stato era == -1?
    No: 
        nuova sequenza quindi incremento n_descr
	c'era una sequenza precedente di numeri uguali (ovvero stato == 0)?
	SI':
	     sommo a l_decr l_eq
        aggiorno stato di modo da tener traccia che sono in sequenza decrescente stato = -1

    Se B==A sono in sequenza crescente o decrescente a seconda dello stato precedente
     se stato == 1 -> sequenza crescente
       incremento l_cresc
     se stato == -1 -> sequenza decrescente
       incremento l_decr
     se stato == 0 -> non ho ancora incontrato variazioni di valore e non posso ancora decidere se andro' verso l'alto o verso il basso, ne tengo comunque traccia
       incremento l_eq

       Copio valore di B in A
       ripeto da X
       */

int main(int argc, char **argv){


  FILE *fp = fopen("dati.txt", "r");
  if(!fp)
  {
    perror("");
    exit(EXIT_FAILURE);
  }

  int a, b;

  // questo ciclo di fatto viene ripetuto per ciascuna riga
  while(1) // non esco, non serve capire fine file, lo capisco dai dati quando leggo
  {
    // DA QUI IN POI ANALIZZO RIGA, DI FATTO IMPLEMENTO ALGORITMO DESCRITTO NEI COMMENTI INIZIALI

    int n_num=0;
    int n_cresc = 0, n_decr = 0;
    int l_cresc = 0, l_decr = 0, l_eq = 0;
    int stato = 0;


    fscanf(fp, "%d", &a);
    if(!a) // non descritto sopra, se primo numero in riga = 0 allora esco
      exit(EXIT_SUCCESS);
    ++n_num;

    while(1)
    {
      fscanf(fp, "%d", &b);
      if(!b) 
	break;
      ++n_num;

      if(b > a || (b == a && stato == 1) ) // sequenza crescente
      {
	++l_cresc;
	if(stato != 1)
	{
	  ++n_cresc;
	  if(!stato)
	    l_cresc += l_eq;
	  stato = 1;
	}
      }

      if(b < a || (b == a && stato == -1) ) // sequenza decrescente
      {
	++l_decr;
	if(stato != -1)
	{
	  ++n_decr;
	  if(!stato)
	    l_decr += l_eq;
	  stato = -1;
	}
      }

      if( a == b && !stato)
	++l_eq;


      a = b;
    }

    printf("Dati letti = %d: ", n_num);
    float media_cresc = 0, media_decr = 0;
    if(n_cresc > 0) media_cresc = l_cresc/(float)n_cresc;
    if(n_decr > 0) media_decr = l_decr/(float)n_decr;
    printf("%.2f %.2f\n", media_cresc, media_decr);
  }

  return 0;
}

