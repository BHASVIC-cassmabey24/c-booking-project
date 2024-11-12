#include <stdio.h>
#include <unistd.h>//sleep used to make pauses between actions: to be turned on end of testing
#include "common.h"

void book_table() {
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

    printf("\nPlease enter your given booking ID:");
    fflush(stdin);
    scanf("%s",&ID);

    int check =check_booking_id(ID);

    //Goes to check stored booking = real booking
    if (check == 1) {
        printf("\nY");
    }
    else{
        printf("\nN");

    }

}