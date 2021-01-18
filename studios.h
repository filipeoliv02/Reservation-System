#ifndef AED1_LP1_STUDIOS_H
#define AED1_LP1_STUDIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buildings.h"


BUILDING_LIST *read_studios_file(BUILDING_LIST *buildingList, char *fname);

void write_studios_file(BUILDING_LIST *buildingList, char *fname);
BUILDING *find_specific_studio(BUILDING_LIST *buildingList, int id);

#endif
