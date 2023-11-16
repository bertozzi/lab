/*
5. implementi la seguente funzione di modo da correggere l'errore di "lingering pointer" presente:
   char *read_line(void){
    char tmp[2000];
    scanf("%[^\n]", tmp);
    return tmp;
   }
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* funzione che non "funziona"
char *read_line(void)
{
  char tmp[2000];
  scanf("%[^\n]", tmp);
  return tmp;  // restituisco un indirizzo valido ma tmp[] viene distrutta al termine della funzione
}

5.c:18:10: warning: function returns address of local variable [-Wreturn-local-addr]
   18 |   return tmp;
      |          ^~~
*/

/* banale trasposizione della precedente usando allocazione dinamica di array comunque largo
char *read_line(void)
{
  char *tmp = malloc(2000*sizeof(char));
  scanf("%[^\n]", tmp);
  return tmp;  
}
*/

/* alloco dinamicamente con malloc() ma poi riduco dimensione buffer con realloc() una volta che so quanti caratteri ho letto
char *read_line(void)
{
  char *tmp = malloc(2000*sizeof(char));
  scanf("%[^\n]", tmp);
  tmp = realloc(tmp, (strlen(tmp)+1)*sizeof(char)); // +1 in quanto ci vuole lo spazio per il carattere nullo di terminaziono
  return tmp;  
}
*/

char *read_line(void)
{
  char tmp[2000];
  scanf("%[^\n]", tmp);
  char *s = malloc((strlen(tmp) + 1) * sizeof(char));
  strcpy(s, tmp);
  return s;  
}

int main(int argc, char **argv){

  printf("Inserisci una stringa: ");
  char *s = read_line();
  printf("Bravo, hai inserito %s\n", s);

  return 0;
}

