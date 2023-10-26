#include "../cbc/permuted_choice.hpp"
#include "../cbc/left_shift.hpp"
#include "../cbc/key_scheduler.hpp"
#include "../cbc/permutations.hpp"
using namespace std;

void generate_subkeys(const bitset<64>& key, bitset<48> subKeys[16]) {
    bitset<56> permutedKey = permuted_choice_1(key);
    // Split the 56-bit key into two 28-bit halves
    bitset<28> leftHalf, rightHalf;
    for (int i = 0; i < 28; ++i) {
        leftHalf[i] = permutedKey[i];
        rightHalf[i] = permutedKey[i + 28];
    }

    for (int round = 0; round < 16; ++round) {
        // Perform left shift on both halves
        leftHalf = left_shift(leftHalf, shiftBits[round]);
        rightHalf = left_shift(rightHalf, shiftBits[round]);

        // Combine the two halves
        bitset<56> combinedKey;
        for (int i = 0; i < 28; ++i) {
            combinedKey[i] = leftHalf[i];
            combinedKey[i + 28] = rightHalf[i];
        }

        // Apply PC2 to the combined key to get the 48-bit round key
        
        subKeys[round] = permuted_choice_2(combinedKey);
        
    }
}