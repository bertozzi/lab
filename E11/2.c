/*
2. Linea di comando: si individui se nella linea di comando e'
   presente "-h", si rammenta che è possibile inserire la linea di
   comando da Project -> Set program's arguments
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){

  printf("DEBUG: sulla linea di comando ci sono %d parole\n", argc);

  int trovato = 0;  // flag di appoggio che mi permette di segnare se il -h c'era o meno
  for(int i = 0; i < argc; ++i)
  {
    printf("DEBUG: sto esaminando la parola #%d e vale %s\n", i, argv[i]);

    //if(strcmp(argv[i], "-h") == 0)
    if(!strcmp(argv[i], "-h"))
    {
      trovato = 1;
      printf("-h e' presente nella linea di comando nella posizione #%d\n", i);
      break; // se trovo il -h esco in quanto sono gia' soddisfatto...
    }
  }

  if(!trovato)
    printf("-h non e' presente sulla linea di comando\n");
    

  return 0;
}

