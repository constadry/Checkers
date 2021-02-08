//
// Created by behap on 07.02.2021.
//

#include <iostream>
#include <set>

struct Checker {
    int row;
    int column;
};

int bad_value(int x, int y) {
    if (x > 7 || x < 0 || y > 7 || y < 0) {
        return 1;
    } else {
        return 0;
    }
}

int empty_field(int oneField) {
    return oneField;
}

int is_other_color(int oneField, int color) {
    if (oneField == 0) {
        return 1;
    } else {
        return oneField != color;
    }
}

void check_warrior(int &flagV, int i, int ci, int j, int cj, int field[][8], int color,  std::set< std::pair<int, int> > &trigger_checkers) {
    if (!bad_value(i + ci, j + cj) && empty_field(field[i + ci][j + cj])) {
        if(is_other_color(field[i + ci][j + cj], color)) {
            if (!bad_value(i + 2*ci, j + 2*cj) && !empty_field(field[i + 2*ci][j + 2*cj])) {
                trigger_checkers.insert(std::make_pair(i, j));
                flagV = 1;
            }
        }
    }
}

void check_warrior(int i, int ci, int j, int cj, int field[][8], int color,  std::set< std::pair<int, int> > &trigger_checkers) {
    if (!bad_value(i + ci, j + cj) && empty_field(field[i + ci][j + cj])) {
        if(is_other_color(field[i + ci][j + cj], color)) {
            if (!bad_value(i + 2*ci, j + 2*cj) && !empty_field(field[i + 2*ci][j + 2*cj])) {
                trigger_checkers.insert(std::make_pair(i + 2*ci, j + 2*cj));
            }
        }
    }
}

void trigger_check(int field[][8], int color, std::set< std::pair<int, int> > &trigger_checkers, int &flagV) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (is_other_color(field[i][j], color)) {
                continue;
            }
            check_warrior(flagV, i, -1, j, -1, field, color, trigger_checkers);
            check_warrior(flagV, i, -1, j, 1, field, color, trigger_checkers);
            check_warrior(flagV, i, 1, j, -1, field, color, trigger_checkers);
            check_warrior(flagV, i, 1, j, 1, field, color, trigger_checkers);
        }
    }
}

int near_all(int x, int y, int field[][8], int color) {
    int k = 2;
    if (color == 1) {
        if (!bad_value(x - 1, y - 1)) {
            if (empty_field(field[x-1][y-1])) {
                --k;
            }
        } else {
            --k;
        }
        if (!bad_value(x - 1, y + 1)) {
            if (empty_field(field[x-1][y+1])) {
                --k;
            }
        } else {
            --k;
        }
    } else {
        if (!bad_value(x + 1, y - 1)) {
            if (empty_field(field[x+1][y-1])) {
                --k;
            }
        } else {
            --k;
        }
        if (!bad_value(x + 1, y + 1)) {
            if (empty_field(field[x+1][y+1])) {
                --k;
            }
        } else {
            --k;
        }
    }
    return k;
}

int choose_checker(Checker &checker, int field[][8], int color) {
    std::set<std::pair<int, int>> trigger_checkers;
    int flagV = 0;
    trigger_check(field, color, trigger_checkers, flagV);
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
    return flagV;
}

int access_move(Checker checker, Checker toField, int color) {
    if (color == 1) {
        if (toField.row == checker.row - 1 && (toField.column == checker.column + 1 || toField.column == checker.column - 1)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (toField.row == checker.row + 1 && (toField.column == checker.column + 1 || toField.column == checker.column - 1)) {
            return 1;
        } else {
            return 0;
        }
    }
}

void moving(Checker &checker, int field[][8], int color) {
    int flagVar = choose_checker(checker, field, color);
    Checker toField{};

    std::set<std::pair<int, int>> warriorsValid;

    if (flagVar) {
        check_warrior(checker.row, -1, checker.column, -1, field, color, warriorsValid);
        check_warrior(checker.row, -1, checker.column, 1, field, color, warriorsValid);
        check_warrior(checker.row, 1, checker.column, -1, field, color, warriorsValid);
        check_warrior(checker.row, 1, checker.column, 1, field, color, warriorsValid);
    }

    while (true) {
        std::cout << "Inter a field to move: \n";
        std::cin >> toField.row >> toField.column;
        if (flagVar) {
            if(warriorsValid.count(std::make_pair(toField.row, toField.column))) {
                field[toField.row][toField.column] = color;
                int diffRow = toField.row - checker.row;
                diffRow /= abs(diffRow);
                int diffCol = toField.column - checker.column;
                diffCol /= abs(diffCol);
                field[checker.row][checker.column] = 0;
                field[checker.row + diffRow][checker.column + diffCol] = 0;
                break;
            } else {
                std::cout << "Incorrect field to move: \n";
            }
        } else {
            if (access_move(checker, toField, color)) {
                if (!empty_field(field[toField.row][toField.column]) && !bad_value(toField.row, toField.column) && is_other_color(field[toField.row][toField.column], color))  {
                    field[toField.row][toField.column] = color;
                    field[checker.row][checker.column] = 0;
                    break;
                }
            } else {
                std::cout << "Incorrect field to move: \n";
            }
        }

    }
}