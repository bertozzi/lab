#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
4. implementi la seguente funzione di modo da correggere l'errore di "lingering pointer" presente:
   char *read_line(void){
    char tmp[2000];
    scanf("%[^\n]", tmp);
    return tmp;
   }
*/

char *read_line(void){
  char tmp[2000];
  scanf("%[^\n]", tmp);

  char *p = malloc((strlen(tmp) + 1)*sizeof(char));
  strcpy(p, tmp);
  return p;
}


int main(int argc, char **argv){

  char *pa = read_line();
  printf("Hai inserito [%s]\n", pa);

  return 0;
}

