#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  printf("Inserisci un ammontare in euro: ");
  float somma;
  scanf("%f", &somma);

  printf("L'ammontare %.2f e' realizzabile usando ", somma);

  int euro2 = somma / 2;
  somma = somma - 2 * euro2;
  printf("%3d monete da 2 eur\n", euro2);

  int euro1 = somma;
  somma = somma - euro1;
  printf("%3d monete da 1 eur\n", euro1);

  int euroc50 = somma * 2;
  somma = somma - euroc50 * .5;
  printf("%3d monete da 50 eurocent\n", euroc50);

  int euroc20 = somma * 5;
  somma = somma - euroc20 * .2;
  printf("%3d monete da 20 eurocent\n", euroc20);

  int euroc10 = somma * 10;
  somma = somma - euroc10 * .1;
  printf("%3d monete da 10 eurocent\n", euroc10);

  int euroc05 = somma * 20;
  somma = somma - euroc10 * .05;
  printf("%3d monete da 5 eurocent\n", euroc05);

  int euroc02 = somma * 50;
  somma = somma - euroc02 * .02;
  printf("%3d monete da 2 eurocent\n", euroc02);

  int euroc01 = somma * 100;
  printf("%3d monete da 1 eurocent\n", euroc01);

  printf("Ovvero da un totale di %d monete\n", euro2 + euro1 + euroc50 + euroc20 + euroc10 + euroc05 + euroc02 + euroc01);


  return 0;
}

// provate con 7.87 ->  c'e' un errore... o meglio, i calcoli sembrano tutti giusti ma cosa succede?
// come posso ovviare

