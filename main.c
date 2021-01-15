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
    //write_buildings_file(buildingList, "api_files/test2.csv");
    //add_buildings_to_list_tail(create_building(), buildingList);
    //show_build_list(buildingList);
    //delete_last_building_in_list(buildingList);

    //STUDIOS
    read_studios_file("api_files/estudios.csv");


    return 0;
}

