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
        bool book =true;
        //char BoardType[]="boardtype";
        const char ID[256];
        int table;
        int time;
        char cont;
        char try;
        //char *line=get_info(ID,BoardType);

        Fill_Table(random);
        while (book =true) {
            printf("\n \n| Booking Register |");
            printf("\n-------------------           Here are the three tables with their appropriate times");

            sleep(2);
            printf("\n1.Naboo   7pm:   9pm:           A (1) below means it is booked already while a (0) means available\n");
            printf("         %d      %d\n",bookings[1][0],bookings[1][1]);

            printf("2.Endor   7pm:   9pm:\n");
            printf("         %d      %d\n",bookings[2][0],bookings[1][1]);

            printf("3.Tatooine 7pm:   9pm:\n");
            printf("         %d      %d\n",bookings[3][0],bookings[3][1]);

            printf("Please enter which table you would like to book: (1 or 2 or 3)");
            scanf("%d",&table);
            fflush(stdin);

            printf("please enter which time you would like 7 or 9");
            scanf("%d",&time);
            fflush(stdin);

            if (table==3 || table==2 ||table==2 ||time==9 || time==7) {
                if (table==1 && time==7) {
                    if (bookings[1][0]==1) {
                        printf("\nTable already booked");
                        sleep(2);
                    }
                    else {
                        bookings[1][0]==1;
                        printf("Table at Naboo for %d booked!",time);
                        book =false;

                    }
                }
                if (table==1 && time==9) {
                    if (bookings[1][1]==1) {
                        printf("\nTable already booked");
                        sleep(2);
                    }
                    else {
                        bookings[1][1]==1;
                        printf("Table at Naboo for %d booked!",time);
                        book =false;

                    }
                }
                if (table==2 && time==7) {
                    if (bookings[2][0]==1) {
                        printf("\nTable already booked");
                        sleep(2);
                    }
                    else {
                        bookings[2][0]==1;
                        printf("Table at Endor for %d booked!",time);
                        book =false;

                    }
                }
                if (table==2 && time==9) {
                    if (bookings[2][1]==1) {
                        printf("\nTable already booked");
                        sleep(2);
                    }
                    else {
                        bookings[2][1]==1;
                        printf("Table at Endor for %d booked!",time);
                        book =false;

                    }
                }
                if (table==3 && time==7) {
                    if (bookings[3][0]==1) {
                        printf("\nTable already booked");
                        sleep(2);
                    }
                    else {
                        bookings[3][0]==1;
                        printf("Table at tatooine for %d booked!",time);
                        book =false;

                    }
                }
                if (table==3 && time==9) {
                    if (bookings[3][1]==1) {
                        printf("\nTable already booked");
                        sleep(2);
                    }
                    else {
                        bookings[3][1]==1;
                        printf("Table at Tatooine for %d booked!",time);
                        book =false;

                    }
                }
            }
            else{
                printf("\n Incorrect input");
                printf("\n try again? (y/n)");
                scanf("%s",&try);
                if (try == 'n' || try == 'N') {
                    book =false;
                    break;
                }

            }
        }
            printf("\n.");
            //sleep(1.2);
            printf("\n.");
            //sleep(1.2);
            printf("\n.");
            //sleep(1.2);
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

            }




    }
}

