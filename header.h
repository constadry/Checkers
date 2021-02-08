//
// Created by behap on 07.02.2021.
//

#ifndef CHECKERS_HEADER_H
#define CHECKERS_HEADER_H

struct Checker {
    int row;
    int column;
};

void fill_field(int [][8]);
void show_field(int [][8]);
void choose_checker(Checker &, int [][8], int);
void moving(Checker &, int [][8], int);
int game_over(int [][8]);

#endif //CHECKERS_HEADER_H
