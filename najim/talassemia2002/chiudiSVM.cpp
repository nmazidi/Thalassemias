/****************************************************************************
*                                                                           *
*                  CHIUDI SVM da  output SVM da distanze nella              *
*                          forma 0/1                                        *
*						  edit by G.Masala 20/04/2002                             *
*                                                                           *
****************************************************************************/
/* Nella riga di comando inserire:
	-> Nome del file di input
/***********************      Inizio Codice        *************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


FILE *apri(char*,char*);
void leggi_esempio (FILE *in,int* id,int* classe,int* predetta);
char dailabel(int i);
void calcolo(char *filename1);

int main(int argc, char **argv)
{
	char *filename1;

   filename1=*++argv;


	printf("\nAvvio il calcolo\n");

   calcolo(filename1);


	return 0;
}


FILE *apri(char* nomefile,char* modo)
{
	FILE *fp;
	fp=fopen(nomefile,modo);
	if(fp==NULL)
	{
		printf("\nErrore di lettura nel file: %s\n",nomefile);
		exit(0);
	}

	return fp;
}



 /*  	case 0 : return 'N';
		case 1 : return 'M';  */


void calcolo(char *filename1)
  {
   FILE *in,*out;
   int respon;
   float feature;

   in=apri(filename1,"r");
   out=apri("cambiami.txt","w");

   while(!feof(in))
	{
    fscanf(in,"%f",&feature);

    if (!feof(in))
    {
    if (feature>0)  fprintf(out,"%d \n",0);
    			else    fprintf(out,"%d \n",1);
    }
   }
   fclose(out);
   fclose(in);
}


