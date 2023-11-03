#include <bitset>
#include <ctime>
#include "../cbc/iv_generator.hpp"

std::bitset<64> generateRandomIV() {
    std::bitset<64> iv;
    srand(time(0)); // get random seed
    for (int i = 0; i < 64; i++) {
        iv[i] = rand() % 2;
    }
    return iv;
}