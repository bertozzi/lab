/* Nelle vecchie tastiere dei telefoni vi erano associazioni numero -> lettere (1=ABC, 2=DEF, 3=GHI, 4=JKL, 5=MNO, 6=PQR,
 * 7=STU, 8=VWX, 9=YZ)
   Data in ingresso una sequenza di caratteri stampare i corrispondenti numeri.
   Ad esempio MASSIMO -> 5177355
*/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  // 1. leggere un carattere
  // 2. e' un a capo?
  // 2a. si' -> esco
  // 2b. no -> converto e stampo
  // 3. ripeto da 1

  for(;;) // ciclo che implementa il punto (3)
  {
    // 1
    char c;
    scanf("%c", &c);
    // 2
    if(c == '\n')
    {
      break; // 2a
    }
    else
    {
      // 2b
      printf("%d", (c -'A')/3 + 1);
    }
  }
  printf("\n");

  return 0;
}

