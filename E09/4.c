/*
4. scrivere una funzione "bisestile" che prende in ingresso un anno e
   restituisce vero o falso a seconda che l'anno in questione sia o
   meno bisestile. Si rammenta che sono bisestili gli anni esattamente
   divisibili per 4 con l'eccezione di quelli divisibili esattamente
   da 100 ma non da 400
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

int main(int argc, char **argv){

  int y;
  printf("Inserisci anno: ");
  scanf("%d", &y);

  printf("bisestile(%d) mi restituisce %d\n", y, bisestile(y));

  return 0;
}

