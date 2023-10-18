#include <bits/stdc++.h>
#include <bitset>
#include <vector>
using namespace std;

// Hoán vị PC-1
vector<int> PC1 = { 57, 49, 41, 33, 25, 17, 9,
                         1,  58, 50, 42, 34, 26, 18,
                         10, 2,  59, 51, 43, 35, 27,
                         19, 11, 3,  60, 52, 44, 36,
                         63, 55, 47, 39, 31, 23, 15,
                         7,  62, 54, 46, 38, 30, 22,
                         14, 6,  61, 53, 45, 37, 29,
                         21, 13, 5,  28, 20, 12, 4 };

// Hoán vị PC-2
vector<int> PC2 = { 14, 17, 11, 24, 1,  5,
                         3,  28, 15, 6,  21, 10,
                         23, 19, 12, 4,  26, 8,
                         16, 7,  27, 20, 13, 2,
                         41, 52, 31, 37, 47, 55,
                         30, 40, 51, 45, 33, 48,
                         44, 49, 39, 56, 34, 53,
                         46, 42, 50, 36, 29, 32 };

// Hàm hoán vị PC-1
bitset<56> permutePC1(const bitset<64>& key) {
    bitset<56> permutedKey;
    for (int i = 0; i < 56; i++) {
        permutedKey[55 - i] = key[64 - PC1[i]];
    }
    return permutedKey;
}

// Hàm hoán vị PC-2
bitset<48> permutePC2(const bitset<56>& key) {
    bitset<48> permutedKey;
    for (int i = 0; i < 48; i++) {
        permutedKey[47 - i] = key[56 - PC2[i]];
    }
    return permutedKey;
}

// Hàm dịch bit trái
bitset<28> leftShift(const bitset<28>& key, int shift) {
    bitset<28> shiftedKey = (key << shift) | (key >> (28 - shift));
    return shiftedKey;
}

// Hàm sinh khóa con (Key Scheduler)
vector<bitset<48>> generateSubKeys(const bitset<64>& key) {
    vector<bitset<48>> subKeys;
    bitset<56> permutedKey = permutePC1(key);

    bitset<28> C0 = permutedKey >> 28;
    bitset<28> D0 = permutedKey & 0x000000000fffffff;

    for (int i = 0; i < 16; i++) {
        C0 = leftShift(C0, 1);  // Dịch bit trái C0 và D0
        D0 = leftShift(D0, 1);

        bitset<56> shiftedKey = (C0.to_ullong() << 28) | D0.to_ullong();
        subKeys.push_back(permutePC2(shiftedKey));
    }

    return subKeys;
}

int main() {
    bitset<64> key64bits("0001001100110100010101110111100110011011101111001101111111110001");

    vector<bitset<48>> subKeys = generateSubKeys(key64bits);

    for (int i = 0; i < 16; i++) {
        cout << "Subkey " << i + 1 << ": " << subKeys[i] << endl;
    }

    return 0;
}
