#include <string.h>
#include <stdio.h>
#include <string.h>
#include <fitsio.h>


void isPartOf(char *, char *);

    int main(int argc, char *argv[])
    {
      fitsfile *fptr;         
        char card[FLEN_CARD]; 
        char *compararkey=argv[2];
        char *nr;
        

      int status = 0,  nkeys, ii; 

      fits_open_file(&fptr, argv[1], READONLY, &status);
        fits_get_hdrspace(fptr, &nkeys, NULL, &status);

        
        for (ii = 1; ii <= nkeys; ii++)  { 
          fits_read_record(fptr, ii, card, &status); 
          
          if(strstr(card,compararkey)!=NULL){
                   nr= strtok (card,"=");
                   nr= strtok (NULL,"=");


          printf("%s\n", nr);

          }
         
        }
        
        fits_close_file(fptr, &status);

        if (status)          /* print any error messages */
          fits_report_error(stderr, status);
        return(status);
    }
