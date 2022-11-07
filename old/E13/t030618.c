#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  FILE *fp=fopen("percorso.txt", "r");
  if(!fp)
  {
    perror("errore");
    exit(EXIT_FAILURE);
  }

  int distanza, altitudine;
  int prec_distanza, prec_altitudine;
  int dislivello_disc=0, dislivello_sal=0;

  float max_pend_salita=0;
  float max_pend_discesa=0;
  int max_pend_sal_in, max_pend_sal_end, max_pend_sal_inalt, max_pend_sal_endalt;
  int max_pend_dis_in, max_pend_dis_end, max_pend_dis_inalt, max_pend_dis_endalt;

  fscanf(fp, "%d %d", &prec_distanza, &prec_altitudine);
  while( fscanf(fp, "%d %d", &distanza, &altitudine) == 2 )
  {
    // TODO
    if(altitudine>prec_altitudine) // sono andato in salita
    {
      dislivello_sal += (altitudine-prec_altitudine);
      float pend = (altitudine-prec_altitudine)/(float)(distanza-prec_distanza); // pendenza salita
      if(pend>max_pend_salita)
      {
	max_pend_salita=pend;
	max_pend_sal_in = prec_distanza;
	max_pend_sal_end = distanza;
	max_pend_sal_inalt = prec_altitudine;
	max_pend_sal_endalt = altitudine;
      }
    }
    else // sono andato in discesa
    {
      dislivello_disc += (prec_altitudine-altitudine);
      float pend = (prec_altitudine-altitudine)/(float)(distanza-prec_distanza); // pendenza salita
      if(pend>max_pend_discesa)
      {
	max_pend_discesa=pend;
	max_pend_dis_in = prec_distanza;
	max_pend_dis_end = distanza;
	max_pend_dis_inalt = prec_altitudine;
	max_pend_dis_endalt = altitudine;
      }
    }






    prec_distanza=distanza;
    prec_altitudine=altitudine;
  }

  printf("Totale dislivello in salita:  %d\n", dislivello_sal);
  printf("Totale dislivello in discesa: %d\n", dislivello_disc);
  printf("Pendenza massima  in salita  tra %d (%d) e %d (%d)\n",
      max_pend_sal_in, max_pend_sal_inalt, max_pend_sal_end, max_pend_sal_endalt);
  printf("Pendenza massima  in discesa tra %d (%d) e %d (%d)\n",
      max_pend_dis_in, max_pend_dis_inalt, max_pend_dis_end, max_pend_dis_endalt);

  return 0;
}

