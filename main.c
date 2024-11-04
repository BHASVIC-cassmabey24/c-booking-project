#include <stdio.h>
#include "check_in.c"
#include "check_out.c"
#include "book_table.c"


void create_new_guest() {
    FILE *fptr;

    // Create a file
    fptr = fopen("idkcustomers\\", "w");

    // Close the file
    fclose(fptr);
}


int main(void) {
    int choice;
    printf("Please enter what you would like to do: \n\n");
    printf("\t1. Check In\n");
    printf("\t2. Check Out\n");
    printf("\t3. Book Table\n\n");
    printf("> ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            check_in();
        break;
        case 2:
            check_out();
        break;
        case 3:
            book_table();
        break;
        default:
            printf("Invalid input.");
        break;
    }


}
