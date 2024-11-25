#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"



void check_out() {
    printf("Checking out...\n");
    fflush(stdin);
    char bookingid[255];

    printf("Enter you booking ID:");
    scanf("%s",&bookingid);
    if (get_info(bookingid, "bookingid") == "") {
        printf("Invalid booking id");
    } else {
        char* birthyear = get_info(bookingid,"dob");
        printf("%s",birthyear);
    }
    char* newspaper = get_info(bookingid,"newspaper");






}