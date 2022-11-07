#include<stdio.h>
#include<stdlib.h>

#include<ctype.h>

char leggifile(short year);
void calcolapasqua(char);

int main(int argc, char **argv){

  int anno;

  printf("Inserisci anno per cui calcolare la pasqua: ");
  scanf("%d", &anno);
  char c=leggifile(anno);
  calcolapasqua(c);


  return 0;
}

char leggifile(short year)
{
  // calcolare decade in base ad anno
  // aprire file
  // leggere riga per riga fino alla decade cercata
  // calcolare anno della decade
  // leggere carattere corrispondente dal file
  // chiudere il file
  // restituire il carattere trovato

  int anno  = year % 10;
  int decade = year - anno;
  FILE *pasqua=fopen("pasqua.txt", "r");
  if(!pasqua)
  {
    perror("Errore");
    exit(EXIT_FAILURE);
  }

  int riga;
  char s[11];

  while(fscanf(pasqua, "%d %s %s", &riga, s, &s[5])==3 && riga!=decade);

  fclose(pasqua);

  if(riga!=decade)
  {
    fprintf(stderr, "errore non trovo l'anno\n");
    exit(EXIT_FAILURE);
  }

  return s[anno];
}

void calcolapasqua(char c)
{

  // guardo se cifra o carattere
  if(isdigit(c))
  {
    if(c>='2') printf("La data della Pasqua e’: 2%c marzo\n", c);
    else       printf("La data della Pasqua e’: 3%c marzo\n", c);
  }
  else if(isalpha(c))
  {
    c=tolower(c); // scomodo considerare lettere maiuscole e minuscole, trasformo tutto in minuscolo
    int giorno=c-'a'+1; // giorno varra' 1 se c contiene codice ascii di a, 2 se b, ecc.
    printf("La data della Pasqua e’: %d aprile\n", giorno);
  }
  else
  {
    fprintf(stderr, "Errore in calcolapasqua(), carattere non consentito\n");
    exit(EXIT_FAILURE);
  }
}
