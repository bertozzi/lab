/*
   Per calcolare la radice quadrata di un numero si puo' usare l'algoritmo di Newton. Dato un numero n di cui calcolare la radice, inizializzo il risultato r a 1. Ad ogni iterazione aggiorno r come valor medio tra r stesso e n/r Mi fermo quando l'aggiornamento di r e' inferiore a 10^-6 Confrontare il risultato con quanto restituito da sqrt(n)
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char **argv){

  /*
     1. chiedo all'utente un numero n (a virgola mobile)
     2. inizializzo r a 1
     3. entro in un ciclo
      3a. aggiorno r come valore medio tra r e n/r
      3b. l'aggiornamento fatto e' inferiore a .000001 ?
       si' -> termino il ciclo
     4. stampo il risultato e il valore di sqrt(n)

     */

  // 1
  double n;
  printf("Inserisci un numero di cui vuoi calcolare la radice: ");
  scanf("%lf", &n);

  // 2
  double r=1, old_r; // old_r mi serve piuì avanto per calcolare l'aggiornamento

  // 3
  do
  {
    // 3a 
    old_r = r; // mi salvo la precedente approssimazione
    r = (r + n/r)/2;

    // 3b 
  }while(fabsl(r - old_r) >= .000001); // r - old_r mi rappresenta l'aggiornamento (e' sempre vero?)

  printf("Il risultato e' %f\n", r);
  printf("Il risultato di sqrt(%f) e' %f\n", n, sqrt(n));

  return 0;
}

