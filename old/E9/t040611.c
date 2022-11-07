#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// SOLO ABBOZZATA PARTE MESE

int calcolamese(const char *mese)
{
  const char *mesi[]={"gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio",
  "agosto", "settembre", "ottobre", "novembre", "dicembre"};
  int i;

  for(i=0;i<12;++i)
    if(!strcasecmp(mese,mesi[i]))
      return i;

  return -1;
}


int main(int argc, char **argv){

  char mese[100];

  printf("Inserisci il mese: ");
  scanf("%s", mese);

  int indicemese=calcolamese(mese);
  printf("L'indice del mese e' %d\n", indicemese);


  return 0;
}

