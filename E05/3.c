#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*

3. legga da tastiera due stringhe qualsiasi di massimo 10 caratteri e:
 - ne stampi la lunghezza (strlen())
 - le stampi in ordine "alfabetico" (strcmp())
 - le concateni e le stampi dapprima usando un array statico come destinazione e successivamente un array allocato dinamicamente (strcat())
 - verifichi se la seconda stringa e' contenuta nella prima e, in caso affermativo, in che posizione (strstr())
 - chieda un carattere e stampi quante volte quel carattere è contenuto nella prima stringa (strchr())
 - usi il carattere precedente a mo' di delimitatore per suddividere la prima stringa in sottostringhe e le si stampino (strtok())

 */

int main(int argc, char **argv){

  char a[11], b[11];

  // LETTURA
  printf("Inserire la  prima   stringa (max 10 caratteri): ");
  scanf(" %[^\n]", a);
  printf("Inserire la  seconda stringa (max 10 caratteri): ");
  scanf(" %[^\n]", b);

  // STAMPA LUNGHEZZA
  printf("La stringa [%s] e' lunga %ld caratteri\n", a, strlen(a));
  printf("La stringa [%s] e' lunga %ld caratteri\n", b, strlen(b));

  // STAMPA IN ORDINE
  if ( strcmp(a, b) <= 0 )
    printf("%s %s\n", a, b);
  else
    printf("%s %s\n", b, a);

  // CONCATENAZIONE STATICA
  char c[21];
  strcpy(c, a);
  strcat(c, b);
  printf("Il risultato della concatenazione e' %s\n", c);

  
  // CONCATENAZIONE DINAMICA 1
  char cvla[strlen(a) + strlen(b) + 1];
  strcpy(cvla, a);
  strcat(cvla, b);
  printf("Il risultato della concatenazione e' %s\n", cvla);

  // CONCATENAZIONE DINAMICA 2
  char *pc = malloc(strlen(a) + strlen(b) + 1);
  strcpy(pc, a);
  strcat(pc, b);
  printf("Il risultato della concatenazione e' %s\n", pc);
  free(pc);

  // RICERCA SOTTOSTRINGA
  if( strstr(a, b) != NULL )
  {
    printf("La stringa [%s] e' sottostringa di [%s] e si trova alla posizione %ld\n", b, a, strstr(a, b) - a);
  }
  else
  {
    printf("La stringa [%s] non e' sottostringa di [%s]\n", b, a);
  }

  // RICERCA CARATTERE
  char ch;
  int occorrenze = 0;

  printf("Inserisci un carattere: ");
  scanf(" %c", &ch);

  char *pa = a;
  while ( strchr(pa, ch) != NULL )
  {
    ++occorrenze;
    pa = strchr(pa, ch) + 1;
  } 
  printf("Nella stringa [%s] ho trovato %d occorrenze del carattere [%c]\n", a, occorrenze, ch);

  // SPEZZETTAMENTO STRINGA

  char delimitatori[2];
  delimitatori[0] = ch;
  delimitatori[1] = '\0';
  int contatore = 1;

  pa = strtok(a, delimitatori);
  while(pa != NULL)
  {
    printf("#%d: [%s]\n", contatore, pa);
    ++contatore;
    pa = strtok(NULL, delimitatori);
  }


  return 0;
}

