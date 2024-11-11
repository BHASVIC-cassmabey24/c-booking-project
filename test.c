// C program to read a file line by line

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getinfo(char booking_id[100])
{
    char dir[255] = "storage/";
    strcat(dir, booking_id);
    strcat(dir, "/info.txt");

    FILE* file = fopen(dir, "r");

    // Buffer to store each line of the file.
    char line[255], firstname[255], surname[255], board[255];
    int counter = 0, idkothercounter = 0, guests, adults, children, days, day, month, year;

    if (file != NULL) {
        while (fgets(line, sizeof(line), file)) {
            char dob[255];
            switch(counter) {
                case 0:
                    strcpy(firstname, line);
                break;
                case 1:
                    strcpy(surname, line);
                    break;
                case 2:
                    strcpy(dob, line);
                    char* token = strtok(dob, " ");

                    while (token != NULL) {
                        if (idkothercounter == 0) {
                            day = atoi(token);
                        } else if (idkothercounter == 1) {
                            month = atoi(token);
                        } else if (idkothercounter == 2) {
                            year = atoi(token);
                            break;
                        }
                        idkothercounter++;
                        token = strtok(NULL, " ");
                    }
                    break;
                case 3:
                    guests = atoi(line);
                    break;
                case 4:
                    adults = atoi(line);
                    break;
                case 5:
                    children = atoi(line);
                    break;
                case 6:
                    strcpy(board, line);
                    break;
                case 7:
                    days = atoi(line);
                    break;
                case 8:
                    strcpy(booking_id, line);
                    break;
            }
            counter += 1;
        }

        return firstname, surname, day, month, year, guests, adults, children, board, days, booking_id;

        fclose(file);
    }
    else {
        fprintf(stderr, "Unable to open file!\n");
    }

    return 0;
}


int main(void) {
    char booking_id[255];
    strcpy(booking_id, "mabey_30840");
    getinfo(booking_id);
}