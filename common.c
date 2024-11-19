#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include "common.h"
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "Globals.h"

int bookings [4][256];

void generatebooking_id(char surname[], char booking_id[]) {
    srand(time(NULL));
    int r = rand();
    snprintf(booking_id, 255, "%s_%d", surname, r);
}

int has_numbers(char string[255]) {
    for (int i = 0; i < strlen(string); i++) {
        if (isdigit(string[i])) {
            return 1;
        }
    }
    return 0;
}

int validate_board(char board[]) {
    if (strcmp(board, "FB") == 0) {
        return 1;
    } else if (strcmp(board, "HB") == 0) {
        return 1;
    } else if (strcmp(board, "BB") == 0) {
        return 1;
    }
    return 0;
}


void create_directory(char *directory) {
    _mkdir(directory);
    printf("Directory created successfully: %s\n", directory);
}

int get_firstname(const char *booking_id) {
    char first_name[255];
    char folder[9] = "storage/";
    FILE *txtfile;
    strcat(folder, booking_id);

    printf("%s\n", folder);
    txtfile = fopen(folder, "r");

    if (txtfile == NULL) {
        printf("Error opening file\n");
    }



    printf("Content of the file are: \n");
}

// reference https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
int check_booking_id(const char *booking_id) {
    DIR *dir;
    struct dirent *entry;
    char path[256];
    struct stat statbuf;


    dir = opendir("storage");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    // Loop through the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path for each directory entry
        snprintf(path, sizeof(path), "storage/%s", entry->d_name);

        // Use stat to get information about the file/directory
        if (stat(path, &statbuf) == 0) {
            // Check if it's a directory
            if (S_ISDIR(statbuf.st_mode)) {
                // Compare the directory name with the booking_id
                if (strcmp(entry->d_name, booking_id) == 0) {
                    printf("Match found: Directory with Booking ID '%s' exists.\n", booking_id);
                    return 1;
                }
            }
        } else {
            return 0;
        }
    }

    // Close the directory
    closedir(dir);

    return 0;
}
// start of booking subprograms:
bool Incorrect_ID() {
    int check;
    printf("\nYou entered the wrong booking ID");
    printf("\nPlease enter 1 if you would like to  try again or 0 to go back to menu:\n ");
    fflush(stdin);
    scanf("%d", &check);
    if (check != 1) {
        return false;
    }
}
bool Incorrect_Booking() {
    int check;
    printf("\n You have the wrong type (B&B)");
    printf("\n We will send you back to the menu");
    printf("\n You are not eligible to book any tables for dinner ");
    printf("\n Please update your board type or create a new booking:\n ");
    sleep(6);
        return false;
}
int random_number() {

    srand(time(NULL));
    int r = (rand() %8) + 1;
    return r;
}

void Fill_Table(int R) {// this program will generate fake bookings which represent a day at the restaurant.

    printf("\n %d\n",R);
    bookings[0][0] = 7;
    bookings[0][1] = 9;
    for (int i = 1; i < 4; i++) {
        bookings[i][0] = 0;
        bookings[i][1] = 0;
    }

    switch(R) {// A random number is generated into this so people will get different experiences on each day
        case 1:
            bookings[1][0] = 1;
            bookings[3][1] = 1;
            break;

        case 2:
            bookings[1][1] = 1;
            bookings[4][0] = 1;
            bookings[2][1] = 1;
            break;

        case 3:
            bookings[1][1] = 1;
            bookings[2][1] = 1;
            bookings[3][1] = 1;
            bookings[4][0] = 1;
            bookings[4][1] = 1;
            break;

        case 4:
            bookings[4][0] = 1;
            bookings[4][1] = 1;
            bookings[1][0] = 1;
            bookings[1][1] = 1;
            bookings[2][1] = 1;
            bookings[2][0] = 1;
            bookings[3][1] = 1;
            bookings[3][0] = 1;
            break;

        case 5:
            bookings[3][0] = 1;
            bookings[4][1] = 1;
            bookings[4][0] = 1;
            bookings[3][1] = 1;
            break;

        case 6:
            bookings[2][1] = 1;
            bookings[3][1] = 1;
            bookings[4][1] = 1;
            break;

        case 7:
            bookings[1][0] = 1;
            bookings[4][1] = 1;
            bookings[3][0] = 1;
            bookings[2][1] = 1;
            break;

        case 8:

        bookings[4][1] = 1;
        bookings[1][0] = 1;
        bookings[1][1] = 1;
        bookings[2][1] = 1;
        bookings[2][0] = 1;
        bookings[3][1] = 1;
        bookings[3][0] = 1;
        break;

        default:
            printf("Error: Please try again");
            break;
    }

}
