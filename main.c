#include <stdio.h>

#include "buildings.h"
#include "events.h"


/**
 * @brief função main
 * @return
*/

int main() {
    //read_buildings_file("api_files/test.csv",4);
    //write_buildings_file("api_files/test2.csv");
    read_events_file("api_files/eventos.csv",5);
    return 0;
}

