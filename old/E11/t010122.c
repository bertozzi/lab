#include<stdio.h>
#include<stdlib.h>

struct nominativo
{
  char nome[100];
  int matricola;
};

// primo argomento: chiave che sto  cercando
// secondo argomento: elemento array
int compara_chiave(const void* k, const void* elem)
{
  const struct nominativo *pelem=elem;
  const int *chiave=k;

  return *chiave - pelem->matricola;
}

int compara_nomi(const void* a, const void*b)
{
  const struct nominativo *pa=a;
  const struct nominativo *pb=b;

  return pa->matricola - pb->matricola;
}

int main(int argc, char **argv){

  struct nominativo riga;

  FILE *fp=fopen("nomi.txt", "r");
  if(!fp)
  {
    perror("errore apertura file");
    exit(EXIT_FAILURE);
  }

  struct nominativo *nomi=NULL;
  int len=0;
  while( fscanf(fp, " %[A-Za-z \t]#%d", riga.nome, &riga.matricola) == 2)
  {
    ++len;
    nomi=realloc(nomi, len*sizeof(struct nominativo));
    nomi[len-1]=riga;
  }

  // void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

  qsort(nomi, len, sizeof(nomi[0]), compara_nomi);

  int i;

  while(1)
  {
    printf("Inserisci un numero: ");
    scanf("%d", &i);
    if(i<10)
    {
      for(i=0; i<len; ++i)
	printf("%5d: %s\n",  nomi[i].matricola, nomi[i].nome);
    }
    else
    {
      // void *bsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
      struct nominativo *item = bsearch(&i , nomi, len, sizeof(nomi[0]), compara_chiave);

      if(!item)
	printf("Non ho trovato la matricola\n");
      else
	printf("%5d: %s\n",  item->matricola, item->nome);
    }
  }

  return 0;
}

