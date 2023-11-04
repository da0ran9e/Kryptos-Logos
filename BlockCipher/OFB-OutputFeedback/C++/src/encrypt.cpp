#include <iostream>
#include "../cbc/initial_permutation.hpp"
#include "../cbc/final_permutation.hpp"
#include "../cbc/key_scheduler.hpp"
#include "../cbc/f_function.hpp"
#include "../cbc/encrypt.hpp"
#include "../cbc/permutations.hpp"

std::bitset<64> encryptDES(std::bitset<64> data, std::bitset<64> originalKey) {
    data = initialPermutation(data);
    // Left half and right half initialization
    std::bitset<32> leftHalf, rightHalf;
    for (int i = 0; i < 32; ++i) {
        leftHalf[i] = data[i];
        rightHalf[i] = data[i + 32];
    }

    // Generate 16 round keys
    std::bitset<48> subKeys[16];
    generate_subkeys(originalKey, subKeys);

    // 16 rounds
    for (int round = 0; round < 16; ++round) {
        std::cout << "L: " << leftHalf << " R: " << rightHalf << " K: " << subKeys[round] << std::endl;

        std::bitset<32> tempRight = rightHalf;
        rightHalf = leftHalf ^ f(rightHalf, subKeys[round]);
        leftHalf = tempRight;
    }

    // Final permutation (FP)
    std::bitset<64> encryptedData;
    for (int i = 0; i < 32; ++i) {
        encryptedData[i] = leftHalf[i];
        encryptedData[i + 32] = rightHalf[i];
    }

    encryptedData = finalPermutation(encryptedData);

    // std::bitset<64> permutedData;
    // for (int i = 0; i < 64; ++i) {
    //     permutedData[i] = encryptedData[finalPermutationTable[i] - 1];
    // }
    
    return encryptedData;
}