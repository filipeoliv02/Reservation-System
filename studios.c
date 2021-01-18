#include "studios.h"
#include "buildings.h"

/**
 * Read Studios in txt to link with list of buildings
 * @param fname
 * @param fbuildname
 * @return a
 */
BUILDING_LIST *read_studios_file(BUILDING_LIST *buildingList, char *fname) {
    FILE *bfile = fopen(fname, "r");
    if (bfile == NULL) {
        printf("File not Found - 404 read_buildings_file\n");
        exit(1);
    }


    STUDIO *aux = malloc(sizeof(STUDIO));
    STUDIO *aux1;
    BUILDING *build = malloc(sizeof(BUILDING));

    while (!feof(bfile)) {
        aux1 = malloc(sizeof(STUDIO));
        aux->config = malloc(sizeof(aux->config));
        fscanf(bfile, "%d[^,]", &aux->id);
        fscanf(bfile, ",%d[^,]", &aux->number);
        fscanf(bfile, ",%d[^,]", &aux->building);
        fscanf(bfile, ",%[^,]s", aux->config);
        fscanf(bfile, ",%d[^,]s", &aux->area);
        printf("%d %d %d %s %d \n", aux->id, aux->number, aux->building, aux->config, aux->area);


        build = find_specific_build(buildingList, aux->building);

        if (build != NULL) {
            if (build->nstudios == 0) {
                build->studios = malloc(sizeof(STUDIO));
            }

            aux1->config = malloc(sizeof(aux->config));
            aux1 = build->studios + build->nstudios;
            *aux1 = *aux;
            build->nstudios++;
        }
    }


    fclose(bfile);
    return buildingList;
}


void write_studios_file(STUDIO *studio_array, char *fname) {
    FILE *sfile = fopen(fname, "w");

    if (fname == NULL) {
        printf("File not Found - 404 write_studios_file\n");
        exit(1);
    }

    while (studio_array != NULL) {

        studio_array->config = malloc(sizeof(studio_array->config));
        fprintf(sfile, "%d,%d,%d,%s,%d\n", studio_array->id, studio_array->number,
                studio_array->building, studio_array->config, studio_array->area);
        studio_array++;
    }
}

