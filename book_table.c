#include <stdio.h>
#include <unistd.h>//sleep used to make pauses between actions: to be turned on end of testing
#include "common.h"
#include <stdbool.h>
#include <stdlib.h>
#include "Globals.h"
bool Start =true;

void book_table() {
    int random =random_number();
    while (Start == true) {
        int checkID = 0;
        bool check_Board = false;
        char BoardType[]="boardtype";
        const char ID[256];
        char *line=get_info(ID,BoardType);



        printf("\n.");
        //sleep(1.2);
        printf("\n.");
        //sleep(1.2);
        printf("\n.");
        //sleep(1.2);
        printf("\n--------------");
        printf("\nBooking table:");
        printf("\n--------------\n");

        printf("\n \n Checking board type...");
            sleep(2);
            if (line[0] != 'B') {
                check_Board = true;
            }

            if (check_Board == false) {
                Start=Incorrect_Booking();
            }
            else {
                printf("\n Correct board type...");
                sleep(2);
                Start =false;
            }

        //booking id check
        printf("\n\n Please enter your given booking ID:");
        fflush(stdin);
        scanf("%s",&ID);
        // way to access booking ID required: going to carry on coding assuming i have it/dont
        printf("\n \n Checking booking ID...");
        sleep(2);
        checkID =check_booking_id(ID);
        if (checkID != 1) {
            Start=Incorrect_ID();
            if (Start==false) {

            }
            else {
                printf("\n Correct Booking ID...");
            }
        }
        Fill_Table(random);



    }
}