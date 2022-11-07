
int *mosse(const char *s, const int r, const int c)
{
  int *mosse=NULL; // conterra' le possibili coordinate di dove si puo' spostare il pezzo
  int nmosse=0; // man mano trovo i possibili spostamenti tengo traccia di quanti ne ho trovati
  int ir,ic;   // contatori di appoggio per calcolo coordinate

  switch(s[r*SIZE+c]) // ogni pezzo si sposta in modo differente
  {
    case ' ':
      break;
    case 'p':
      if(r==0 && s[(r-1)*SIZE+c]!=' ') 
	break;
      ++nmosse;
      mosse=realloc(mosse, nmosse*2*sizeof(int));
      mosse[nmosse*2-2]=r-1;
      mosse[nmosse*2-1]=c;
      if(r==6 && s[4*SIZE+c]!=' ')
      {
	++nmosse;
        mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=4;
	mosse[nmosse*2-1]=c;
      }
      break;
    case 'P':
      if(r==7 && s[(r+1)*SIZE+c]!=' ') 
	break;
      ++nmosse;
      mosse=realloc(mosse, nmosse*2*sizeof(int));
      mosse[nmosse*2-2]=r+1;
      mosse[nmosse*2-1]=c;
      if(r==1 && s[3*SIZE+c]!=' ')
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=3;
	mosse[nmosse*2-1]=c;
      }
      break;
    case 'b':
    case 'B': // si sposta solo in diagonale
      for(ir=r+1, ic=c+1; ir<8 && ic<8 && s[ir*SIZE+ic] == ' ' ;ir++, ic++)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=ir;
	mosse[nmosse*2-1]=ic;
      }  
      for(ir=r-1, ic=c-1; ir>=0 && ic>=0 && s[ir*SIZE+ic] == ' ' ;ir--, ic--)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=ir;
	mosse[nmosse*2-1]=ic;
      }
      for(ir=r-1, ic=c+1; ir>=0 && ic<8 && s[ir*SIZE+ic] == ' ' ;ir--, ic++)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=ir;
	mosse[nmosse*2-1]=ic;
      }

      for(ir=r+1, ic=c-1; ir<8 && ic>=0 && s[ir*SIZE+ic] == ' ' ;ir++, ic--)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=ir;
	mosse[nmosse*2-1]=ic;
      }
      break;
    case 'r':
    case 'R':
      for(ir=r+1; ir<8 && s[ir*SIZE+c] == ' ' ;ir++)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=ir;
	mosse[nmosse*2-1]=c;
      }

      for(ir=r-1; ir>=0 && s[ir*SIZE+c] == ' ' ;ir--)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=ir;
	mosse[nmosse*2-1]=c;
      }

      for(ic=c+1; ic<8 && s[r*SIZE+ic] == ' ' ;ic++)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=r;
	mosse[nmosse*2-1]=ic;
      }
      for(ic=c-1; ic>=0 && s[r*SIZE+ic] == ' ' ;ic--)
      {
	++nmosse;
	mosse=realloc(mosse, nmosse*2*sizeof(int));
	mosse[nmosse*2-2]=r;
	mosse[nmosse*2-1]=ic;
      }
      break;
    case 'n':
    case 'N':
      for(ic=-2; ic<=2; ic = ic +4)
	for(ir=-1; ir<=1; ir = ir +2)
	  if((c+ic)>=0 && (c+ic)<8 && (r+ir)>=0 && (r+ir)<8 && s[(r+ir)*SIZE + (c+ic)] == ' ')
	  {
	    ++nmosse;
	    mosse=realloc(mosse, nmosse*2*sizeof(int));
	    mosse[nmosse*2-2]=r+ir;
	    mosse[nmosse*2-1]=c+ic;
	  }
      for(ir=-2; ir<=2; ir = ir +4)
	for(ic=-1; ic<=1; ic = ic +2)
	  if((c+ic)>=0 && (c+ic)<8 && (r+ir)>=0 && (r+ir)<8 && s[(r+ir)*SIZE + (c+ic)] == ' ')
	  {
	    ++nmosse;
	    mosse=realloc(mosse, nmosse*2*sizeof(int));
	    mosse[nmosse*2-2]=r+ir;
	    mosse[nmosse*2-1]=c+ic;
	  }
      break;
    case 'k':
    case 'K':
      for(ic=-1; ic<=1; ++ic)
	for(ir=-1; ir<=1; ++ir)
	{
	  if((c+ic)>=0 && (c+ic)<8 && (r+ir)>=0 && (r+ir)<8 && s[(r+ir)*SIZE + (c+ic)] == ' ')
	  {
	    ++nmosse;
	    mosse=realloc(mosse, nmosse*2*sizeof(int));
	    mosse[nmosse*2-2]=r+ir;
	    mosse[nmosse*2-1]=c+ic;
	  }
	}
      break;
    default:
      break;
  }

  // se devo restituire qualcosa di non vuoto lo "termino" con un -1
  // in questo modo chi riceve il dato puo' capire dove finisce
  if(mosse)
  {
    mosse=realloc(mosse, nmosse*2*sizeof(int)+1);
    mosse[nmosse*2] = -1;
  }

  return mosse;
}

