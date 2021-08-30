#include <string.h>
#include <stdio.h>
#include <string.h>
#include <fitsio.h>


float getValue(const char* nameArq,const char* compararkey)
    {
      fitsfile *fptr;         
        char card[FLEN_CARD]; 
        //char *compararkey=argv[1];
        char *nr;
        

      int status = 0,  nkeys, ii; 

      fits_open_file(&fptr, nameArq, READONLY, &status); // open fits file
        fits_get_hdrspace(fptr, &nkeys, NULL, &status);// read header
        
        for (ii = 1; ii <= nkeys; ii++)  { //search for a key
          fits_read_record(fptr, ii, card, &status); 
          
          if(strstr(card,compararkey)!=NULL){
                   nr= strtok (card,"=");//tokenizer for get only number part of key
                   nr= strtok (NULL,"=");          

          }
         
        }
        
        fits_close_file(fptr, &status);
        return atof(nr);
     
    }


int main(int argc, char *argv[])
    { 
              
        int status = 0,  nkeys, ii;  /* MUST initialize status */
        float nr;

       const char *file="nomearquivo.fits[1]";
       const char *key="key...";
              
        

       nr=getValue(file,key);
       printf("%f\n",nr);
        
        
        
        
         if (status)          /* print any error messages */
          fits_report_error(stderr, status);
        return(status);
        
        
        }



    
