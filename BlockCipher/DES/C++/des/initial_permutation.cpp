#include "../des/initial_permutation.hpp"
#include "../des/permutations.hpp"

// Function to perform Initial Permutation (IP)
std::bitset<64> initialPermutation(std::bitset<64> data) {
    std::bitset<64> permutedData;
    for (int i = 0; i < 64; ++i) {
        permutedData[i] = data[initialPermutationTable[i] - 1];
    }
    return permutedData;
}