#include<stdio.h>
#include<stdlib.h>

void dectobyte(int, char *);
FILE *aprifile(const char *nomefile, const char *mode);

int main(int argc, char **argv){
  // 1. leggere riga di comando
  if(argc<3)
  {
    fprintf(stderr, "Errore devi passare i nomi dei 2 file\n");
    exit(1);
  }

  // 2. aprire i file
  FILE *fin=aprifile(argv[1], "r");
  FILE *fout=aprifile(argv[2], "w");

  // 3. leggere il primo file riga per riga
  int ip[4];
  while(fscanf(fin, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]) == 4)
  {
    //printf("Ho letto %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);

    // 4. convertire i 4 numeri letti
    char bin[9];
    int i;
    for(i=0; i<4; ++i)
    {
      dectobyte(ip[i], bin);
      //printf("Ho ottenuto %s da %d\n", bin, ip[i]);
      // 5. scrivere su secondo file la conversione
      fprintf(fout, "%s", bin);
    }
    fprintf(fout, "\n");
  }


  fclose(fin);
  fclose(fout);
  return 0;
}

void dectobyte(int n, char *s)
{
  int i;
  for(i=0; i<8; ++i)
  {
    int bindigit=n%2;
    n = n/2;
    s[7-i]='0'+bindigit;
  }
  s[8]='\0';
}

FILE *aprifile(const char *nomefile, const char *mode)
{
  FILE *fp=fopen(nomefile, mode);
  if(!fp)
  {
    perror("Errore in apertura file");
    exit(1);
  }
  return fp;
}
