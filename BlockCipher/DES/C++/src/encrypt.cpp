#include "../des/initial_permutation.hpp"
#include "../des/key_scheduler.hpp"
#include "../des/f_function.hpp"
#include "../des/encrypt.hpp"

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

    return encryptedData;
}