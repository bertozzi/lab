#include<stdio.h>
#include<stdlib.h>

struct country 
{
  int min, max;
  char name[86];
};

int controlla_codice(char *c);

int main(int argc, char **argv){

  FILE *fp = fopen("countries.txt", "r");
  if(!fp)
  {
    perror("");
    exit(EXIT_FAILURE);
  }

  struct country countries[97];

  int tmp;

  int i=0;
  while ( fscanf(fp, "%d", &tmp) == 1 )
  {
    countries[i].min = tmp;
    char separatore = fgetc(fp);
    if(separatore == '-')
      fscanf(fp, "%d", &countries[i].max);
    else
      countries[i].max = tmp;
    fscanf(fp, " %[^\n]", countries[i].name);
    ++i;
  }
  fclose(fp);


  fp = fopen("codici.txt", "r");
  if(!fp)
  {
    perror("");
    exit(EXIT_FAILURE);
  }

  char codice[14];
  while( fscanf(fp, " %s", codice) == 1 )
  {
    printf("Il codice letto e' [%s] ", codice);
    int valido = controlla_codice(codice);
    if(valido)
      printf("ed e' un valido codice EAN-13\n");
    else
      printf("e NON e' un valido codice EAN-13\n");
  }

  return 0;
}

int controlla_codice(char *c)
{
  int check;

  int sommadispari = 0;
  for(int i=0; i<=10; i += 2)
    sommadispari += c[i] - '0';

  int sommapari = 0;
  for(int i=1; i<=11; i += 2)
    sommapari += c[i] - '0';

  int sum_resto = (sommapari + sommadispari*3) % 10;

  if(sum_resto)
    check = 10 - sum_resto;
  else
    check = 0;

  if(c[12] == (check + '0'))
    return 1;
  else
    return 0;
}











