#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  printf("Inserisci un ammontare in euro: ");
  float somma;
  scanf("%f", &somma);

  printf("L'ammontare %.2f e' realizzabile usando\n", somma);

  int euro2 = somma / 2;
  somma = somma - 2 * euro2;
  printf("%3d monete da 2 eur\n", euro2);

  int euro1 = somma;
  somma = somma - euro1;
  printf("%3d monete da 1 eur\n", euro1);

  //FIXME invece di usare i numeri a virgola mobile e rischiare con arrotondamenti, uso solo numeri interi

  int isomma = somma  * 100 + .5; // a cosa serve il +.5?

  int euroc50 = isomma / 50;
  isomma = isomma - euroc50 * 50;
  printf("%3d monete da 50 eurocent\n", euroc50);

  int euroc20 = isomma / 20;
  isomma = isomma - euroc20 * 20;
  printf("%3d monete da 20 eurocent\n", euroc20);

  int euroc10 = isomma  / 10;
  isomma = isomma - euroc10 * 10;
  printf("%3d monete da 10 eurocent\n", euroc10);

  int euroc05 = isomma / 5;
  isomma = isomma - euroc10 * 5;
  printf("%3d monete da 5 eurocent\n", euroc05);

  int euroc02 = isomma / 2;
  isomma = isomma - euroc02 * 2;
  printf("%3d monete da 2 eurocent\n", euroc02);

  int euroc01 = isomma;
  printf("%3d monete da 1 eurocen\n", euroc01);

  printf("Ovvero da un totale di %d monete\n", euro2 + euro1 + euroc50 + euroc20 + euroc10 + euroc05 + euroc02 + euroc01);


  return 0;
}

// provate con 7.87 ->  c'e' un errore... o meglio, i calcoli sembrano tutti giusti ma cosa succede?
// come posso ovviare

