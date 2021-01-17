#include <stdio.h>

#include "buildings.h"
#include "events.h"
#include "studios.h"

/**
 * @brief função main
 * @return
 */

int main() {

    //BUILDINGS

    BUILDING_LIST *buildingList = read_buildings_to_list("api_files/edificios.csv");
    add_specific_building(buildingList,2589623,create_building());

    show_build_list(buildingList);
//write_buildings_file(buildingList, "api_files/test2.csv");
    //show_build_list(buildingList);
    //add_buildings_to_list_tail(create_building(), buildingList);
    //printf("------------------------\n");
    //show_build_list(buildingList);

    //delete_last_building_in_list(buildingList);
    //printf("------------------------\n");
    //show_build_list(buildingList);

    //STUDIOS
    //STUDIO *studio_array=read_studios_file("api_files/estudios.csv");
    //write_studios_file(studio_array,"api_files/test.csv");



    //read_events_file("api_files/eventos.csv");
    // write_events_file("api_files/test2.csv");
    return 0;
}

