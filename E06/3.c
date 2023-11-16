// 3. legga da tastiera una stringa che contiene caratteri di spaziatura e la stampi, ne stampi anche la lunghezza

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){
  char s[2000];

  printf("Inserisci una stringa: ");
  scanf("%[^\n]", s);

  printf("Hai inserito la stringa '%s' che e' formata da %ld caratteri\n", s, strlen(s));


  return 0;
}

