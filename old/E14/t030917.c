#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){

  char str[81]; 

  while( scanf("%[^\n]", str) == 1)
  {
    int i;
    for(i=1; i<=strlen(str); ++i) // provo tutti i periodi possibili da 1 a lunghezza stringa
    {
      if(strlen(str) % i) continue; // il periodo deve essere divisore esatto della stringa, ignoro i periodi non adatti
      int j;
      int periodico = 1; // booleiano che mi codifica se l'elemento e' sttostringa periodica di str
      for(j=1; j<strlen(str)/i; ++j) // provero' tutti i confronti possibili della sottostringa formata dai primi i caratteri di str nelle possibili posizioni 
      {
        if( strncmp(str, str + j*i , i) ) // uso aritmetica puntatori per capire posizione per confronto
	{
	  periodico = 0;
	  break;
	}
      }

      if(periodico)
      {
	printf("Il periodo piu' piccolo e' pari a: %d\n", i);
	break;
      }
    }
  }





  return 0;
}

