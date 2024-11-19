#include <stdio.h>
#include <unistd.h>//sleep used to make pauses between actions: to be turned on end of testing
#include "common.h"
#include <stdbool.h>
#include <stdlib.h>
#include "Globals.h"
bool Start =true;

void book_table() {
    int random =random_number();
    while (Start) {
        bool checkID = true;
        bool check_Board = true;
        const char ID[256];



        printf("\n.");
        //sleep(1.2);
        printf("\n.");
        //sleep(1.2);
        printf("\n.");
        //sleep(1.2);
        printf("\n--------------");
        printf("\nBooking table:");
        printf("\n--------------\n");

        //booking id check
        printf("\nPlease enter your given booking ID:");
        fflush(stdin);
        scanf("%s",&ID);
        // way to access booking ID required: going to carry on coding assuming i have it/dont
        printf("\n \n Checking booking ID...");
        sleep(2);
        if (checkID == false) {

            Start=Incorrect_ID();
        }
        else;
        printf("\n Correct Booking ID...");

        printf("\n \n Checking board type...");
        sleep(2);
        if (check_Board == false) {
            Start=Incorrect_Booking();
        }
        else {
            printf("\n Correct board type...");
            sleep(2);
            Start =false;
        }
    }

    Fill_Table(random);
    for (int i = 0; i < 2; i++) {
        printf("\n");
        for (int j = 0; j < 4; j++) {
            printf("%d ", bookings[i][j]);


        }
    }
}