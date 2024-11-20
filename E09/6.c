/*
6. scrivere una funzione "num_giorno" che restituisce, dopo aver preso
   in ingresso una data come giorno mese e anno, quanti giorni sono
   passati dall'inizio dell'anno fino a quella data
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

int num_giorno(int d, int m, int y)
{
  // uso i dati per semplificare il codice
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // correggo  febbraio
  if(m >= 2 && bisestile(y))
    days[1]  = 29;

  int num_giorni = 0;

  // accumulo prima i giorni di ciascun mese escluso quello della data
  for(int mi = 0; mi < (m - 1); ++mi)
    num_giorni += days[mi];

  // aggiungo anche i giorni del mese corrente
  num_giorni += d;

  return num_giorni;
}

  

int main(int argc, char **argv){

  int g, m, a;
  printf("Inserisci giorno, mese e anno: ");
  scanf("%d%d%d", &g, &m, &a);

  printf("num_giorno(%d, %d, %d) mi restituisce %d\n", g, m, a, num_giorno(g, m, a) );

  return 0;
}

