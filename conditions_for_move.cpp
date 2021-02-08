//
// Created by behap on 08.02.2021.
//

int bad_value(int x, int y) {               // Можно передавать Checker
    //int x = checker.row;
    //int y = checker.column;
    if (x > 7 || x < 0 || y > 7 || y < 0) {
        return 1;
    } else {
        return 0;
    }
}

int empty_field(int oneField) {             // В этой версии реализации можно обойтись !field[x][y]
    return oneField;
}

int is_other_color(int oneField, int color) {        //нужно в каждом месте встречи проверить на пустоту
    if (oneField == 0) {                             //раньше чем на совпадение цвета и заменить на field != color
        return 1;
    } else {
        return oneField != color;
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

int access_move(int x, int y, int mx, int my, int color) {
    if (color == 1) {
        if (mx == x - 1 && (my == y + 1 || my == y - 1)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (mx == x + 1 && (my == y + 1 || my == y - 1)) {
            return 1;
        } else {
            return 0;
        }
    }
}