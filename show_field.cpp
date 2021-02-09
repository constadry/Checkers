//
// Created by behap on 07.02.2021.
//

#include <iostream>

void show_field(int field[][8]) {
    for (int i = 0; i < 8; ++i) {
        std::cout << i << "  ";
        for (int j = 0; j < 8; ++j) {
            std::cout << field[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "   ";
    for (int i = 0; i < 8; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}