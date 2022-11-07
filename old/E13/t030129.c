#include<stdio.h>
#include<stdlib.h>

void stampapersone(unsigned int *elenco, const unsigned int quantita)
{
  int i;
  for(i=0; i<quantita ; ++i)
    printf("%u ", elenco[i]);
  printf("\n");

}

int main(int argc, char **argv){

  // leggere due numeri n e m
  unsigned int n, m;
  scanf("%u %u", &n, &m);

  // inizializzare elenco di n persone
  unsigned int *persone=malloc(n*sizeof(*persone));
  int i;
  for(i=0; i<n ; ++i)
    persone[i]=i+1;

  stampapersone(persone, n);

  unsigned int npersone=n; // mi contiene quante persone sono ancora in gara
  i=0; // lo uso per scandire array di pettorali
  do
  {
  // iterativamente contare m persone
    unsigned int conta=0; // lo incremento ogni volta che incontro un pettorale "valido"
    while(1)
    {
      if(persone[i]) // pettorale valido
	++conta;
      if(conta==m) break; // esco se arrivato ad elemento da eliminare

      // incremento indice per scadnire array e controllo se non sono arrivato alla fine
      ++i; 
      // se arrivato a fine array riparto da inizio
      if(i>=n) i=0;
    }
    // eliminare la m-eseima persona e stampare pettorale
    printf("Elimino il pettorale %u\n", persone[i] );
    persone[i] = 0; // annullo il pettorale di modo che non sia contato al prossimo ciclo
    --npersone;
    // ci sono ancora persone?
      // si' ripetere
      // no terminare
  }
  while(npersone);

  return 0;
}

