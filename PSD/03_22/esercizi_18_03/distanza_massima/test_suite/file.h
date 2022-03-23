#include <stdio.h>
#include "punto.h"

FILE *apri_file(char *file_name, char *mode);
punto *finput_punto(char *file_name, int *npunti);
void foutput_punto(char *file_name, float m);
float fread_oracle(char *oracle_fname);
