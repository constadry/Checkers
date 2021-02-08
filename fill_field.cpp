//
// Created by behap on 07.02.2021.
//

void fill_field(int field[][8]) {
    int i,j;
    for(i = 7; i >= 0; --i) {
        if(i < 3) {
            for (j = 0; j < 8; ++j) {
                field[i][j] = ((i % 2) + (j % 2)) % 2;
                field[i][j] *= 2;
            }
        } else if (i > 4) {
            for (j = 0; j < 8; ++j) {
                field[i][j] = ((i % 2) + (j % 2)) % 2;
            }
        } else {
            for (j = 0; j < 8; ++j) {
                field[i][j] = 0;
            }
        }
    }
}