//
// Created by behap on 08.02.2021.
//

#ifndef CHECKERS_MOVING_HEADER_H
#define CHECKERS_MOVING_HEADER_H

#include <iostream>
#include <set>

struct Checker {
    int row;
    int column;
};

int bad_value(int , int );
int empty_field(int );
int is_other_color(int , int );
int near_all(int , int , int [][8], int );
int access_move(int , int , int , int , int );
void trigger_check(int [][8], int , std::set< std::pair<int, int> > &);
void check_warrior_move(int , int , int , int , int [][8], int ,  std::set< std::pair<int, int> > &);
void check_warrior_choose(int , int , int , int , int [][8], int ,  std::set< std::pair<int, int> > &);

#endif //CHECKERS_MOVING_HEADER_H
