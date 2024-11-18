#include <stdio.h>
#include <stdlib.h>
#include "common.h"


void check_out() {
    printf("Checking out...");
    char first_name[255], surname[255];
    int day = 0, month = 0, year = 0, total_guests = 0, total_adults = 0, total_children = 0, stay_length = 0, roomnumber = 0, paper = 0, totalprice = 0, randomtempvar;
    char board[255];
    char booking_id[255 + 10];

    FILE *file;
    FILE =filepointer
    file = fopen(file_path, "r");
    fscanf(file, "%s", &first_name);
    fscanf(file, "%s", &surname);
    fscanf(filepointer, "%d %d %d", &day, &month, &year);
    fscanf(filepointer, "%d", &total_guests);
    fscanf(filepointer, "%d", &total_adults);
    fscanf(filepointer, "%d", &total_children);
    fscanf(file, "%s", &board);
    fscanf(filepointer, "%d", &stay_length);
    fscanf(file, "%s", &booking_id);
    fscanf(filepointer, "%d", &roomnumber);
    fscanf(filepointer, "%d", &paper);

}