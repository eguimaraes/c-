int fits_open_file( fitsfile **fptr, char *filename, int mode, int *status)
int fits_open_data( fitsfile **fptr, char *filename, int mode, int *status)
int fits_open_table(fitsfile **fptr, char *filename, int mode, int *status)
int fits_open_image(fitsfile **fptr, char *filename, int mode, int *status)

int fits_create_file(fitsfile **fptr, char *filename, int *status)
int fits_close_file(fitsfile *fptr, int *status)
