#include<stdio.h>
#include<stdlib.h>

#define MAXLEN 78

void stampasequenza(const int *seq, const int len)
{
  int i;
  for(i=0; i<len; ++i)
    printf("%d ", seq[i]);
  printf("\n");
}

int main(int argc, char **argv){

  // 1. leggere intero n da tastiera

  int n;
  printf("Dimmi il numero di righe della sequenza da generare (max 15): ");
  scanf("%d", &n);


  // 2. inizializzare buffer con sequenza "1" e lo stampo
  int seq[MAXLEN];
  int lenseq;

  seq[0]=1;
  lenseq=1;

  
  stampasequenza(seq, lenseq);

  // secondo buffer
  int tmp[MAXLEN];
  int lentmp=0;

  // 3. ripetere n volte
  int i;
  for(i=0; i < n; ++i)
  {
    int j=0, x=1;
    int pivot=seq[0];
    for(j=1; j<lenseq; ++j)
    {
      //   a. contare i primi x numeri uguali nel primo buffer
      if(seq[j]==pivot) 
      {
	++x;
      }
      else
      {
	//   b. scrivere numero e numero ripetizioni nel secondo buffer
	tmp[lentmp]=pivot;
	tmp[lentmp+1]=x;
	lentmp = lentmp + 2;
	pivot=seq[j];
	x=1;
      }
      //   c. sono arrivato alla fine del primo buffer
      //      no -> avanzo nel primo buffer e ripeto da (a)
    }
    tmp[lentmp]=pivot;
    tmp[lentmp+1]=x;
    lentmp = lentmp + 2;

    //      si' -> stampo il secondo buffer, copio il secondo nel buffer nel primo e continuo con il ciclo
    stampasequenza(tmp, lentmp);

    // copio sia dati che lunghezza
    for(j=0; j<lentmp; ++j)
      seq[j]=tmp[j];
    lenseq=lentmp;

    // devo azzerare il buffer temporaneo
    lentmp=0;
  }


  return 0;
}

