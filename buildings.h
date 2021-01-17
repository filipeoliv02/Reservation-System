#ifndef AED1_LP1_BUILDINGS_H
#define AED1_LP1_BUILDINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct building {
    int id;
    char *name;
    double latitude;
    double longitude;
    char *address;
    double priceperday;
    struct building *next;
    struct studio *studios;
} BUILDING;

typedef struct building_list {
    BUILDING *pbuildings;
    int size;
} BUILDING_LIST;


/**
 * Ler do ficheiro build, apenas guarda a ultima linha
 * @param fname
 */
void read_buildings_file(char *fname);

/**
 * escrever uma no fim do ficheiro novo building
 * @param fname
 */
void write_buildings_file(BUILDING_LIST *buildingList, char *fname);

/**
 * Método para criar um novo build na lista em memoria;
 * @return build
 */
BUILDING *create_building();

/**
 * Guardar numa lista ligada os buildings do ficheiro enviado em argumento do método
 * @param fname
 * @return
 */
BUILDING_LIST *read_buildings_to_list(char *fname);

/**
 * método de teste para enviar para a consola a lista de buildings
 * @param L
 */
void show_build_list(BUILDING_LIST *L);

/**
 * Adiciona na ultima posição da list build um novo build
 * @param building
 * @param buildingList
 * @return
 */
BUILDING_LIST *add_buildings_to_list_tail(BUILDING *building, BUILDING_LIST *buildingList);

/**
 * Apagar ultimo endereço da lista enviada em argumento
 * @param buildingList
 */
BUILDING_LIST *delete_last_building_in_list(BUILDING_LIST *buildingList);

BUILDING_LIST *delete_specific_building(BUILDING_LIST *buildingList, int id);

BUILDING_LIST *add_specific_building(BUILDING_LIST *buildingList, int pos, BUILDING *build);


#endif
