#include "../des/permute.hpp"
#include "../des/permutations.hpp"

// Function to perform permutation
std::bitset<32> permute(std::bitset<32> data) {
    std::bitset<32> permutedData;
    for (int i = 0; i < 32; ++i) {
        permutedData[i] = data[permutationTable[i] - 1];
    }
    return permutedData;
}