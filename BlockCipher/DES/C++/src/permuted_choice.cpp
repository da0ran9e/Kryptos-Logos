#include <bits/stdc++.h>
#include "../des/permuted_choice.hpp"
#include "../des/permutations.hpp"

// Hàm hoán vị PC-1
std::bitset<56> permuted_choice_1(const std::bitset<64>& key) {
    std::bitset<56> permutedKey;
    for (int i = 0; i < 56; ++i) {
        permutedKey[i] = key[PC1[i] - 1];
    }
    return permutedKey;
}

// Hàm hoán vị PC-2
std::bitset<48> permuted_choice_2(const std::bitset<56>& key) {
    std::bitset<48> permutedKey;
    for (int i = 0; i < 48; ++i) {
        permutedKey[i] = key[PC2[i] - 1];
    }
    return permutedKey;
}
