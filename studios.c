//
// Created by filipe on 12/29/20.
//

#include "studios.h"

void read_studios_file(char *fname) {
    FILE *bfile = fopen(fname, "r");
    if (bfile == NULL) {
        printf("File not Found - 404 read_buildings_file\n");
        exit(1);
    }

    STUDIO studios;

    studios.config = malloc(sizeof(studios.config));

    while (!feof(bfile)) {
        fscanf(bfile, "%d[^,]", &studios.id);
        fscanf(bfile, ",%d[^,]", &studios.number);
        fscanf(bfile, ",%d[^,]", &studios.building);
        fscanf(bfile, ",%[^,]s", studios.config);
        fscanf(bfile, ",%d[^,]s", &studios.area);


        printf("%d %d %d %s %d \n", studios.id, studios.number, studios.building,
               studios.config, studios.area);
    }
    fclose(bfile);
}
#include "studios.h"
