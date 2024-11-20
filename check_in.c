#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* generate_booking_id(char name[255], char booking_id[255]) {
    srand(time(NULL));
    int random_num = rand() % 10000;
    sprintf(booking_id, "%s_%d", name, random_num);
    return booking_id;
}


char* randominsult() {
    static char insult[100]; // Reference https://www.geeksforgeeks.org/static-variables-in-c/
    const char *adjectives[] = {"stupid", "silly", "weird looking", "clown like", "weak", "shrimpy", "short", "monkey brained"};
    const char *nouns[] = {"dum dum", "doofus", "nerd", "geek", "clown"};

    int num_adjectives = sizeof(adjectives) / sizeof(adjectives[0]);
    int num_nouns = sizeof(nouns) / sizeof(nouns[0]);

    srand(time(NULL));

    const char *adj = adjectives[rand() % num_adjectives];
    const char *noun = nouns[rand() % num_nouns];

    sprintf(insult, "%s %s", adj, noun);

    return insult;
}

int check_booking_id(char* booking_id) {
    char txtfile[255];
    sprintf(txtfile, "./storage/%s.txt", booking_id);

    FILE *file = fopen(txtfile, "r");
    if (file == NULL) {
        return NULL;
    }
    fclose(file);
    return 1;
}

char* get_info(char* booking_id, char* linenumber) {

    if (!check_booking_id(booking_id)) {
        printf("Booking ID not found");
        return;
    }

    int line_number = 0;
    char line[256];
    if (strcmp(linenumber, "firstname") == 0) {
        line_number = 1;
    } else if (strcmp(linenumber, "surname") == 0) {
        line_number = 2;
    } else if (strcmp(linenumber, "dob") == 0) {
        line_number = 3;
    } else if (strcmp(linenumber, "totalguests") == 0) {
        line_number = 4;
    } else if (strcmp(linenumber, "totaladults") == 0) {
        line_number = 5;
    } else if (strcmp(linenumber, "totalkids") == 0) {
        line_number = 6;
    } else if (strcmp(linenumber, "boardtype") == 0) {
        line_number = 7;
    } else if (strcmp(linenumber, "newspaper") == 0) {
        line_number = 8;
    } else if (strcmp(linenumber, "roomnumber") == 0) {
        line_number = 9;
    } else if (strcmp(linenumber, "lengthofstay") == 0) {
        line_number = 10;
    } else if (strcmp(linenumber, "roomcost") == 0) {
        line_number = 11;
    } else {
        printf("Invalid linenumber: %s\n", linenumber);
        return "";
    }
    char txtfile[255];
    sprintf(txtfile, "./storage/%s.txt", booking_id);

    FILE *file = fopen(txtfile, "r");
    if (file == NULL) {
        printf("Booking ID not found: %s\n", booking_id);
        return "";
    }
    int counter = 0;
    while (fgets(line, sizeof(line), file)) {
        if (counter == line_number) {
            return line;
        }
        counter++;
    }


}


void check_in() {
    char first_name[255], surname[255], dob[255], board_type[255], daily_newspaper[255], txtfile[255];
    int num_guests = 0, num_adults = 0, num_children = 0, length_of_stay = 0, room_choice = 0;
    int board_cost = 0, room_rate = 0, total_cost = 0, room_cost = 0, total_board_cost = 0;

    printf("Firstname: ");
    scanf("%s", first_name);
    printf("Surname: ");
    scanf("%s", surname);
    printf("DOB: ");
    scanf("%s", dob);

    printf("Amount of guests (max of 4): ");
    scanf("%d", &num_guests);
    if (num_guests > 4) {
        char* insult = randominsult();
        printf("can you not count you %s\n", insult);
        return;
    }
    printf("Amount of adults: ");
    scanf("%d", &num_adults);
    num_children = num_guests - num_adults;
    if (num_children < 0) {
        char* insult = randominsult();
        printf("can you not do basic addition of adults and children you %s\n", insult);
        return;
    }

    printf("Enter board (FB, HB, BB): ");
    scanf("%s", board_type);
    if (strcmp(board_type, "FB") == 0) {
        board_cost = 20;
    } else if (strcmp(board_type, "HB") == 0) {
        board_cost = 15;
    } else if (strcmp(board_type, "BB") == 0) {
        board_cost = 5;
    } else {
        char* insult = randominsult();
        printf("can you not read it was FB HB or BB you %s\n", insult);
        return;
    }

    printf("Stay length (days): ");
    scanf("%d", &length_of_stay);

    printf("Newpaper (1= yes | 0 = no): ");
    scanf("%s", daily_newspaper);

    printf("\nAvailable rooms and their rates (per room, per day):\n");
    printf("1. Room 1 | 2.Room 2 | 3. Room 3 | 4. Room 4 | 5. Room 5 | 6. Room 6\n");
    printf("Room: ");
    scanf("%d", &room_choice);

    switch (room_choice) {
        case 1:
        case 2:
            room_rate = 100;
            break;
        case 3:
            room_rate = 85;
            break;
        case 4:
        case 5:
            room_rate = 75;
            break;
        case 6:
            room_rate = 50;
            break;
        default:
            char* insult = randominsult();
            printf("it was an option what did you do you %s :(\n", insult);
            return;
    }

    char booking_id[255];
    generate_booking_id(surname, booking_id);

    room_cost = room_rate * length_of_stay;
    total_board_cost = board_cost * num_guests * length_of_stay;
    total_cost = room_cost + total_board_cost;

    sprintf(txtfile, "./storage/%s.txt", booking_id);

    printf("%s\n", txtfile);

    FILE *file = fopen(txtfile, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(file, "%s \n", booking_id);
    fprintf(file, "%s \n", first_name);
    fprintf(file, "%s \n", surname);
    fprintf(file, "%s \n", dob);
    fprintf(file, "%d \n", num_guests);
    fprintf(file, "%d \n", num_adults);
    fprintf(file, "%d \n", num_children);
    fprintf(file, "%s \n", board_type);
    fprintf(file, "%s \n", daily_newspaper);
    fprintf(file, "%d \n", room_choice);
    fprintf(file, "%d \n", length_of_stay);
    fprintf(file, "%d \n", room_cost);
    fclose(file);

    printf("Booking id: %s\n", booking_id);

}