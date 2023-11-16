// 1. legga da tastiera una stringa che non contiene caratteri di spaziatura e la stampi

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
  char s[2000];

  printf("Inserisci una stringa: ");
  scanf("%s", s);

  printf("Hai inserito '%s'\n", s);


  return 0;
}

