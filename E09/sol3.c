// SOLUZIONE CHE SI APPOGGIA AD UNA STRUCT
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct db 
{
  char *dati[1000];
  int index;
};

FILE *file_html(void);
char *leggi_prossimo_tag(FILE *);
int is_apertura(char *);
void push(char *, struct db*);
int is_last(char *, struct db);

int main(int argc, char **argv){

// chiedere all'utente il nome file e aprirlo

FILE *fp=file_html();

// leggere il primo tag
char *tag;

// struttura in cui memorizzare i miei tag 
struct db tags;
tags.index = 0;


while( (tag = leggi_prossimo_tag(fp)) != NULL)
{
  // printf("Ho trovato %s\n", tag); // DEBUG
  // e' un tag di apertura?
  if( is_apertura(tag))
  {
   // printf("Ho trovato il tag di apertura %s\n", tag); // DEBUG
    // si' lo memorizzo

    push(tag, &tags);
  }
  else
  {
   // printf("Ho trovato il tag di chiusura %s\n", tag); // DEBUG
    // no lo confronto con l'ultimo memorizzato
    // e' uguale?
    if(is_last(tag, tags))
    {
      // si' rimuovo l'ultimo tag memorizzato
      tags.index--;
      /// pop_last();
    }
    else
    {
      // no -> errore ed esco
      printf("ERRORE il tag %s non e' correttamente indentato\n", tag);
      exit(1);
    }
    // ripeto da lettura prossimo tag fino a che non sono a fine file
  }
}
// ci sono ancora tag di apertura memorizzati?
  /// if(!empty())
if(tags.index)
  {
    // si' errore
    printf("ERRORE: non tutti i tag sono stati chiusi\n");
    exit(1);
  }
  else
  {
    // no stampo OK
    printf("OK\n");
  }


  return 0;
}

FILE *file_html(void)
{
  printf("Inserisci il nome di un file da controllare: ");
  char nomefile[1000];
  scanf(" %s", nomefile);
  FILE *fp = fopen(nomefile, "r");
  if(!fp)
  {
    perror("");
    exit(1);
  }
  
  return fp;
}

char *leggi_prossimo_tag(FILE *x)
{
  int trovato = 0; // mi permette di tenere memoria se avevo gia' incontrato un tag o meno\

  char tag_tmp[1000]; // array temporaneo in cui memorizzo tag
  int tag_index = 0;  // indice per memorizzare lettere nell'array temporaneo


  //1. leggi un carattere
  int c;
  while( (c = fgetc(x)) != EOF )
  {
    //2. e' un < ?
    if(c == '<' )
    {
      // si' -> ho incontrato un tag, tienine nota
      trovato = 1;
    }

    // avevo gia' incontrato il <?
    if(trovato)
    {
      //  si' memorizza il carattere
      tag_tmp[tag_index] = c;
      tag_index++;
    }
    //3. e' un > ?

    if(c == '>') 
    {
      // si' -> chiudo il tag e lo restituisco
      tag_tmp[tag_index] = '\0';
      char *final_tag = malloc(strlen(tag_tmp) + 1);
      strcpy(final_tag, tag_tmp);
      return final_tag;
    }

    //4. ripeti da 1
  }

  return NULL;
}

int is_apertura(char *t)
{
  if(t[1] == '/')
    return 0;

  return 1;
}

void push(char *t, struct db *tags)
{

  tags->dati[tags->index] = t;
  tags->index++;

}

int is_last(char *t, struct db tags)
{
  int last_index = tags.index - 1; // ultimo tag inserito

  // controllo se la struttura e' o meno piena
  if(last_index < 0) 
    return 0;

  int confronto = strcmp(tags.dati[last_index] + 1, t + 2); // confronto tag e ultimo tag memorizzato a partire dalla parte che dovrebbero avere in comune.
  // ovvero salto il < in entrambi e anche lo / in quello di chiusura
  
  if(! confronto) return 1; // sono uguali
  return 0;
}
