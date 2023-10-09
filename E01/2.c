#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  // definisco e leggo un float
  float netto;
  printf("Inserisci un ammontare in Euro: ");
  scanf("%f", &netto);

  // per stampare float occorre usare %f
  // per stampare float con sole due cifre decimali dopo la virgola occorre usare %.2f
  printf("Il totale con IVA al 22%% vale %.2f\n", netto * 1.22);


  return 0;
}

