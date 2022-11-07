#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
  unsigned int assenze[40]={};

  // apri file assenza
  FILE *fass;
  fass=fopen("assenze.txt", "r");

  if(!fass)
  {
    perror("Errore: ");
    exit(1);
  }


  // leggi numero lezioni/studenti
  unsigned int nlez, nstud;
  fscanf(fass,"%d %d", &nlez, &nstud);


  // cicla su numero lezioni
  int il;
  for(il=0; il<nlez; ++il)
  {
   // leggi numero assenti
    unsigned int nass;
    fscanf(fass, "%d", &nass);
     // cicla su numero assenti
    while(nass--)
    {
      // leggi e segna chi e' assente
      unsigned int assente;
      fscanf(fass, "%d", &assente);
      assenze[assente-1]++;
    }
  }

  // cicla su studenti
  for(il=0; il<nstud; ++il)
  {
   // stampa dati
    int npresenze=(int)((1-assenze[il]/(float)nlez)*100+0.5);
    printf("%d %3u %4d ", il+1, assenze[il], npresenze);
    // assenze > % ? stampa insufficienza
    if(npresenze<30) printf (" insufficiente");
    printf("\n");
  }


  return 0;
}

