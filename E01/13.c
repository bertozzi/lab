/* 13 le attuali aliquote IRPEF prevedono una tassazione del 23% per la
   quota di reddito imponibile fino a 15.000 EUR, del 25% per la parte
   tra 15.001 e 28.000 EUR del 35% per la quota tra 28.001 e 50.000
   EUR, e del 43% per quanto oltre i 50.000. Chiedere all'utente una
   cifra di imponibile e stampare a video l'ammontare IRPEF e la
   relativa aliquota media.
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  float imponibile;
  printf("Qual e' l'imponibile? ");
  scanf("%f", &imponibile);

  float irpef;
  if(imponibile <= 15000)
  {
    irpef = imponibile * 0.23;
  }
  else if(imponibile <= 28000)
  {
    irpef = 15000*.23 + (imponibile - 15000)*.28;
  }
  else if(imponibile <= 50000)
  {
    irpef = 15000*.23 + (28000 - 15000)*.28 + (imponibile - 28000)*.35;
  }
  else
    irpef = 15000*.23 + (28000 - 15000)*.28 + (50000 - 28000)*.35 + (imponibile - 50000)*.43;

  printf("L'ammontare IRPEF per un imponibile di %.2f EUR vale %.2f\n", imponibile, irpef);
  printf("L'aliquota media IRPEF vale %.2f\n", irpef/imponibile*100);


  return 0;
}

