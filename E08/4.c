/*
4. legga da tastiera due stringhe qualsiasi di massimo 10 caratteri e:
 - ne stampi la lunghezza (strlen())
 - le stampi in ordine "alfabetico" (strcmp())
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){
  char s1[11], s2[11];

  printf("Inserisci una stringa: ");
  scanf("%[^\n]", s1);
  printf("Inserisci una stringa: ");
  scanf(" %[^\n]", s2); // attenzione, ci vuole uno spazio per fare in modo che la scanf() ignori l'"a capo" del precedente inserimento rimasto nel buffer di tastiera
  
  printf("Hai inserito le stringhe '%s' e '%s' che sono composte dal %ld e %ld caratteri rispettivamente\n", 
      s1,
      s2,
      strlen(s1),
      strlen(s2)
      );

  if(strcmp(s1, s2) > 0)
  {
    printf("In ordine ASCII sono %s e %s\n", s2, s1);
  }
  else
  {
    printf("In ordine ASCII sono %s e %s\n", s1, s2);
  }


  return 0;
}

