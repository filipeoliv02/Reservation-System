#include "studios.h"
#include "buildings.h"

/**
 * Read Studios in txt to link with list of buildings
 * @param fname
 * @param fbuildname
 * @return
 */
BUILDING_LIST *read_studios_file(char *fname, char *fbuildname) { //building pointer
    FILE *bfile = fopen(fname, "r");
    if (bfile == NULL) {
        printf("File not Found - 404 read_buildings_file\n");
        exit(1);
    }

    STUDIO *studios = malloc(sizeof(STUDIO));
    STUDIO *aux = studios;
    //BUILDING_LIST *buildingList= malloc (sizeof(struct building_list));
    BUILDING_LIST *buildingList =read_buildings_to_list(fbuildname);

    while (!feof(bfile)) {

        aux->config = malloc(sizeof(aux->config));

        fscanf(bfile, "%d[^,]", &aux->id);
        fscanf(bfile, ",%d[^,]", &aux->number);
        fscanf(bfile, ",%d[^,]", &aux->building);
        fscanf(bfile, ",%[^,]s", aux->config);
        fscanf(bfile, ",%d[^,]s", &aux->area);
        printf("%d %d %d %s %d \n", aux->id, aux->number, aux->building, aux->config, aux->area);

        STUDIO *aux = malloc(sizeof(STUDIO));

        BUILDING *build = find_specific_build(buildingList,studios->building);
        if(build!= NULL){
            build->studios = studios;
        }
        aux++;
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

