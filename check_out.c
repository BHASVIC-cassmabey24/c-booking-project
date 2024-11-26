#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"



void check_out() {
    printf("Checking out...\n");
    fflush(stdin);

    double totalcost = 0;
    char bookingid[255];

    printf("Enter booking ID: ");
    scanf("%s", bookingid);

    char* firstname = get_info(bookingid, 1);
    char* surname = get_info(bookingid, 2);
    char* totalguests_str = get_info(bookingid, 4);
    int totalguests = atoi(totalguests_str);

    char* roomnumberstr = get_info(bookingid, 9);
    int roomnumber = atoi(roomnumberstr);
    switch(roomnumber) {
        case 1:
        case 2:
            totalcost += 100;
            printf("You ordered room 1 or 2: £100\n");
            break;
        case 3:
            totalcost += 85;
            printf("You ordered room 3: £85\n");
            break;
        case 4:
        case 5:
            totalcost += 75;
            printf("You ordered room 4 or 5: £75\n");
            break;
        case 6:
            totalcost += 50;
            printf("You ordered room 6: £50\n");
            break;
        default:
            printf("Weird, your room number is: %d\n", roomnumber);
            break;
    }

    char* board_type = get_info(bookingid, 7);
    printf("Board Type: %s\n", board_type);

    int board_cost_per_person = 0;
    if (strcmp(board_type, "FB") == 0) {
        board_cost_per_person = 20;
    } else if (strcmp(board_type, "HB") == 0) {
        board_cost_per_person = 15;
    } else if (strcmp(board_type, "BB") == 0) {
        board_cost_per_person = 5;
    } else {
        printf("Invalid board type.\n");
        return;
    }

    char* totaladults_str = get_info(bookingid, 5);
    char* totalkids_str = get_info(bookingid, 6);
    int totaladults = atoi(totaladults_str);
    int totalkids = atoi(totalkids_str);

    int total_board_cost = (totaladults + totalkids * 0.5) * board_cost_per_person;
    totalcost += total_board_cost;

    char* newspaper = get_info(bookingid, 8);
    if (strcmp(newspaper, "1") == 0) {
        totalcost += 5.50;
    }

    char* dob_str = get_info(bookingid, 3);
    int dob = atoi(dob_str);
    int current_year = 2024;
    if (current_year - dob > 65) {
        totalcost *= 0.9;
    }

    // Print the final bill
    printf("\n_-_-_-_- Bill -_-_-_-_\n");
    printf("Booking ID: %s\n", bookingid);
    printf("Name: %s %s\n", firstname, surname);
    printf("Total Guests: %d\n", totalguests);
    printf("Room Cost: £%d\n", totalcost);
    printf("Board Cost: £%d\n", total_board_cost);
    if (strcmp(newspaper, "1") == 0) {
        printf("Newspaper: £5.50\n");
    }
    if (current_year - dob > 65) {
        printf("Senior Discount (10%%): -£%.2f\n", totalcost * 0.1);
    }
    printf("Total: £%.2f\n", totalcost);

    printf("\nCheck-out complete.\n");
}
