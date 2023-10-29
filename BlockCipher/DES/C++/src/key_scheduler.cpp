#include "../des/permuted_choice.hpp"
#include "../des/left_shift.hpp"
#include "../des/key_scheduler.hpp"
#include "../des/permutations.hpp"

void generate_subkeys(const std::bitset<64>& key, std::bitset<48> subKeys[16]) {
    std::bitset<56> permutedKey = permuted_choice_1(key);
    // Split the 56-bit key into two 28-bit halves
    std::bitset<28> leftHalf, rightHalf;
    for (int i = 0; i < 28; ++i) {
        leftHalf[i] = permutedKey[i];
        rightHalf[i] = permutedKey[i + 28];
    }

    for (int round = 0; round < 16; ++round) {
        // Perform left shift on both halves
        leftHalf = left_shift(leftHalf, shiftBits[round]);
        rightHalf = left_shift(rightHalf, shiftBits[round]);

        // Combine the two halves
        std::bitset<56> combinedKey;
        for (int i = 0; i < 28; ++i) {
            combinedKey[i] = leftHalf[i];
            combinedKey[i + 28] = rightHalf[i];
        }

        // Apply PC2 to the combined key to get the 48-bit round key
        
        subKeys[round] = permuted_choice_2(combinedKey);
        
    }
}