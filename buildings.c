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

            fscanf(bfile, "%d[^,]", (&build.id));
            L->id=build.id;
            fscanf(bfile, ",%[^,]s", L->name=build.name);
            fscanf(bfile, ",%lf[^,]", &build.latitude);
            L->latitude=build.latitude;
            fscanf(bfile, ",%lf[^,]", &build.longitude);
            L->longitude=build.longitude;
            fscanf(bfile, ",%[^,]s", L->address=build.address);
            fscanf(bfile, ",%lf[^\n]", &build.priceperday);
            L->priceperday=build.priceperday;
            aux=L;
        }

        else {
            aux->next=(BUILDING*)malloc (1*sizeof(BUILDING));

            aux=aux->next;
            fscanf(bfile, "%d[^,]",(&build.id));
            aux->id=build.id;
            fscanf(bfile, ",%[^,]s",build.name);
            aux->name=build.name;
            fscanf(bfile, ",%lf[^,]", &build.latitude);
            aux->latitude=build.latitude;
            fscanf(bfile, ",%lf[^,]", &build.longitude);
            aux ->longitude=build.longitude;
            fscanf(bfile, ",%[^,]s", aux->address=build.address);
            fscanf(bfile, ",%lf[^\n]", &build.priceperday);
            aux->priceperday=build.priceperday;
            aux->next=NULL;
        }
    }
    fclose(bfile);
    show_build_list(L);
}


void show_build_list(BUILDING *L){
    if(L==NULL){
        printf("A Lista esta vazia!\n");
        return;
    }
    else {
        //enquanto houver nodos..
        while(L!=NULL){
            printf( "ID: %d, NAME: %s , LATITUDE: %lf, LONGITUDE: %lf, ADRESS: %s, PRICEPERDAY: %lf \n", L->id, L->name,
                    L->latitude,L->longitude,L->address, L->priceperday);

            L=L->next;
        }
    }
    return;
}