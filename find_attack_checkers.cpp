//
// Created by behap on 08.02.2021.
//

#include "moving_header.h"

void check_warrior_move(int i, int ci, int j, int cj, int field[][8], int color,  std::set< std::pair<int, int> > &trigger_checkers) {
    //Получение массива полей, куда надо ходить
    if (!bad_value(i + ci, j + cj) && empty_field(field[i + ci][j + cj])) {
        if(is_other_color(field[i + ci][j + cj], color)) {
            if (!bad_value(i + 2*ci, j + 2*cj) && !empty_field(field[i + 2*ci][j + 2*cj])) {
                trigger_checkers.insert(std::make_pair(i + 2*ci, j + 2*cj));
            }
        }
    }
}

void check_warrior_choose(int i, int ci, int j, int cj, int field[][8], int color,  std::set< std::pair<int, int> > &trigger_checkers) {
    //Получение массива шашек, которыми надо ходить
    if (!bad_value(i + ci, j + cj) && empty_field(field[i + ci][j + cj])) {
        if(is_other_color(field[i + ci][j + cj], color)) {
            if (!bad_value(i + 2*ci, j + 2*cj) && !empty_field(field[i + 2*ci][j + 2*cj])) {
                trigger_checkers.insert(std::make_pair(i, j));
            }
        }
    }
}

void trigger_check(int field[][8], int color, std::set< std::pair<int, int> > &trigger_checkers) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (is_other_color(field[i][j], color)) {
                continue;
            }
            check_warrior_choose(i, -1, j, -1, field, color, trigger_checkers);
            check_warrior_choose(i, -1, j, 1, field, color, trigger_checkers);
            check_warrior_choose(i, 1, j, -1, field, color, trigger_checkers);
            check_warrior_choose(i, 1, j, 1, field, color, trigger_checkers);
        }
    }
}