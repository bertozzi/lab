#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void leggi_frequenze(float dati[]);
char estrai_lettera(float dati[]);
int controlla_lettere(char parola[], char lettere[]);
int controlla_dizionario(char parola[]);

int main(int argc, char **argv){

  srand(time(0));

  float percentile[26];
  leggi_frequenze(percentile);

  //   stampa di debug
  //for(int i=0; i < 26; ++i)
  //  printf("%c: %f\n", 'a' + i, percentile[i]);

  char lettere[13];
  for(int i=0; i < 12; ++i)
    lettere[i] = estrai_lettera(percentile);
  lettere[12] = '\0';
  printf("Le lettere estratte sono %s\n", lettere);

  char parola[13];
  printf("Inserisci una parola: ");
  scanf(" %s", parola);
  printf("Ho letto da tastiera %s\n", parola);

  if( !controlla_lettere(parola, lettere) )
  {
    printf("La parola '%s' non risulta componibile usando le lettere estratte\n", parola);
    exit(1);
  }

  if( !controlla_dizionario(parola) )
  {
    printf("Mi dispiace hai inserito una parola non ammessa\n");
  }
  else
  {
    printf("Complimenti tutto giusto!\n");
  }

  return 0;
}



int controlla_dizionario(char parola[])
{
  FILE *dict = fopen("dizionario.txt", "r");
  if(!dict)
  {
    perror("");
    exit(1);
  }

  char word[1000];

  while( fscanf(dict, " %s", word)  == 1 )
  {
    if( ! strcmp(word, parola) )
    {
      fclose(dict);
      return 1;
    }
  }
  fclose(dict);
  return 0;
}

char estrai_lettera(float dati[])
{
  float caso = rand()/(float)RAND_MAX;

  for(int i=0; i < 26; ++i)
    if(dati[i] > caso)
      return 'a' + i;
}

int controlla_lettere(char parola[], char lettere[])
{
  for(int i=0; i < strlen(parola); ++i)
  {
    char *ricerca = strchr(lettere, parola[i]);
    if(!ricerca)
      return 0;
    *ricerca =  '*';
  }
  return 1;
}


















void leggi_frequenze(float dati[])
{
  FILE *freq = fopen("letterfreq.txt", "r");
  if(!freq)
  {
    perror("");
    exit(1);
  }

  char lettera;
  float frequenza; 
  
  while( fscanf(freq, " %c %f", &lettera, &frequenza) == 2)
  {
    dati[ lettera - 'a' ] = frequenza;
  }
  fclose(freq);

  for(int i=1; i < 26; ++i)
    dati[i] = dati[i] + dati[i-1];

}


