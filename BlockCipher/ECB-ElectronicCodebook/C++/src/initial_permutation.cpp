#include "../cbc/initial_permutation.hpp"
#include "../cbc/permutations.hpp"

// Function to perform Initial Permutation (IP)
std::bitset<64> initialPermutation(std::bitset<64> data) {
    std::bitset<64> permutedData;
    for (int i = 0; i < 64; ++i) {
        permutedData[i] = data[initialPermutationTable[i] - 1];
    }
    //std::cout << "IP: \t\t\t\t" << permutedData << std::endl;
    return permutedData;
}