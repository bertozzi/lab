#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isvalidrecipientname(char c)
{
}

/*
   lettere [ a-zA-Z ]
   cifre   [ 0-9 ]
   i caratteri stampabili [ !#$%&'*+-/=?^_`{|}~ ]
   il punto [ . ] salvo non sia il primo carattere o ripetuto due volte di seguito
*/
int check_recipient(char *r)
{
  if(strlen(r) > 64) return 0;
  for(int i=0; i<strlen(r); ++i)
  {
    if(!isalnum(r[i]) || !isvalidrecipientname(r[i]) || r[i] != '.')
      return 0;
  }
}

int main(int argc, char **argv){

  FILE *mail=fopen("mail.eml", "r");
  if(!mail)
  {
    perror("");
    exit(1);
  }

  char parola[1000];
  while( fscanf(mail, " %s", parola) == 1 )
  {
    char *at = strchr(parola, '@');

    if(at)
    {
      char *domain = at + 1;
      *at = '\0';
      int recipient_valido = check_recipient(parola);
      printf("%s   %s\n", parola, domain);
    }
  }

  fclose(mail);


  return 0;
}

