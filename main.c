#include <stdio.h>

#include "buildings.h"
#include "events.h"
#include "studios.h"

/**
 * @brief função main
 * @return
 */

int main() {
    read_buildings_file("api_files/edificios.csv");
    /*write_buildings_file("api_files/test2.csv");*/
    //remove_fromBuildings_file("api_files/test2.csv");
   /*read_events_file("api_files/eventos.csv");*/
    //write_events_file("api_files/test.csv");
    //read_studios_file("api_files/estudios.csv");
    //write_studios_file("api_files/test.csv");

    return 0;
}

