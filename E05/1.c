#include<stdio.h>
#include<stdlib.h>

// 1. legga da tastiera una stringa che non contiene caratteri di spaziatura e la stampi


int main(int argc, char **argv){

  char stringa[1000];

  printf("Inserisci una parola: ");
  scanf("%s", stringa);

  printf("Hai inserito la parola %s\n", stringa);

  return 0;
}

