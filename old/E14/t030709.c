#include<stdio.h>
#include<stdlib.h>

void stampatris(const int tabella[3][3])
{
  int i, j;
  for(i=0; i<3; ++i)
  {
    for(j=0; j<3; ++j)
      switch(tabella[i][j])
      {
	case 0:
	  printf("X ");
	  break;
	case 1:
	  printf("O ");
	  break;
	default:
	  printf("  ");
	  break;
      }
    printf("\n");
  }
}

int controlladiagonale(const int tabella[3][3], const int diagonale)
{
  if(diagonale == 0 && tabella[1][1] == tabella[0][0] && tabella[1][1] == tabella[2][2])
    return tabella[1][1];

  if(diagonale == 1 && tabella[1][1] == tabella[0][2] && tabella[1][1] == tabella[2][0])
    return tabella[1][1];

  return -1;
}

int controllacolonna(const int tabella[3][3], const int colonna)
{
  // controllo se nella colonna in questione tutti e 3 gli elementi sono uguali
  if(tabella[0][colonna] == tabella[1][colonna] && tabella[1][colonna] == tabella[2][colonna])
    return tabella[0][colonna];
  return -1;
}

int controllariga(const int tabella[3][3], const int riga)
{
  // controllo se nella riga in questione tutti e 3 gli elementi sono uguali
  if(tabella[riga][0] == tabella[riga][1] && tabella[riga][1] == tabella[riga][2])
    return tabella[riga][0];
  return -1;
}

int main(int argc, char **argv){

  // LEGGI FILE TRIS.TXT E MEMORIZZA IN OPPORTUNA STRUTTURA
  // alloca/definisci matrice 3x3
  int tabella[3][3];
  int i,j;
  for(i=0; i<3; ++i)
    for(j=0; j<3; ++j)
      tabella[i][j]=-1;

  // inizializza giocatore come X
  int giocatore = 0; // 0 -> X 1 -> O

  // leggi due interi dal file
  FILE *fp;
  fp=fopen("tris.txt", "r"); 
  if(!fp)
  {
    perror("errore");
    exit(EXIT_FAILURE);
  }

  while(fscanf(fp, "%d %d", &i, &j) == 2)
  {
    // in matrice segna giocatore alle coordinate lette
    tabella[i][j]=giocatore;
    // commuta giocatore (ovvero se X diventa O e viceversa)
    giocatore = (giocatore?0:1);
    // ci sono ancora righe? si' ripeti
  }
  fclose(fp);

  stampatris(tabella); // solo a fini debug

  // CONTROLLA VITTORIA
  // controlla se nelle righe ci sono 3 elementi tutti uguali
  for(i=0; i<3; ++i)
  {
    int vincitore=controllariga(tabella, i);
    if(vincitore != -1)
    {
      printf("Partita vinta da %c\n", vincitore ? 'O':'X');
      return 0;
    }
  }
  // controlla se nelle colonne ci sono 3 elementi tutti uguali

  for(i=0; i<3; ++i)
  {
    int vincitore=controllacolonna(tabella, i);
    if(vincitore != -1)
    {
      printf("Partita vinta da %c\n", vincitore ? 'O':'X');
      return 0;
    }
  }  
  // controlla se nelle diagonali ci sono 3 elementi tutti uguali
  int vincitore=controlladiagonale(tabella, 0);
  if(vincitore != -1)
    {
      printf("Partita vinta da %c\n", vincitore ? 'O':'X');
      return 0;
    }
  vincitore=controlladiagonale(tabella, 1);
  if(vincitore != -1)
    {
      printf("Partita vinta da %c\n", vincitore ? 'O':'X');
      return 0;
    }


  printf("Partita patta\n");
  return 0;
}

