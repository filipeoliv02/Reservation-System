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
}


void write_studios_file(char *fname) {
    FILE *sfile = fopen(fname, "a");
    STUDIO studio;

    studio.config = malloc(sizeof(studio.config));
    studio.id = 75;
    studio.number = 32;
    studio.building = 4;
    studio.config = "T100";
    studio.area = 5;

    fprintf(sfile, "%d,%d,%d,%s,%d\n", studio.id, studio.number,
            studio.building, studio.config, studio.area);
}

#include "studios.h"
