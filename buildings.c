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

void read_buildings_to_List(char *fname) {
    FILE *bfile = fopen(fname, "r");
    if (bfile == NULL) {
        printf("File not Found - 404 read_buildings_file\n");
        exit(1);
    }

    BUILDING build;

    BUILDING *L=NULL,*aux;

    while (!feof(bfile)) {
        if(L==NULL){
            build.name = malloc(sizeof(build.name));
            build.address = malloc(sizeof(build.address));
            L=(BUILDING*)malloc (1*sizeof(BUILDING));

            fscanf(bfile, "%d[^,]", L->id=build.id);
            fscanf(bfile, ",%[^,]s", L->name=build.name);
            fscanf(bfile, ",%lf[^,]", L->latitude=build.latitude);
            fscanf(bfile, ",%lf[^,]", L->longitude=build.longitude);
            fscanf(bfile, ",%[^,]s", L->address=build.address);
            fscanf(bfile, ",%lf[^\n]", L->priceperday=build.priceperday);
            aux=L;
        }

        else {
            aux->next=(BUILDING*)malloc (1*sizeof(BUILDING));
            aux=aux->next;
            strcpy(aux->name,fscanf(bfile, ",%[^,]s", L->name=build.name));
            aux->id=fscanf(bfile, "%d[^,]", L->id=&build.id);
            aux->next=NULL;
        }
    }



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
