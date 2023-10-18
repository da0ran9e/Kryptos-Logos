#include <bits/stdc++.h>
#include "../des/permuted_choice.hpp"
#include "../des/permutations.hpp"
using namespace std;

// Hàm hoán vị PC-1
bitset<56> permuted_choice_1(const bitset<64>& key) {
    bitset<56> permutedKey;
    for (int i = 0; i < 56; i++) {
        permutedKey[55 - i] = key[64 - PC1[i]];
    }
    return permutedKey;
}

// Hàm hoán vị PC-2
bitset<48> permuted_choice_2(const bitset<56>& key) {
    bitset<48> permutedKey;
    for (int i = 0; i < 48; i++) {
        permutedKey[47 - i] = key[56 - PC2[i]];
    }
    return permutedKey;
}
