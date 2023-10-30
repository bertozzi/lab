//  8. redigere un programma che prende in ingresso una sequenza di caratteri e calcola quante vocali contiene.


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char **argv){

  char c;
  int num_vocali = 0;

  do
  {
    scanf("%c", &c);

    c = toupper(c);
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
      num_vocali++;
  }
  while(c != '\n');

  printf("Nella frase inserita ci sono %d vocali\n", num_vocali);

  return 0;
}

