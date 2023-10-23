#include <iostream>
#include "../des/initial_permutation.hpp"
#include "../des/final_permutation.hpp"
#include "../des/key_scheduler.hpp"
#include "../des/f_function.hpp"
#include "../des/encrypt.hpp"
#include "../des/permutations.hpp"

std::bitset<64> encryptDES(std::bitset<64> data, std::bitset<64> originalKey) {
    std::cout << "data: " << data;
    data = initialPermutation(data);
    std::cout << "--IP-->" << data << std::endl;
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

    std::cout << "data: " << encryptedData;
    encryptedData = finalPermutation(encryptedData);
    std::cout << "--IP-->" << encryptedData << std::endl;

    // std::bitset<64> permutedData;
    // for (int i = 0; i < 64; ++i) {
    //     permutedData[i] = encryptedData[finalPermutationTable[i] - 1];
    // }
    
    return encryptedData;
}