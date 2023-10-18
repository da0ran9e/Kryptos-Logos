#include "../des/expand.hpp"
#include "../des/permutations.hpp"

std::bitset<48> expand(std::bitset<32> data) {
    std::bitset<48> expandedData;
    for (int i = 0; i < 48; ++i) {
        expandedData[i] = data[expansionTable[i] - 1];
    }
    return expandedData;
}