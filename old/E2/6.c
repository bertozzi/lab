#include<stdio.h>
#include<stdlib.h>

// 6. prenda in ingresso due orari (come ora e minuti separatamente) e stampi la differenza in minuti tra i due~
// leggo primo orario come ora e minuti
// leggo secondo orario come ora e minuti
// trasformo primo orario in minuti
// trasformo secondo orario in minuti
// calcolo differenza 
// stampo differenza

int main(int argc, char **argv){

  int o1,m1,o2,m2;

  printf("Inserisci il primo orario come ora e minuti: ");
  scanf("%d %d", &o1, &m1);

  printf("Inserisci il secondo orario come ora e minuti: ");
  scanf("%d %d", &o2, &m2);

  int min1, min2;

  min1 = o1*60 + m1;
  min2 = o2*60 + m2;

  printf("La differenza di orario in minuti e' %d\n", abs(min1-min2));

  return 0;
}

