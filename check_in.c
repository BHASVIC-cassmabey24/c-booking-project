#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <direct.h>
#include <ctype.h>

#include "common.c"





void check_in() {
    char first_name[255], surname[255];
    int day = 0, month = 0, year = 0, total_guests = 0, total_adults = 0, total_children = 0, stay_length = 0, roomnumber = 0, paper = 0, totalprice = 0, randomtempvar;
    char board[255];
    char booking_id[255 + 10];
    char dir[100];
    char file_path[150];
    FILE *file;

    printf("room number: ");
    scanf("%d", &roomnumber);
    fflush(stdin);
    printf("paper (1 = yes | 0 = no): ");
    scanf("%d", &roomnumber);
    fflush(stdin);
    printf("first name: ");
    scanf("%s", first_name);
    fflush(stdin);
    printf("surname: ");
    scanf("%s", surname);
    fflush(stdin);
    printf("birthdate: ");
    scanf("%d %d %d", &day, &month, &year);
    fflush(stdin);
    printf("guests: ");
    scanf("%d", &total_guests);
    fflush(stdin);
    printf("adults: ");
    scanf("%d", &total_adults);
    fflush(stdin);
    printf("children: ");
    scanf("%d", &total_children);
    fflush(stdin);

    printf("length of stay: ");
    scanf("%d", &stay_length);
    fflush(stdin);

    for (int i = 0; i < total_guests; i++) {
        printf("What boarding type does guest %d want: ", i);
        scanf("%s", board);
        fflush(stdin);
        if (validate_board(board) == 0) {
            printf("Incorrect boarding type\n");
            return;
        }
        printf("Is guest %d a child (1 = yes | 0 = no): ", i);
        scanf("%d", &randomtempvar);
        if (board == "FB") {
            if (randomtempvar == 1) {
                totalprice += 10;
            }
            totalprice += 20;
        } else if (board == "HB") {
            if (randomtempvar == 1) {
                totalprice += 7.5;
            }
            totalprice += 15;
        } else if (board == "BB") {
            if (randomtempvar == 1) {
                totalprice += 2.5;
            }
            totalprice += 5;
        }
    }

    if (
        // First name and surname validations
        has_numbers(first_name) || 
        strlen(first_name) > 15 || 
        strlen(first_name) < 3 ||
        has_numbers(surname) || 
        strlen(surname) > 15 || 
        strlen(surname) < 3 ||

        // Board type validation
        validate_board(board) == 0||

        // Date of birth validation
        day < 1 || 
        day > 31 || 
        month < 1 || 
        month > 12 || 

        // Guest validation
        total_guests < 0 || 
        total_guests > 4 ||
        total_adults < 0 ||
        total_adults > 4 ||
        total_children < 0 || 
        total_children > 4 ||
        (total_children + total_adults) != total_guests ||

        // Length of stay validation
        stay_length <= 0 ||

        // ROom number valdidation
        has_numbers(roomnumber) ||
        roomnumber <= 0 ||
        roomnumber >= 7 ||

        // Paper Validation
        paper != 0 &&
        paper != 1

    ) {
        printf("Validation has caught some incorrect infomation.\n");
        return;
    }

    generatebooking_id(surname, booking_id);
    printf("Your Booking id is: %s\n", booking_id);

    snprintf(dir, sizeof(dir), "storage/%s", booking_id);
    
    create_directory(dir);

    snprintf(file_path, sizeof(file_path), "%s/info.txt", dir);
    file = fopen(file_path, "w");

    fprintf(file, "%s\n", first_name);
    fprintf(file, "%s\n", surname);
    fprintf(file, "%d %d %d\n", day, month, year);
    fprintf(file, "%d\n", total_guests);
    fprintf(file, "%d\n", total_adults);
    fprintf(file, "%d\n", total_children);
    fprintf(file, "%s\n", board);
    fprintf(file, "%d\n", stay_length);
    fprintf(file, "%s\n", booking_id);
    fprintf(file, "%d\n", roomnumber);
    fprintf(file, "%d\n", paper);

    fclose(file);
    printf("Check-in complete. Guest information saved to %s\n", file_path);
}


