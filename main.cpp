#include "header.h"

int main() {
    int field[8][8];
    fill_field(field);
    int counter = 1;
    int color;
    show_field(field);
    while (true) {
        if (counter % 2) {
            color = 1;
        } else {
            color = 2;
        }
        ++counter;
        Checker checker{};
        moving(checker, field, color);
        show_field(field);

        if (game_over(field)) {
            break;
        }
    }

    return 0;
}
