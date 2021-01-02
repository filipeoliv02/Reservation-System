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
    struct studio_array **studios;

} BUILDING;

typedef struct building_list {
    BUILDING *pbuildings;
    int Size;
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
void write_buildings_file(char *fname);

/**
 * Método para criar um novo build na lista em memoria;
 * @return build
 */
BUILDING* creat_random_building();

/**
 * Guardar numa lista ligada os buildings do ficheiro enviado em argumento do método
 * @param fname
 * @return
 */
BUILDING_LIST* read_buildings_to_List(char *fname);
/**
 * método de teste para enviar para a consola a lista de buildings
 * @param L
 */
void show_build_list(BUILDING *L);

/**
 * Adiciona na ultima posição da list build um novo build
 * @param building
 * @param buildingList
 * @return
 */
BUILDING_LIST* add_buildings_to_list_tail(BUILDING* building,BUILDING_LIST* buildingList);

/**
 * Apagar ultimo endereço da lista enviada em argumento
 * @param buildingList
 */
BUILDING_LIST* delete_last_building_in_list(BUILDING_LIST* buildingList);

#endif
