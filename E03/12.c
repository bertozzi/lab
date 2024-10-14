// si prenda in ingresso un ammontare in EUR, un tasso di interesse
// annuale (x in %), e una durata in anni n. Si stampi come varia
// l'ammontare inserito anno per anno se ogni anno applichiamo il
// tasso di interesse x per n anni.

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  int durata;
  float cash, tasso;

  printf("Inserisci ammontare (EUR), tasso di interesse annuale e durata in anni: ");
  scanf("%f%f%d", &cash, &tasso, &durata);

  for(int i = 0; i < durata; ++i)
    cash = cash + cash*tasso/100.0;

  printf("Dopo %d anni ti troverai %f EUR\n", durata, cash);


  return 0;
}

