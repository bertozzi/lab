// 6. Calcolare il numero piu' grande per cui io riesco a calcolare il fattoriale

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  unsigned long long n  = 2;
  unsigned long long prec  = 0;
  unsigned long long fatt = 1;

  do
  {
    prec = fatt;

    fatt = 1;
    for(unsigned long long i = 2; i <= n; ++i)
      fatt = fatt * i;

    printf("Il fattoriale di %llu vale %llu\n", n, fatt);
    ++n;

  }
  while(fatt > prec);


  return 0;
}

