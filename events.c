#include "events.h"

void read_events_file(char *fname, int value) {
    FILE *efile = fopen(fname, "r");
    if (efile == NULL) {
        printf("File not Found - 404 read_events_file\n");
        exit(1);
    }

    EVENT event;

    event.type = malloc(sizeof(event.type));
    event.platform = malloc(sizeof(event.platform));

    for (int i = 0; i < value; i++) {
        fscanf(efile, "%d[^,]", &event.id);
        fscanf(efile, ",%[^,]s", event.type);

        fscanf(efile, ",%d[^-]", event.check_in.year);
        fscanf(efile, "-%d[^-]", event.check_in.month);
        fscanf(efile, "-%d[^,]", event.check_in.day);

        fscanf(efile, ",%d[^-]", event.check_out.year);
        fscanf(efile, "-%d[^-]", event.check_out.month);
        fscanf(efile, "-%d[^,]", event.check_out.day);

        fscanf(efile, ",%d[^,]", event.guest);

        fscanf(efile, ",%d[^,]", event.studio);


        fscanf(efile, ",%[^\n]s", &event.platform);


        printf("%d %s %d-%d-%d %d-%d-%d %d %d %s\n", event.id, event.type, event.check_in.year, event.check_in.month,
               event.check_in.day,
               event.check_out.year, event.check_out.month, event.check_out.day, event.guest, event.studio,
               event.platform);


        //fclose(efile);
    }
}
/*
void write_events_file(char *fname) {

    FILE *efile = fopen(fname, "a");

     // Se for necessario obrigar um ficheiro esoecifico.
    if (efile == NULL) {
        printf("File not Found - 404 write_events_file\n");
        exit(1);
    }


    event event;
    event.name = malloc(sizeof(event.name));
    event.address = malloc(sizeof(event.address));
    event.id = 43;
    event.name = "this is a test";
    event.latitude = 1.32322;
    event.longitude = 82.32322;
    event.address = "random address";
    event.priceperday = 34.98;
    fprintf(efile, "%d,%s,%lf,%lf,%s,%lf\n", event.id, event.name, event.latitude, event.longitude, event.address,
            event.priceperday);
}
*/