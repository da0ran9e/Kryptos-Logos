#include <bits/stdc++.h>
#include "../des/permuted_choice.hpp"
#include "../des/left_shift.hpp"
#include "../des/key_scheduler.hpp"
using namespace std;

vector<bitset<48>> generateSubKeys(const bitset<64>& key) {

    vector<bitset<48>> subKeys;
    bitset<56> permutedKey = permuted_choice_1(key);

    bitset<28> C0, D0;

    for (int i = 0; i < 28; i++) {
        C0[i] = permutedKey[i + 28];
        D0[i] = permutedKey[i];
    }

    for (int i = 0; i < 16; i++) {
        C0 = left_shift(C0, 1);  // Dịch bit trái C0 và D0
        D0 = left_shift(D0, 1);

        bitset<56> shiftedKey;
        for (int j = 0; j < 28; j++) {
            shiftedKey[j] = D0[j];
            shiftedKey[j + 28] = C0[j];
        }
        
        subKeys.push_back(permuted_choice_2(shiftedKey));
    }

    return subKeys;
}