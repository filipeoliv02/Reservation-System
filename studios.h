#ifndef AED1_LP1_STUDIOS_H
#define AED1_LP1_STUDIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief tipo de dados que define os estúdios
 * @details contém a tipologia do estúdio (T2, T3...)
 * aponta para o edifício a que pertence
 * e contém a morada
 */
typedef struct studio {
    int id;
    int number;
    int building;
    char *config;
    int area;
} STUDIO;

STUDIO *read_studios_file(char *fname);

void write_studios_file(STUDIO *studio_array, char *fname);


#endif
