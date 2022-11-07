#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

  if(argc<2)
  {
    fprintf(stderr, "errore, devi fornire nome file di input\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp=fopen(argv[1], "r");
  if(!fp)
  {
    perror("errore in apertura file");
    exit(EXIT_FAILURE);
  }



  int c, oldc=0;
  int crotonde=0, cquadre=0, cgraffe=0;
  int ignoraparentesi = 0;
  while( (c=fgetc(fp)) != EOF )
  {
    switch(c)
    {
      case '(':
	if(!ignoraparentesi) crotonde++;
	break;
      case '[':
	if(!ignoraparentesi) cquadre++;
	break;
      case '{':
	if(!ignoraparentesi) cgraffe++;
	break;
      case ')':
	if(!ignoraparentesi) crotonde--;
	break;
      case ']':
	if(!ignoraparentesi) cquadre--;
	break;
      case '}':
	if(!ignoraparentesi) cgraffe--;
	break;
      case '"': //"
      case '\'': //'
	if(oldc!='\\') //'
	  ignoraparentesi = ( ignoraparentesi?0:1);
	break;
      default:
	break;
    }
    //printf("Ho letto %c ignoraparentesi=%d crotonde=%d\n", c, ignoraparentesi, crotonde);

    if(crotonde<0 || cgraffe<0 || cquadre < 0)
    {
      printf("Ho chiuso troppe parentesi \"(((\n");
      exit(EXIT_SUCCESS);
    }
    oldc=c;
  }

  if(crotonde || cgraffe || cquadre )
    printf("Ho aperto troppe parentesi crotonde=%d cquadre=%d cgraffe=%d \n", crotonde, cquadre,
	cgraffe);
  else
    printf("Le parentesi vanno bene\n");




  return 0;
}

