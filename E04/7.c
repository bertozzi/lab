// 7. Nelle vecchie tastiere dei telefoni vi erano associazioni numero -> lettere (1=ABC, 2=DEF, 3=GHI, 4=JKL, 5=MNO, 6=PQR, 7=ST, 8=UV, 9=WX, 0=YZ.)
// Data in ingresso una sequenza di caratteri stampare i corrispondenti numeri.
// Ad esempio MASSIMO -> 5177355

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  char c;

  do
  {
    scanf("%c", &c);
    switch(c)
    {
      case 'A':
      case 'B':
      case 'C':
	printf("1");
	break;
      case 'D':
      case 'E':
      case 'F':
	printf("2");
	break;
      // TODO ecc. ecc.
    }
  }
  while(c != '\n');

  return 0;
}

