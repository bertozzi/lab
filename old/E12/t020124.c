#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h> // per memcpy()

#define MSIZE (8)

// void copiamatrice(int dest[MSIZE][MSIZE], int src[MSIZE][MSIZE])
void stampamatrice(int m[MSIZE][MSIZE]);
int minvicini(int m[MSIZE][MSIZE], int r, int c);

int main(int argc, char **argv){

  int m[MSIZE][MSIZE]={}, mp[MSIZE][MSIZE];

  srand(time(0));

  int i,j;
  /*
  for(i=0; i<3; ++i)
  {
    m[rand()%MSIZE][rand()%MSIZE] = 1;
  }
  */

  j=rand()%3+1;
  for(i=0; i<j; ++i)
  {
    int r=rand()%MSIZE;
    int c=rand()%MSIZE;
    if(!m[r][c]) m[r][c]=1;
    else --i;
  }

  stampamatrice(m);

  int cisonozeri;
  do
  {
    cisonozeri=0;
    for(i=0; i<MSIZE; ++i)
    {
      for(j=0; j<MSIZE; ++j)
      {
	if(m[i][j])
	  mp[i][j]=m[i][j];
	else
	  mp[i][j]=minvicini(m, i, j);

	if(!mp[i][j])
	  cisonozeri=1;
      }
    }
    stampamatrice(mp);
    //copiamatrice(m, mp);
    memcpy(m, mp, MSIZE*MSIZE*sizeof(m[0][0]));

  }while(cisonozeri);



  return 0;
}

void stampamatrice(int m[MSIZE][MSIZE])
{
  int i,j;
  for(i=0; i<MSIZE; ++i)
  {
    for(j=0; j<MSIZE; ++j)
      printf("%d ", m[i][j]);
    printf("\n");
  }

  printf("\n");
}

int minvicini(int m[MSIZE][MSIZE], int r, int c)
{
  int or, oc;

  int min_val=1000; // FIXME usare limit.h
  for(oc=-1; oc <=1; ++oc) // ciclo su vicinato ovvero su elementi che hanno riga/colonna +-1 rispetto elemento in esame
    for(or=-1; or <=1; ++or)
    {
      int rv=r+or; // coordinata riga elemento vicino
      int cv=c+oc; // coordinata colonna elemento vicino
      if (rv>=0 && rv<MSIZE && cv>=0 && cv<MSIZE && m[rv][cv] && min_val > m[rv][cv])
       	min_val=m[rv][cv];
    }

  if(min_val != 1000) return min_val+1;
  else return 0;
}


/*
void copiamatrice(int dest[MSIZE][MSIZE], int src[MSIZE][MSIZE])
{
  int i,j;
  for(i=0; i<MSIZE; ++i)
    for(j=0; j<MSIZE; ++j)
      dest[i][j]=src[i][j];
}
*/
