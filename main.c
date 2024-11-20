#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>

#include "common.h"
//#include "check_out.c"
//#include "book_table.c"

int main() {
    int choice;
    setbuf(stdout, NULL);

    while (1) {
        printf("\n Choose: \n");
        printf("1. check in\n");
        printf("2. book table\n");
        printf("3. check out\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
//
        switch (choice) {
            case 1:
                check_in();
                break;
            case 2:
                //book_table();
                break;
            case 3:
                //check_out();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}