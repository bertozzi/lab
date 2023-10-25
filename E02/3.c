// 3. sviluppare un programma che legga un char da input, se e' una lettera minuscola lo trasformi in maiuscola, stampi il carattere


#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  char x;
  printf("Inserisci un carattere: ");
  scanf("%c", &x);

  if(x >= 'a' && x <= 'z')
    x = (x - 'a') + 'A';

  printf("%c\n", x);

  return 0;
}

