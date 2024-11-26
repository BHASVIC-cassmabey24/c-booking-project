//
// Created by Lordn on 12/11/2024.
//
#include<stdbool.h>
#ifndef COMMON_H
#define COMMON_H
// by including common.c in every file we get a redefinition error
// to combat this include common.h which will contain the declarations

void generatebooking_id(char surname[], char booking_id[]);

int has_numbers(char string[255]);

int validate_board(char board[]);

void create_directory(char *directory);

int get_firstname(const char *booking_id);

//Table booking:
void book_table();

bool Incorrect_ID();

bool Incorrect_Booking();

int random_number();

void Fill_Table(int R);

void check_in();
int check_booking_id(char* booking_id);
char* get_info(char* booking_id, int linenumber);

#endif //COMMON_H
