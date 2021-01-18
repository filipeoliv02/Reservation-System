#include "studios.h"
#include "buildings.h"

/**
 * @brief Read Studios in txt to link with list of buildings
 * @param fname
 * @param fbuildname
 * @return
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

/**
 * @brief Write Studios in txt from building List
 * @param buildingList
 * @param fname
 * @return
 */
void write_studios_file(BUILDING_LIST *buildingList, char *fname) {
    FILE *sfile = fopen(fname, "w");
    BUILDING *build = buildingList->pbuildings;
    for (int j = 0; j < buildingList->size - 1; j++) {
        for (int i = 0; i < build->nstudios; i++) {
            fprintf(sfile, "%d,%d,%d,%s,%d\n", build->studios->id, build->studios->number, build->studios->building,
                    build->studios->config, build->studios->area);
            build->studios++;
        }
        build = build->next;
    }
    fclose(sfile);
}

BUILDING *find_specific_studio(BUILDING_LIST *buildingList, int id) {
    if (buildingList == NULL) {
        printf("Building list is NULL - 404 find_specific_build\n");
        return NULL;
    }
    BUILDING *build = buildingList->pbuildings;
    for (int j = 0; j < buildingList->size - 1; j++) {
        for (int i = 0; i < build->nstudios; i++) {
            if (build->studios->id == id) {
                return build;
            }

            build->studios++;
        }
        build = build->next;
    }
    return NULL;

}


BUILDING_LIST *add_studio(BUILDING_LIST *buildingList, int buildid) {

    BUILDING *build = buildingList->pbuildings;

    for (int i = 0; i < buildingList->size - 1; i++) {

        if (build->id == buildid) {
            for (int j = 0; j < build->nstudios; j++) {
                build->studios++;
            }
            build->studios->id = 51;  //hardcoded easy to resolve
            build->studios->number = 45;
            build->studios->building = buildid;
            build->studios->config = "T6";
            build->studios->area = 999;
            return buildingList;
        }
        build = build->next;
    }
    return NULL;
}


