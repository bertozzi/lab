#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isvalidrecipientname(char c)
{

  char validchars[]="!#$%&'*+-/=?^_`{|}~";
  for(int i=0; i<strlen(validchars); ++i)
    if(validchars[i] == c)
      return 1;

  return 0;
}

/*
3. il domain name è formato da almeno 2 "parole" separate da '.' che a loro volta possono contenere solo:

   lettere [ a-zA-Z ]
   cifre   [ 0-9 ]
   il carattere '-' ma non in prima o ultima posizione
*/
int check_domain(char *d)
{
  char *punto = strchr(d, '.');
  if(!punto || punto == d || (punto - d) == (strlen(d) - 1) )
    return 0;

  for(int i=0; i<strlen(d); ++i)
  {
    if( !isalnum(d[i]) && d[i]!= '.' && !( d[i] == '-' && (i==0 || i==(strlen(d) -1) ))  )
    {
      return 0;
    }
	
  }
  return 1;
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
  char precchar=' ';
  for(int i=0; i<strlen(r); ++i)
  {
    if( !isalnum(r[i]) && !isvalidrecipientname(r[i]) && (r[i] == '.' && (i==0 ||  precchar == '.')) )
      return 0;
    precchar = r[i];
  }
  return 1;
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
      int domain_valido = check_domain(parola);
      *at='@';
      if(recipient_valido && domain_valido)
	printf("%s\n", parola);
    }
  }

  fclose(mail);


  return 0;
}

