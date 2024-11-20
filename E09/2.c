// 2. scrivere una funzione del tipo max(a,b) che restituisce il valore
// massimo tra a e b Implementare successivamente una seconda funzione
// che, sfruttando la precedente, restituisce il massimo tra 4 valori

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double max(double a, double b)
{
  // PRIMO MODO
  if(a > b)
    return a;
  else
    return b;

  // SECONDO APPROCCIO (l'else di fatto non serve)
  if(a > b)
    return a;
  return b;

  // TERZO APPROCCIO (if in linea)
  return (a > b)? a : b;


}

double  max4(double a, double b, double c, double d)
{
  return max(max(a, b), max(c, d));
}

int main(int argc, char **argv){

  srand(time(NULL));

  // genero 4 numeri a virgola mobile a caso
  double x[] = {rand()/3.14, rand()/3.14, rand()/3.14, rand()/3.14};

  printf("Il massimo tra i seguenti numeri: %g, %g, %g, %g e' %g\n", x[0], x[1], x[2], x[3], max4(x[0], x[1], x[2], x[3]) );

  return 0;
}

