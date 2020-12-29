#include "buildings.h"

void read_buildings_file(char *fname) {
    FILE *bfile = fopen(fname, "r");
    if (bfile == NULL) {
        printf("File not Found - 404 read_buildings_file\n");
        exit(1);
    }

    BUILDING build;

    build.name = malloc(sizeof(build.name));
    build.address = malloc(sizeof(build.address));

    while (!feof(bfile)) {
        fscanf(bfile, "%d[^,]", &build.id);
        fscanf(bfile, ",%[^,]s", build.name);
        fscanf(bfile, ",%lf[^,]", &build.latitude);
        fscanf(bfile, ",%lf[^,]", &build.longitude);
        fscanf(bfile, ",%[^,]s", build.address);
        fscanf(bfile, ",%lf[^\n]", &build.priceperday);

        printf("%d %s %lf %lf %s %lf\n", build.id, build.name, build.latitude,
               build.longitude, build.address, build.priceperday);
    }
    fclose(bfile);
}

void write_buildings_file(char *fname) {
    FILE *bfile = fopen(fname, "a");
    /**
     * Se for necessario obrigar um ficheiro esoecifico.
    if (bfile == NULL) {
        printf("File not Found - 404 write_buildings_file\n");
        exit(1);
    }
     **/

    BUILDING build;
    build.name = malloc(sizeof(build.name));
    build.address = malloc(sizeof(build.address));
    build.id = 43;
    build.name = "this is a test";
    build.latitude = 1.32322;
    build.longitude = 82.32322;
    build.address = "random address";
    build.priceperday = 34.98;
    fprintf(bfile, "%d,%s,%lf,%lf,%s,%lf\n", build.id, build.name,
            build.latitude, build.longitude, build.address, build.priceperday);
}
