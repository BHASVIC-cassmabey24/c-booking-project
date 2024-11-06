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

bool validate_board(char board[]) {
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



// DONT TOUCH (taken strait from stackoverflow with a few adjustments to fit this)
//int check_booking_id(const char *booking_id) {
//    DIR *dir;
//    struct dirent *entry;
//    char path[256];
//    struct stat statbuf;
//    
//    // Open the directory
//    dir = opendir("storage");
//    if (dir == NULL) {
//        perror("opendir");
//        return 1;
//    }
//
//    // Loop through the directory entries
//    while ((entry = readdir(dir)) != NULL) {
//        // Skip "." and ".." entries
//        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
//            continue;
//        }
//
//        // Construct the full path for each directory entry
//        snprintf(path, sizeof(path), "storage/%s", entry->d_name);
//
//        // Use stat to get information about the file/directory
//        if (stat(path, &statbuf) == 0) {
//            // Check if it's a directory
//            if (S_ISDIR(statbuf.st_mode)) {
//                // Compare the directory name with the booking_id
//                if (strcmp(entry->d_name, booking_id) == 0) {
//                    printf("Match found: Directory with Booking ID '%s' exists.\n", booking_id);
//                    // You can add any further actions here, such as processing the directory
//                }
//            }
//        } else {
//            perror("stat");
//        }
//    }
//
//    // Close the directory
//    closedir(dir);
//
//    return 0;
//}