#ifndef AED1_LP1_BUILDINGS_H
#define AED1_LP1_BUILDINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct building {
    int id;
    char *name;
    double latitude;
    double longitude;
    char *address;
    double priceperday;
    struct building *next;
    struct studio_array **studios;

} BUILDING;

typedef struct building_list {
    BUILDING *pbuildings;
} BUILDING_LIST;

void read_buildings_file(char *fname);
void write_buildings_file(char *fname);
void read_buildings_to_List(char *fname);
void show_build_list(BUILDING *L);

#endif
