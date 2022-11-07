#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compara_stringhe(const void *a, const void *b)
{
  return strcmp( *(char **)a, *(char**) b);
}

int main(int argc, char **argv){
  FILE* fp=fopen("divina.txt","r");
  int nparole=0;
  char tmp[51];

  while(fscanf(fp,"%s",tmp)==1)
    ++nparole;

  printf("Il file contiene %d parole\n",nparole);

  char **v=malloc(nparole*sizeof(char*));

  fseek(fp,0,SEEK_SET);

  int i=0;
  while(fscanf(fp,"%s",tmp)==1)
  {
    v[i]=malloc(strlen(tmp)+1);
    strcpy(v[i],tmp);
    ++i;
  }

  qsort(v,nparole,sizeof(char*),compara_stringhe);

  for(i=0;i<nparole;++i)
    printf("%s ",v[i]);


  return 0;
}

