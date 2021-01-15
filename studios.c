#include "studios.h"

STUDIO *read_studios_file(char *fname) {
    FILE *bfile = fopen(fname, "r");
    if (bfile == NULL) {
        printf("File not Found - 404 read_buildings_file\n");
        exit(1);
    }

    STUDIO *studios = malloc(sizeof(STUDIO));

    while (!feof(bfile)) {

        studios->config = malloc(sizeof(studios->config));
        fscanf(bfile, "%d[^,]", &studios->id);
        fscanf(bfile, ",%d[^,]", &studios->number);
        fscanf(bfile, ",%d[^,]", &studios->building);
        fscanf(bfile, ",%[^,]s", studios->config);
        fscanf(bfile, ",%d[^,]s", &studios->area);
        printf("%d %d %d %s %d \n", studios->id, studios->number, studios->building, studios->config, studios->area);
        studios++;
    }
    fclose(bfile);
    while(studios->id!=0){
        studios--;
    }
    studios++;

    return studios;
}


void write_studios_file(STUDIO *studio_array, char *fname) {
    FILE *sfile = fopen(fname, "w");
    while (studio_array != NULL) {

        studio_array->config = malloc(sizeof(studio_array->config));
        fprintf(sfile, "%d,%d,%d,%s,%d\n", studio_array->id, studio_array->number,
                studio_array->building, studio_array->config, studio_array->area);
        studio_array++;
    }
}

