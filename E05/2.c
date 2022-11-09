#include<stdio.h>
#include<stdlib.h>

// 2. legga da tastiera una stringa che contiene caratteri di spaziatura e la stampi


int main(int argc, char **argv){

  char stringa[1000];

  printf("Inserisci una frase: ");
  scanf("%[^\n]", stringa);

  printf("Hai inserito la frase %s\n", stringa);

  return 0;
}

