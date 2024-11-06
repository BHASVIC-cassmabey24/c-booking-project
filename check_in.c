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
    int day = 0, month = 0, year = 0, total_guests = 0, total_adults = 0, total_children = 0, stay_length = 0;
    char board[255];
    char booking_id[255 + 10];
    char dir[100];
    char file_path[150];
    FILE *file;

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
    printf("board: ");
    scanf("%s", board);
    fflush(stdin);
    printf("length of stay: ");
    scanf("%d", &stay_length);
    fflush(stdin);

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

        // Guests validation
        total_guests < 0 || 
        total_guests > 4 ||
        total_adults < 0 ||
        total_adults > 4 ||
        total_children < 0 || 
        total_children > 4 ||
        (total_children + total_adults) != total_guests ||

        // Length of stay validation
        stay_length <= 0

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

    fclose(file);
    printf("Check-in complete. Guest information saved to %s\n", file_path);
}