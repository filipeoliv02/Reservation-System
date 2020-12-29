#include "events.h"

void read_events_file(char *fname) {
    FILE *efile = fopen(fname, "r");
    if (efile == NULL) {
        printf("File not Found - 404 read_events_file\n");
        exit(1);
    }

    EVENT event;

    event.type = malloc(sizeof(event.type));
    event.platform = malloc(sizeof(event.platform));
    while (!feof(efile)) {
        fscanf(efile, "%d[^,]", &event.id);
        fscanf(efile, ",%[^,]s", event.type);
        fscanf(efile, ",%d[^-]", &event.check_in.year);
        fscanf(efile, "-%d[^-]", &event.check_in.month);
        fscanf(efile, "-%d[^,]", &event.check_in.day);
        fscanf(efile, ",%d[^-]", &event.check_out.year);
        fscanf(efile, "-%d[^-]", &event.check_out.month);
        fscanf(efile, "-%d[^,]", &event.check_out.day);
        fscanf(efile, ",%d[^,]", &event.guest);
        fscanf(efile, ",%d[^,]", &event.studio);
        fscanf(efile, ",%[^\n]s", event.platform);

        printf("%d %s %d-%d-%d %d-%d-%d %d %d %s\n", event.id, event.type,
               event.check_in.year, event.check_in.month, event.check_in.day,
               event.check_out.year, event.check_out.month, event.check_out.day,
               event.guest, event.studio, event.platform);
    }
    fclose(efile);
}
void write_events_file(char *fname) {

    FILE *efile = fopen(fname, "a");

    EVENT event;
    event.type = malloc(sizeof(event.type));
    event.platform = malloc(sizeof(event.platform));
    event.id = 25;
    event.type = "this is a test";
    event.check_in.year = 2020;
    event.check_in.month=12;
    event.check_in.day=25;
    event.check_out.year=2021;
    event.check_out.month=01;
    event.check_out.day=1;
    event.guest=1;
    event.studio=2;
    event.platform="AirBnE";

    fprintf(efile, "%d,%s,%d-%d-%d,%d-%d-%d,%d,%d,%s\n",
            event.id,
            event.type,
            event.check_in.year,
            event.check_in.month,
            event.check_in.day,
            event.check_out.year,
            event.check_out.month,
            event.check_out.day,
            event.guest,
            event.studio,
            event.platform);
}
