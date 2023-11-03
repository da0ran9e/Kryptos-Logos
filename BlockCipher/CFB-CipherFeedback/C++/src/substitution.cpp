#include "../cbc/substitution.hpp"
#include "../cbc/permutations.hpp"

// Function to perform S-box substitution
std::bitset<32> sBoxSubstitution(std::bitset<48> data) {
    std::bitset<32> substitutedData;
    int bitPos = 0;
    for (int i = 0; i < 8; ++i) {
        int row = data[bitPos] * 2 + data[bitPos + 5];
        int col = (data[bitPos + 1] << 3) + (data[bitPos + 2] << 2) + (data[bitPos + 3] << 1) + data[bitPos + 4];
        int sBoxValue = SBox[i][row][col];
        std::bitset<4> sBoxBits(sBoxValue);
        for (int j = 0; j < 4; ++j) {
            substitutedData[4 * i + j] = sBoxBits[j];
        }
        bitPos += 6;
    }
    return substitutedData;
}