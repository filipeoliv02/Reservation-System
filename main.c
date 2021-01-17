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
    //find_specific_build(buildingList,2);

    //STUDIOS
    BUILDING_LIST *buildingList1 =read_studios_file("api_files/estudios.csv","api_files/edificio.csv");
    //write_studios_file(studio_array,"api_files/test.csv");

    return 0;
}

