#include <bits/stdc++.h>
using namespace std;

const int PC1[56] = {
    57, 49, 41, 33, 25, 17, 9, 1,
    58, 50, 42, 34, 26, 18, 10, 2,
    59, 51, 43, 35, 27, 19, 11, 3,
    60, 52, 44, 36, 63, 55, 47, 39,
    31, 23, 15, 7, 62, 54, 46, 38,
    30, 22, 14, 6, 61, 53, 45, 37,
    29, 21, 13, 5, 28, 20, 12, 4
};

const int PC2[48] = {
    14, 17, 11, 24, 1, 5, 3, 28,
    15, 6, 21, 10, 23, 19, 12, 4,
    26, 8, 16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55, 30, 40,
    51, 45, 33, 48, 44, 49, 39, 56,
    34, 53, 46, 42, 50, 36, 29, 32
};

const int shiftBits[16] = {
    1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

bitset<56> permuted_choice_1(const bitset<64>& key) {
    bitset<56> permutedKey;
    for (int i = 0; i < 56; ++i) {
        permutedKey[i] = key[PC1[i] - 1];
    }
    return permutedKey;
}

bitset<48> permuted_choice_2(const bitset<56>& key) {
    bitset<48> permutedKey;
    for (int i = 0; i < 48; ++i) {
        permutedKey[i] = key[PC2[i] - 1];
    }
    return permutedKey;
}

bitset<28> left_shift(const bitset<28>& key, int shift) {
    bitset<28> data = key;
    for (int i = 0; i < 28; ++i) {
        int newPos = (i + shift) % 28;
        data[newPos] = key[i];
    }
    return data;
}

void generate_subkeys(const bitset<64>& key, bitset<48> subKeys[16]) {
    bitset<56> permutedKey = permuted_choice_1(key);
    // Split the 56-bit key into two 28-bit halves
    bitset<28> leftHalf, rightHalf;
    for (int i = 0; i < 28; ++i) {
        leftHalf[i] = permutedKey[i];
        rightHalf[i] = permutedKey[i + 28];
    }

    for (int round = 0; round < 16; ++round) {
        leftHalf = left_shift(leftHalf, shiftBits[round]);
        rightHalf = left_shift(rightHalf, shiftBits[round]);

        bitset<56> combinedKey;
        for (int i = 0; i < 28; ++i) {
            combinedKey[i] = leftHalf[i];
            combinedKey[i + 28] = rightHalf[i];
        }
        
        subKeys[round] = permuted_choice_2(combinedKey);
        
    }
}

int main(){
    bitset<64> originalKey(0x0123456789ABCDEF);
    bitset<48> subKeys[16];

    generate_subkeys(originalKey, subKeys);

    cout << "Original key: " << originalKey << endl;
    for (int i=0; i<16; i++){
        cout << "[" << i << "] \t subkey: \t"<< subKeys[i] << endl;
    }
    return 0;
}