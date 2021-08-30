#include <string.h>
#include <stdio.h>
#include <string.h>
#include <fitsio.h>



    int main(int argc, char *argv[])
    {
      fitsfile *fptr;         
        char card[FLEN_CARD]; 
        char *compararkey=argv[2];
        char *nr;
        

      int status = 0,  nkeys, ii; 

      fits_open_file(&fptr, argv[1], READONLY, &status); // open fits file
        fits_get_hdrspace(fptr, &nkeys, NULL, &status);// read header
        
        for (ii = 1; ii <= nkeys; ii++)  { //search for a key
          fits_read_record(fptr, ii, card, &status); 
          
          if(strstr(card,compararkey)!=NULL){
                   nr= strtok (card,"=");//tokenizer for get only number part of key
                   nr= strtok (NULL,"=");


          printf("%f\n", atof(nr)); //print number

          }
         
        }
        
        fits_close_file(fptr, &status);

        if (status)          /* print any error messages */
          fits_report_error(stderr, status);
        return(status);
    }
