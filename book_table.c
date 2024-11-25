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
        printf("\n.");
        printf("\n.");
        printf("\n.");
        printf("\n--------------");
        printf("\nBooking table:");
        printf("\n--------------\n");


        printf("\n\n Please enter your given booking ID:");
        scanf("%s",ID);
        // way to access booking ID required: going to carry on coding assuming i have it/dont
        printf("\n \n Checking booking ID...");
        if (get_info(ID ,"bookingid") == "") {
            printf("Booking id is invalid");
        } else {
            Start = false;
            printf("Booking id is valid");
            printf("\n \n Checking board type...");
            char *line=get_info(ID,"boardtype");
            if (line[0] != 'B') {
                check_Board = true;
            }

            printf("Booking ID is valid :)");
        }




        Fill_Table(random);
        printf("\n \n| Booking Regester |");
        printf("\n -------------------");

        for (int i=0; i<4; i++) {
            printf("\n");
            if (i=1) {
                printf("Naboo:\n");
            }
            if (i=2) {
                printf("Tatooine:\n");
            }
            if (i=3){
                printf("Endor:\n");
            }
            for (int j=0; j<2; j++) {

                if (bookings[i][j] == 0) {
                    printf("Booked");
                }
                else if (bookings[i][j] == 1) {
                    printf("Available");

                }
            }
        }
    }
}