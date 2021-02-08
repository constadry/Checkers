//
// Created by behap on 07.02.2021.
//

int game_over(int field[][8]) {
    int flagW = 1;
    int flagB = 1;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (field[i][j] == 1) {
                flagW = 0;
            }

            if (field[i][j] == 2) {
                flagB = 0;
            }

            if (flagB + flagW == 0) {
                return 0;
            }
        }
    }
    return 1;
}