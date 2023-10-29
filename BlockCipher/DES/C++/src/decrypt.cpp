#include "../des/final_permutation.hpp"
#include "../des/initial_permutation.hpp"
#include "../des/key_scheduler.hpp"
#include "../des/f_function.hpp"
#include "../des/decrypt.hpp"
#include "../des/permutations.hpp"

std::bitset<64> decryptDES(std::bitset<64> data, std::bitset<64> originalKey) {
    //FP
    data = finalPermutation(data);
    // Generate keys
    std::bitset<48> subKeys[16];
    generate_subkeys(originalKey, subKeys);

    // Split data
    std::bitset<32> leftHalf, rightHalf;
    for (int i = 0; i < 32; ++i) {
        leftHalf[i] = data[i];
        rightHalf[i] = data[i + 32];
    }

    // Decrypt 16 round
    for (int round = 15; round >= 0; --round) {
        std::bitset<32> tempRight = rightHalf;
        rightHalf = leftHalf ^ f(rightHalf, subKeys[round]);
        leftHalf = tempRight;
    }

    // Assemble 2 halves
    std::bitset<64> decryptedData;
    for (int i = 0; i < 32; ++i) {
        decryptedData[i] = rightHalf[i];
        decryptedData[i + 32] = leftHalf[i];
    }
    //IP
    decryptedData = initialPermutation(decryptedData);

    return decryptedData;
}