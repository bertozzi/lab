#include<stdio.h>
#include<stdlib.h>

char menu(void);
int *genera(int *);
int *load(int *);
void stampa(int *, int);
void salva(int *, int);

int main(int argc, char **argv){

  int n;
  int *quadrato = NULL;

  while(1)
  {
    char c = menu();
    switch(c)
    {
      case 'l':
      case 'L':
	if(quadrato)
	  free(quadrato);
	quadrato = load(&n);
	break;
      case 's':
      case 'S':
	salva(quadrato, n);
	break;
      case 'p':
      case 'P':
	stampa(quadrato, n);
	break;
      case 'g':
      case 'G':
	if(quadrato)
	  free(quadrato);
	quadrato = genera(&n);
	printf("DEBUG: ho generato un quadrato magico di %dx%d\n", n, n);
	break;
      case 'x':
      case 'X':
	if(quadrato)
	  free(quadrato);
	printf("Ciao ciao\n");
	exit(EXIT_SUCCESS);
      default:
	printf("Scelta non valida\n");
    }
  }


  return 0;
}

int *load(int *size)
{
  char nome[1000];
  printf("Inserisci il nome di un file da caricare: ");
  scanf(" %s", nome);

  // apro il file in lettura binaria (il b!)
  FILE *infile = fopen(nome, "rb");
  if(!infile)
  {
    perror("");
    exit(EXIT_FAILURE);
  }

  // e' il duale della salva() solo che uso fread()
  fread(size, sizeof(int), 1, infile);
  printf("DEBUG: il quadrato ha dimensiont %dx%d\n", *size, *size);

  // alloco buffer in cui leggere il resto del contenuto del file (il quadrato vero e proprio)
  int *numeri = malloc((*size)*(*size)*sizeof(int));
  
  // lo leggo
  fread(numeri, sizeof(int), (*size)*(*size), infile);
  
  // chiudo il file
  fclose(infile);

  // fase di verifica, calcolo somme colonne, righe e diagonali

  int somma, riferimento;

  // prima calcolo riferimento (somma prima riga)
  riferimento = 0;
  for(int c = 0; c < *size; ++c)
    riferimento += numeri[c]; // sarebbe numeri[0*(*size) + c] in base a formula vista
  
  // faccio stessa operazione per tutte le altre righe e confronto con riferimento
  for(int r = 1; r < *size; ++r)
  {
    somma = 0;
    for(int c = 0; c < *size; ++c)
      somma += numeri[r * (*size) + c];
    if(somma != riferimento)
    {
      printf("Il quadrato magico caricato da file non e' tanto magico...\n");
      exit(EXIT_FAILURE);
    }
  }

  // stessa cosa per le colonne (come il precedente invertendo i cicli e senza saltare nessuna colonna)
  for(int c = 0; c < *size; ++c)
  {
    somma = 0;
    for(int r = 0; r < *size; ++r)
      somma += numeri[r * (*size) + c];
    if(somma != riferimento)
    {
      printf("Il quadrato magico caricato da file non e' tanto magico...\n");
      exit(EXIT_FAILURE);
    }
  }

  // prima diagonale
  somma = 0;
  for(int d = 0; d < *size; ++d)
    somma += numeri[d * (*size) + d ];
  if(somma != riferimento)
  {
    printf("Il quadrato magico caricato da file non e' tanto magico...\n");
    exit(EXIT_FAILURE);
  }
  
  // seconda diagonale
  somma = 0;
  for(int d = 0; d < *size; ++d)
    somma += numeri[d * (*size) + (*size -1 - d) ];
  if(somma != riferimento)
  {
    printf("Il quadrato magico caricato da file non e' tanto magico...\n");
    exit(EXIT_FAILURE);
  }


  // restituisco indirizzo buffer allocato
  return numeri;
}

void salva(int *q, int size)
{
  if(!q)
  {
    printf("non posso salvare un quadrato vuoto\n");
    return;
  }

  char nome[1000];
  printf("Inserisci il nome di un file su cui salvare: ");
  scanf(" %s", nome);

  // apro il file in scrittura binaria (il b!)
  FILE *output = fopen(nome, "wb");
  if(!output)
  {
    perror("");
    exit(EXIT_FAILURE);
  }


  // devo scrivere in testa la dimensione del quadrato magico come int (in pratica il contenuto della variabile size)
  fwrite(&size, sizeof(int), 1, output);
  // scrivo contenuto quadrato magico
  fwrite(q, sizeof(int), size*size, output);

  fclose(output);
}

void stampa(int *q, int size)
{
  if(!q) // mi e' stato passato puntatore non valido 
  {
    printf("Mi rifiuto di stampare un quadrato magico vuoto!\n");
    return;
  }

  // ciclo di stampa riga e colonna
  for(int r = 0; r < size; ++r)
  {
    for(int c = 0; c < size; ++c)
    {
      printf("%3d ", q[r*size + c]);  // uso 3 caratteri per incolonnare
    }
    printf("\n"); //  al termine di ogni riga vado a capo
  }
}

char menu(void)
{
  printf("Fai la tua scelta\n G – generare un nuovo quadrato magico\n L – caricarlo da file\n S – salvarlo su file\n P – stampa\n X – esci\n\n : ");
  char scelta;
  scanf(" %c", &scelta);

  return scelta;
}

int *genera(int *size)
{
  do
  {
    printf("Inserisci la dimensione del quadrato magico da generare: ");
    scanf("%d", size);
  }
  while( !((*size) % 2) );

  int n = *size;   // per semplicita' di scrittura codice

  int *q = calloc( n*n, sizeof(int));

  int r, c; // coordinate nella matrice dove man mano deposito i valori secondo l'algoritmo descritto
  int r_precedente, c_precedente; // per tener traccia di dove ero in precedenza

  r = 0;   // prima riga
  c = n/2;  // meta' prima riga
  
  int val = 1; // numeri che man mano "depositero'" nella matrice
  q[r*n + c] = val;   // deposito il primo "1"
  
  while(val != (n*n)) // devo scrivere n*n valori
  {
    ++val; // incremento numero da scrivere in matrice (1 lo avevo gia' scritto)
    r_precedente = r; // prima di spostarmi sulla matrice tengo traccia da dove partivo
    c_precedente = c;
	   
    --r; // mi sposto in alto
    if(r < 0)  // se sono uscito in alto rientro dal basso
      r = n - 1; // gli indici di riga vanno da 0 a n-1

    --c; // ripeto per l'indice di riga
    if(c < 0)
      c = n - 1;
  
    // verifico se in destinazione posso scrivere (ovvero c'e' uno 0) o se ho gia' scritto qualcosa
    if(q[r*n + c])
    {
      // mi sposto banalmente in basso rispetto posizione precedente
      c = c_precedente;
      r = r_precedente + 1;
      if(r > (n-1)) // anche qui devo controllare di non aver "sforato" dai bordi
	r = 0;
    }

    q[r*n + c] = val;
  }

  return q;
}
