#include <stdio.h>

#include "buildings.h"

/**
 * @brief função main
 * @return
*/

int main() {
    read_buildings_file("./api_files/edificios.csv",4);
    write_buildings_file("./api_files/test.csv");
    return 0;
}

