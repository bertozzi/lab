/*
leggere da tastiera un numero intero non negativo tra 0 e 15 e
stampare la cifra esadecimale corrispondente
(calcolandola, non usando gli specificatori di formato %x o %X)
 Richiede l'uso del costrutto if()
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  printf("Inserisci un numero decimale tra 0 e 15: "); // ci fidiamo dell'utente...
  int x;
  scanf("%d", &x);

  if( x < 10)
  {
    printf("La cifra esadecimale corrispondente a %d vale %d\n", x, x);
  }
  else
  {
    // mi calcolo il simbolo da stampare 
    char hex_digit = (x - 10) + 'A'; // f(x) tale che:  10 -> 'A', 11 -> 'B', ...
    printf("La cifra esadecimale corrispondente a %d vale %c\n", x, hex_digit);
    // a rigore una variabile non era  necessaria potevo fare tutto nella printf()
  }

  return 0;
}

