#include "buildings.h"

void read_buildings_file(char* fname) {
    FILE* bfile = fopen(fname, "r");
    BUILDING build;
    while (fread(&build, sizeof(BUILDING), 1, bfile))

        printf("id = %d name = %s \n", build.id, build.name);
}
