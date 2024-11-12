//
// Created by Lordn on 12/11/2024.
//

#ifndef COMMON_H
#define COMMON_H
// by including common.c in every file we get a redefinition error
// to combat this include common.h which will contain the declarations

void generatebooking_id(char surname[], char booking_id[]);

int has_numbers(char string[255]);

int validate_board(char board[]);

void create_directory(char *directory);

int get_firstname(const char *booking_id);

int check_booking_id(const char *booking_id);

#endif //COMMON_H
