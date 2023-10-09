#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  float t_far, t_cel;

  printf("Inserisci una temperatura in gradi Calsius (C): ");
  scanf("%f", &t_cel);
  
  printf("La corrispondente temperatura in gradi Farenheit (F) e': %.2f\n", 32 + 9/5*t_cel);
  // ancora una volta sbaglia... 
  // Riuscite a modificare questo codice di modo che il calcolo sia fatto in maniera corretta?

  return 0;
}

