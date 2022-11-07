#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(const int a, const int b)
{
  return (a<b ? a : b);
}

int main(int argc, char **argv){


  //1. si prendano in ingresso due stringhe s e t

  char s[100], t[100];

  printf("Inserisci la stringa s: ");
  scanf("%s", s);
  printf("Inserisci la stringa t: ");
  scanf("%s", t);


  //2. si calcolino n=lunghezza(s) e m=lunghezza(t)

  int n=strlen(s);
  int m=strlen(t);


  //2.1. se n=0 si ha DL=m, stampare DL e terminare
  if(!n) 
  {
    printf("DL=%d\n", m);
    exit(EXIT_SUCCESS);
  }

  //2.2. se m=0 si ha DL=n, stampare DL e terminare
  if(!m) 
  {
    printf("DL=%d\n", n);
    exit(EXIT_SUCCESS);
  }

  //3. inizializzare una matrice d di n+1 colonne e m+1 righe:
  int mat[100][100]={};
  int i, j;

  //3.1. la prima riga della matrice deve contenere i valori da 0 a n
  for(i=0; i<=n; ++i) mat[0][i]=i;

  //3.2. la prima colonna della matrice deve contenere i valori da 0 a m
  for(i=0; i<=m; ++i) mat[i][0]=i;

  //4. si prendano in considerazione ciascun carattere di s (s[i] con i che varia da 0 a n-1) e ciascun
  //carattere di t (t[j] con j che varia da 0 a m-1)
  for(i=0; i<n; ++i)
    for(j=0; j<m; ++j)
    {
      //4.1. se t[j]=s[i] allora costo=0 altrimenti costo=1
      int costo;
      if(t[j]==s[i]) costo=0;
      else           costo=1;
      //4.2. si imposti il valore della cella della matrice d di coordinate (j+1,i+1) pari al minimo valore di:
      //• valore della cella di coordinate (j+1,i) + 1
      //• valore della cella di coordinate (j,i+1) + 1
      //• valore della cella di coordinate (j,i) + costo
      mat[j+1][i+1]=min(mat[j+1][i]+1, min(mat[j][i+1]*1, mat[j][i]+costo));
    }
  //5. DL è uguale al valore della cella della matrice d di coordinate (m,n); stampare DL e terminare.

  printf("DL=%d\n", mat[m][n]);


  return 0;
}

