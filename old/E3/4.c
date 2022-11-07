#include<stdio.h>
#include<stdlib.h>

// 5. legge due date nel formato GG/MM/AAAA e stampa la differenza in giorni tra le due

int main(int argc, char **argv){
  int mm1, gg1, aa1, mm2, gg2, aa2;

  printf("Inserisci una data in formato GG/MM/AAA: ");
  scanf("%d/%d/%d", &gg1, &mm1, &aa1);
  printf("Hai inserito %d-%d-%d\n", gg1, mm1, aa1);

  // TBD

  return 0;
}

