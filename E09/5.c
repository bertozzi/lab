/*
5. scrivere una funzione "check_data" che restituisce vero o falso a
   seconda che la data passata come argomento (giorno, mese e anno)
   sia valida o meno. Suggerimento, ricordate la filastrocca sui mesi?
   "Trenta giorni ha novembre, con april, giugno e settembre..."
*/

#include<stdio.h>
#include<stdlib.h>

int bisestile(int year)
{
  // non e' bisestile quando
  // NON divisibile per 4
  // O
  // divisibile per 100 MA NON per 400
  
  return !( (year%4) || ( !(year%100) && (year%400) ) );
}

int check_data(int d, int m, int y)
{
  // uso i dati per semplificare il codice
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // correggo  febbraio
  if(m == 2 && bisestile(y))
    days[1]  = 29;

   return ( (m >= 1 && m <= 12) && (d >= 1 && d <=  days[m - 1]) );
}

int main(int argc, char **argv){

  int g, m, a;
  printf("Inserisci giorno, mese e anno: ");
  scanf("%d%d%d", &g, &m, &a);

  printf("check_data(%d, %d, %d) mi restituisce %d\n", g, m, a, check_data(g, m, a) );

  return 0;
}

