#include "../des/permute.hpp"
#include "../des/expand.hpp"
#include "../des/substitution.hpp"
#include "../des/f_function.hpp"
#include "../des/permutations.hpp"

// Function to perform the f function
std::bitset<32> f(std::bitset<32> rightHalf, std::bitset<48> roundKey) {
    // Expansion
    std::bitset<48> expandedData = expand(rightHalf);

    // XOR with round key
    expandedData ^= roundKey;

    // S-box substitution
    std::bitset<32> substitutedData = sBoxSubstitution(expandedData);

    // Permutation
    std::bitset<32> permutedData = permute(substitutedData);

    return permutedData;
}