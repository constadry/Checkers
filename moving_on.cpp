//
// Created by behap on 07.02.2021.
//

#include "moving_header.h"

void choose_checker(Checker &checker, int field[][8], int color) {
    std::set<std::pair<int, int>> trigger_checkers;
    trigger_check(field, color, trigger_checkers);
    std::cout << "Choose a checker: \n" << "Inter a row, next a column\n";
    std::cin >> checker.row >> checker.column;

    int x, y;

    if (trigger_checkers.empty()) {
        while (true) {
            x = checker.row, y = checker.column;
            if (bad_value(x, y) || !empty_field(field[x][y]) || !near_all(x, y, field, color) || is_other_color(field[x][y], color)) {
                std::cout << "Choose a checker: \n" << "Inter an other row, next a column\n";
                std::cin >> checker.row >> checker.column;
            } else {
                break;
            }
        }
    } else {
        while (true) {
            x = checker.row, y = checker.column;
            if (trigger_checkers.count(std::make_pair(x, y))) {
                break;
            } else {
                std::cout << "Choose a checker: \n" << "Inter an other row, next a column\n";
                std::cin >> checker.row >> checker.column;
            }
        }
    }
}

//void attack(int x, int y, int mx, int my, int color, int field[][8]) {
//
//}

void moving(Checker &checker, int field[][8], int color) {
    choose_checker(checker, field, color);
    Checker toField{};

    std::set<std::pair<int, int>> warriorsValid;

    int x = checker.row;
    int y = checker.column;

    check_warrior_move(x, -1, y, -1, field, color, warriorsValid);
    check_warrior_move(x, -1, y, 1, field, color, warriorsValid);
    check_warrior_move(x, 1, y, -1, field, color, warriorsValid);
    check_warrior_move(x, 1, y, 1, field, color, warriorsValid);

    int mx, my;

    if (!warriorsValid.empty()) {
        while (true) {
            std::cout << "Inter a field to move: \n";
            std::cin >> toField.row >> toField.column;
            mx = toField.row;
            my = toField.column;
            if (warriorsValid.count(std::make_pair(mx, my))) {
                field[mx][my] = color;
                int diffRow = mx - x;
                diffRow /= abs(diffRow);
                int diffCol = my - y;
                diffCol /= abs(diffCol);
                field[x][y] = 0;
                field[x + diffRow][y + diffCol] = 0;
                x = mx;
                y = my;
                warriorsValid.clear();
                check_warrior_move(x, -1, y, -1, field, color, warriorsValid);
                check_warrior_move(x, -1, y, 1, field, color, warriorsValid);
                check_warrior_move(x, 1, y, -1, field, color, warriorsValid);
                check_warrior_move(x, 1, y, 1, field, color, warriorsValid);
                if (warriorsValid.empty()) {
                    break;
                }
                std::cout << "Attack again!\n";
            } else {
                std::cout << "Incorrect field to move: \n";
            }
        }
    } else {
        while (true) {
            std::cout << "Inter a field to move: \n";
            std::cin >> toField.row >> toField.column;
            mx = toField.row;
            my = toField.column;
            if (access_move(x, y, mx, my, color)) {
                if (!bad_value(mx, my) && !empty_field(field[mx][my])) {
                    field[mx][my] = color;
                    field[x][y] = 0;
                    break;
                }
            } else {
                std::cout << "Incorrect field to move: \n";
            }
        }
    }
}