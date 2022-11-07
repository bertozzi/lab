#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct elenco {
  double numeri[1000]; // coda dei numeri
  size_t n; // riempimento della coda
};

void push(struct elenco *lista, const double x); // inserim ento numero
double pop(struct elenco *lista);                // prelievo numero

int main(int argc, char **argv){

  // leggere un file per "parola" 
  FILE *fp=fopen("polacca.txt", "r");
  if(!fp)
  {
    perror("errore");
    exit(EXIT_FAILURE);
  }

  struct elenco lista_numeri;
  lista_numeri.n=0;

  char str[1000];

  while( fscanf(fp, "%s", str) == 1 )
  {

    // capire se e' un numero o un operatore
    if(strlen(str)==1 && !isdigit(str[0]) )
    {
    // se operatore
      // togliere due numeri da lista, eseguire relativa operazione e rimettere  in lista risultato
      // printf("Ho letto operatore %s\n", str);
      double a=pop(&lista_numeri);
      double b=pop(&lista_numeri);
      // if(str[0]  == '+` )...
      switch(str[0])
      {
	case '+':
	  push(&lista_numeri, a+b);
	  break;
	case '*':
	  push(&lista_numeri, a*b);
	  break;
	case '-':
	  push(&lista_numeri, b-a);
	  break;
	case '/':
	  push(&lista_numeri, b/a);
	  break;
	default:
	  fprintf(stderr, "Errore: operando sconosciuto '%c'\n", str[0]);
	  exit(EXIT_FAILURE);
	  break;
      }
    }
    else
    {
    // se numero
      // mettere in opportuna lista
      push(&lista_numeri, atof(str) );
    }
  }

  // alla fine del file: prelevare ultimo numero in lista e stamparlo
  printf("Il risultato e': %f\n", pop(&lista_numeri));

  return 0;
}

void push(struct elenco *lista, const double x)
{
  lista->numeri[lista->n]=x;
  ++lista->n; 
  //printf("Ho inserito in lista %f e adesso ho %lu numeri\n", x, lista->n);
}

double pop(struct elenco *lista)
{
  if(!lista->n)
  {
    fprintf(stderr, "errore in pop(): lista vuota\n");
    exit(EXIT_FAILURE);
  }
  --lista->n;

  //printf("Sto restituendo %f e adesso ho %lu numeri\n", lista->numeri[lista->n], lista->n);
  return  lista->numeri[lista->n];
}

