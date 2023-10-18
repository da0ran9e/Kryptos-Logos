#include "../des/initial_permutation.hpp"
#include "../des/permutations.hpp"

std::bitset<64> finalPermutation(std::bitset<64> data) {
    std::bitset<64> permutedData;
    for (int i = 0; i < 64; ++i) {
        permutedData[i] = data[finalPermutationTable[i] - 1];
    }
    return permutedData;
}