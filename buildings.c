#include "buildings.h"

/**
 * @brief lê ficheiro para uma lista ligada - deprecated
 * @param fname file name
 */
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

/**
 * @brief Escreve o que tem na lista ligada para o ficheiro
 * @param buildingList
 * @param fname
 */
void write_buildings_file(BUILDING_LIST *buildingList, char *fname) {
    FILE *bfile = fopen(fname, "w");
    BUILDING *aux = buildingList->pbuildings;

    while (aux->next != NULL) {
        fprintf(bfile, "%d,%s,%lf,%lf,%s,%lf\n", aux->id, aux->name,
                aux->latitude, aux->longitude, aux->address, aux->priceperday);
        aux = aux->next;
    }
    fprintf(bfile, "%d,%s,%lf,%lf,%s,%lf\n", aux->id, aux->name,
            aux->latitude, aux->longitude, aux->address, aux->priceperday);
    fclose(bfile);
}

/**
 * @brief lê do ficheiro para uma lista ligada e retorna a lista ligada
 * @param fname
 * @return a lista ligada
 */
BUILDING_LIST *read_buildings_to_list(char *fname) {
            FILE *bfile = fopen(fname, "r");
            if (bfile == NULL) {
        printf("File not Found - 404 read_buildings_file\n");
        exit(1);
    }

    BUILDING *L = NULL, *aux;

    int count = 0; //Contador de buildings

    while (!feof(bfile)) {
        count = count + 1;
        if (L == NULL) {

            L = (BUILDING *) malloc(sizeof(BUILDING));

            L->name = (char *) malloc(sizeof(char) * 100);
            L->address = (char *) malloc(sizeof(char) * 100);

            //L=(BUILDING*)malloc (sizeof(BUILDING));

            fscanf(bfile, "%d[^,]", &L->id);
            //L->id=build.id;
            fscanf(bfile, ",%[^,]s", L->name);
            //L->name=build.name;
            fscanf(bfile, ",%lf[^,]", &L->latitude);
            //L->latitude=build.latitude;
            fscanf(bfile, ",%lf[^,]", &L->longitude);
            //L->longitude=build.longitude;
            fscanf(bfile, ",%[^,]s", L->address);
            //L->address=build.address;
            fscanf(bfile, ",%lf[^\n]", &L->priceperday);
            //L->priceperday=build.priceperday;
            L->nstudios=0;
            aux = L;

        } else {

            aux->next = (BUILDING *) malloc(1 * sizeof(BUILDING));
            aux = aux->next;
            aux->name = (char *) malloc(sizeof(char) * 100);
            aux->address = (char *) malloc(sizeof(char) * 100);
            fscanf(bfile, "%d[^,]", &aux->id);
            //aux->id=&L->id;
            fscanf(bfile, ",%[^,]s", aux->name);
            //aux->name=build.name;
            fscanf(bfile, ",%lf[^,]", &aux->latitude);
            //aux->latitude=build.latitude;
            fscanf(bfile, ",%lf[^,]", &aux->longitude);
            //aux ->longitude=build.longitude;
            fscanf(bfile, ",%[^,]s", aux->address);
            //aux->address=build.address;
            fscanf(bfile, ",%lf[^\n]", &aux->priceperday);
            //aux->priceperday=build.priceperday;
            aux->nstudios=0;
            aux->next = NULL;
        }
    }
    BUILDING_LIST *buildingList = (BUILDING_LIST *) malloc(sizeof(BUILDING_LIST));
    buildingList->size = count;
    buildingList->pbuildings = L;

    fclose(bfile);

    return (buildingList);
    //show_build_list(L);
}


/**
 * Add to last position a new Build
 * @param building
 * @param buildingList
 * @return the linked list
 */
BUILDING_LIST *add_buildings_to_list_tail(BUILDING *building, BUILDING_LIST *buildingList) {

    if (building == NULL || buildingList == NULL) {
        return (buildingList);
    } else {
        BUILDING *aux = buildingList->pbuildings;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = building;
        building->next = NULL;
        buildingList->size++;
    }
    return buildingList;
}

/**
 * @brief prints to screen the content of the building list
 * @param L
 */
void show_build_list(BUILDING_LIST *L) {
    BUILDING *building = L->pbuildings;
    if (building == NULL) {
        printf("A Lista esta vazia!\n");
        return;
    } else {
        //enquanto houver nodes..
        while (building != NULL) {
            printf("ID: %d, NAME: %s , LATITUDE: %lf, LONGITUDE: %lf, ADRESS: %s, PRICEPERDAY: %lf \n", building->id,
                   building->name,
                   building->latitude, building->longitude, building->address, building->priceperday);
            building = building->next;
        }
    }
}

/**
 * @brief create a building
 * @return the building
 */
BUILDING *create_building() {
    BUILDING *build;
    build = malloc(sizeof(BUILDING));
    build->name = malloc(sizeof(build->name));
    build->address = malloc(sizeof(build->address));

    build->id = 43;
    build->name = "this is a test random";
    build->latitude = 1.232;
    build->longitude = 35.32322;
    build->address = "random address";
    build->priceperday = 34.64454;
    return (build);
}

/**
 * @brief removes the last node from the linked list
 * @param buildingList
 * @return returns the linked list without the tail node
 */
BUILDING_LIST *delete_last_building_in_list(BUILDING_LIST *buildingList) {

    if (buildingList == NULL) {
        printf("Building list is NULL - 404 delete_last_building_in_list\n");
        exit(1);
    } else if (buildingList->size == 1) {
        free(buildingList->pbuildings);
        buildingList->size = 0;

        return buildingList;
    } else {
        BUILDING *aux = buildingList->pbuildings;
        while (aux->next->next != NULL) {
            aux = aux->next;
        }
        free(aux->next);
        aux->next = NULL;

        buildingList->size--;

    }
    return (buildingList);

}

/**
 * @brief delete a building searching it first by his id
 * @param buildingList
 * @param id
 * @return
 */
BUILDING_LIST *delete_specific_building(BUILDING_LIST *buildingList, int id) {
    if (buildingList == NULL) {
        printf("Building list is NULL - 404 delete_specific_building\n");
        exit(1);
    }
    BUILDING *aux = buildingList->pbuildings;
    BUILDING *aux1 = buildingList->pbuildings;
    while (1) {
        if (aux->next->id == id) {
            aux1 = aux->next;
            aux->next = aux1->next;
            free(aux1);
            break;
        }
    }
    buildingList->size--;
    free(aux);

    return (buildingList);
}

/**
 * @brief add a building at a specific position
 * @param buildingList
 * @param pos
 * @param build
 * @return
 */
BUILDING_LIST *add_specific_building(BUILDING_LIST *buildingList, int pos, BUILDING *build) {
    if (buildingList == NULL) {
        buildingList->size++;
        buildingList->pbuildings = build;
        return buildingList;
    }
    if (pos > buildingList->size) {
        pos = buildingList->size + 1;
    }
    BUILDING *aux = buildingList->pbuildings;
    BUILDING *aux1 = build;
    if (pos == 1) {
        buildingList->pbuildings = build;
        buildingList->pbuildings->next = aux;
        return (buildingList);
    }
    for (int i = 0; i < pos - 2; i++) {
        aux = aux->next;
    }
    aux1->next = aux->next;
    aux->next = aux1;
    buildingList->size++;
    return (buildingList);
}

/**
 * @brief Find specific build by his id
 * @param buildingList
 * @param id
 * @return
 */
BUILDING *find_specific_build(BUILDING_LIST *buildingList, int id) {
    if (buildingList == NULL) {
        printf("Building list is NULL - 404 find_specific_build\n");
        return NULL;
    }

    BUILDING *aux = buildingList->pbuildings;

    for (int i = 0; buildingList->size; i++) {
        if (aux->id == id) {
            return (aux);
        }
        aux = aux->next;
    }
    printf("404 NOT FOUND - FIND_SPECIFIC_BUILD\n");
    return NULL;
}

/**
 * @brief bubble sort to sort the building list
 * @param buildingList
 * @return
 */
BUILDING_LIST *sort_buildings(BUILDING_LIST *buildingList) {
    int swapped, i;
    BUILDING *aux;
    BUILDING *aux1 = NULL;
    /* Checking for empty list */
    if (buildingList->pbuildings == NULL) {
        printf("Building list is NULL - 404 sort_buildings\n");
        return NULL;
    }
    do {
        swapped = 0;
        aux = buildingList->pbuildings;

        while (aux->next != aux1) {
            if (aux->id > aux->next->id) {
                swap(aux, aux->next);
                swapped = 1;
            }
            aux = aux->next;
        }
        aux1 = aux;
    } while (swapped);
    return (buildingList);
}

/**
 * @brief swap function used at sort_buildings
 * @param a
 * @param b
 */
void swap(BUILDING *a, BUILDING *b) {
    int temp = a->id;
    a->id = b->id;
    b->id = temp;
}