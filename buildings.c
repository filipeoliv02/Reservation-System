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

BUILDING_LIST* read_buildings_to_List(char *fname) {
    FILE *bfile = fopen(fname, "r");
    if (bfile == NULL) {
        printf("File not Found - 404 read_buildings_file\n");
        exit(1);
    }

    BUILDING *L=NULL, *aux;

    int count=0; //Contador de buildings

    while (!feof(bfile)) {
        count=count+1;
        if(L==NULL){

            L=(BUILDING*)malloc (sizeof(BUILDING));

            L->name =(char*) malloc(sizeof(char)*100);
            L->address =(char*) malloc(sizeof(char)*100);

            //L=(BUILDING*)malloc (sizeof(BUILDING));

            fscanf(bfile, "%d[^,]",&L->id);
            //L->id=build.id;
            fscanf(bfile, ",%[^,]s",L->name);
            //L->name=build.name;
            fscanf(bfile, ",%lf[^,]", &L->latitude);
            //L->latitude=build.latitude;
            fscanf(bfile, ",%lf[^,]", &L->longitude);
            //L->longitude=build.longitude;
            fscanf(bfile, ",%[^,]s", L->address);
            //L->address=build.address;
            fscanf(bfile, ",%lf[^\n]", &L->priceperday);
            //L->priceperday=build.priceperday;
            aux=L;
        }
        else {

            aux->next=(BUILDING*)malloc (1*sizeof(BUILDING));
            aux=aux->next;
            aux->name =(char*) malloc(sizeof(char)*100);
            aux->address =(char*) malloc(sizeof(char)*100);
            fscanf(bfile, "%d[^,]", &aux->id);
            //aux->id=&L->id;
            fscanf(bfile, ",%[^,]s",aux->name);
            //aux->name=build.name;
            fscanf(bfile, ",%lf[^,]", &aux->latitude);
            //aux->latitude=build.latitude;
            fscanf(bfile, ",%lf[^,]", &aux ->longitude);
            //aux ->longitude=build.longitude;
            fscanf(bfile, ",%[^,]s", aux->address);
            //aux->address=build.address;
            fscanf(bfile, ",%lf[^\n]", &aux->priceperday);
            //aux->priceperday=build.priceperday;
            aux->next=NULL;
        }
    }
    BUILDING_LIST *buildingList =(BUILDING_LIST*)malloc (sizeof(BUILDING_LIST));
    buildingList->Size=count;
    buildingList->pbuildings=L;

    fclose(bfile);

    return(buildingList);
    //show_build_list(L);
}



/**
 * Add to last position a new Build
 * @param building
 * @param buildingList
 * @return
 */
BUILDING_LIST* add_buildings_to_list_tail(BUILDING *building,BUILDING_LIST* buildingList)
{

    if (building == NULL || buildingList==NULL){
        return(buildingList);
    }
    else{
        BUILDING *aux = buildingList->pbuildings;
        while(aux->next!=NULL){
            aux=aux->next;
        }

        aux->next=building;
        building->next=NULL;
    }
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