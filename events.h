#ifndef AED1_LP1_EVENTS_H
#define AED1_LP1_EVENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date {
    int day;
    int month;
    int year;
} DATE;

typedef struct event {
    int id;
    char *type;
    struct date check_in;
    struct date check_out;
    int guest;
    int studio;
    char *platform;
} EVENT;

void read_events_file(char *fname);

void write_events_file(char *fname);
#endif
