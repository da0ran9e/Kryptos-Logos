#include <bits/stdc++.h>
using namespace std;

// IP table
const int initialPermutationTable[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

// IP-1 table
const int finalPermutationTable[64] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
};
// PC1
const int PC1[56] = {
    57, 49, 41, 33, 25, 17, 9, 1,
    58, 50, 42, 34, 26, 18, 10, 2,
    59, 51, 43, 35, 27, 19, 11, 3,
    60, 52, 44, 36, 63, 55, 47, 39,
    31, 23, 15, 7, 62, 54, 46, 38,
    30, 22, 14, 6, 61, 53, 45, 37,
    29, 21, 13, 5, 28, 20, 12, 4
};

// PC2
const int PC2[48] = {
    14, 17, 11, 24, 1, 5, 3, 28,
    15, 6, 21, 10, 23, 19, 12, 4,
    26, 8, 16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55, 30, 40,
    51, 45, 33, 48, 44, 49, 39, 56,
    34, 53, 46, 42, 50, 36, 29, 32
};

//shift table
const int shiftBits[16] = {
    1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};
//permutation 
const int permutationTable[32] = {
    16, 7, 20, 21, 29, 12, 28, 17,
    1, 15, 23, 26, 5, 18, 31, 10,
    2, 8, 24, 14, 32, 27, 3, 9,
    19, 13, 30, 6, 22, 11, 4, 25
};
//expansion
const int expansionTable[48] = {
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1
};

// S-boxes
const int SBox[8][4][16] = {
    // S1
    {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    },
    // S2
    {
        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
        {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
        {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
        {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
    },
    // S3
    {
        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
        {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
        {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
        {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
    },
    // S4
    {
        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
    },
    // S5
    {
        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
    },
    // S6
    {
        {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
        {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
        {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
        {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
    },
    // S7
    {
        {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
        {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
        {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
        {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
    },
    // S8
    {
        {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
        {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
        {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
        {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
    }
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
    //pick 56 out of 64 key bits
    bitset<56> permutedKey = permuted_choice_1(key);
    // Split
    bitset<28> leftHalf, rightHalf;
    for (int i = 0; i < 28; ++i) {
        leftHalf[i] = permutedKey[i];
        rightHalf[i] = permutedKey[i + 28];
    }

    for (int round = 0; round < 16; ++round) {
        //left shift
        leftHalf = left_shift(leftHalf, shiftBits[round]);
        rightHalf = left_shift(rightHalf, shiftBits[round]);

        // assemble 2 halves
        bitset<56> combinedKey;
        for (int i = 0; i < 28; ++i) {
            combinedKey[i] = leftHalf[i];
            combinedKey[i + 28] = rightHalf[i];
        }

        //PC2
        subKeys[round] = permuted_choice_2(combinedKey);
        
    }
}

// expand
bitset<48> expand(bitset<32> data) {
    bitset<48> expandedData;
    for (int i = 0; i < 48; ++i) {
        expandedData[i] = data[expansionTable[i] - 1];
    }
    return expandedData;
}

//permutation
bitset<32> permute(bitset<32> data) {
    bitset<32> permutedData;
    for (int i = 0; i < 32; ++i) {
        permutedData[i] = data[permutationTable[i] - 1];
    }
    return permutedData;
}

//substitution
bitset<32> sBoxSubstitution(bitset<48> data) {
    bitset<32> substitutedData;
    int bitPos = 0;
    for (int i = 0; i < 8; ++i) {
        int row = data[bitPos] * 2 + data[bitPos + 5];
        int col = (data[bitPos + 1] << 3) + (data[bitPos + 2] << 2) + (data[bitPos + 3] << 1) + data[bitPos + 4];
        int sBoxValue = SBox[i][row][col];
        bitset<4> sBoxBits(sBoxValue);
        for (int j = 0; j < 4; ++j) {
            substitutedData[4 * i + j] = sBoxBits[j];
        }
        bitPos += 6;
    }
    return substitutedData;
}

//f function
bitset<32> f(bitset<32> rightHalf, bitset<48> roundKey) {
    // expansion
    bitset<48> expandedData = expand(rightHalf);

    // XOR with subkey
    expandedData ^= roundKey;

    //substitution
    bitset<32> substitutedData = sBoxSubstitution(expandedData);

    // permutation
    bitset<32> permutedData = permute(substitutedData);

    return permutedData;
}
// FP
bitset<64> finalPermutation(bitset<64> data) {
    bitset<64> permutedData;
    for (int i = 0; i < 64; ++i) {
        permutedData[i] = data[finalPermutationTable[i] - 1];
    }
    // cout << "IP-1: \t\t\t\t" << permutedData << endl;
    return permutedData;
}
//IP
bitset<64> initialPermutation(bitset<64> data) {
    bitset<64> permutedData;
    for (int i = 0; i < 64; ++i) {
        permutedData[i] = data[initialPermutationTable[i] - 1];
    }
    //cout << "IP: \t\t\t\t" << permutedData << endl;
    return permutedData;
}
//DES encryption
bitset<64> encryptDES(bitset<64> data, bitset<64> originalKey) {
    //IP
    data = initialPermutation(data);

    // Split
    bitset<32> leftHalf, rightHalf;
    for (int i = 0; i < 32; ++i) {
        leftHalf[i] = data[i];
        rightHalf[i] = data[i + 32];
    }

    // Generate subkeys
    bitset<48> subKeys[16];
    generate_subkeys(originalKey, subKeys);

    // 16 rounds
    for (int round = 0; round < 16; ++round) {
        bitset<32> tempRight = rightHalf;
        rightHalf = leftHalf ^ f(rightHalf, subKeys[round]);
        leftHalf = tempRight;
    }

    //assemble 2 halves
    bitset<64> encryptedData;
    for (int i = 0; i < 32; ++i) {
        encryptedData[i] = leftHalf[i];
        encryptedData[i + 32] = rightHalf[i];
    }

    // FP
    encryptedData = finalPermutation(encryptedData);
    return encryptedData;
}
//generate IV
bitset<64> generateRandomIV() {
    bitset<64> iv;
    srand(time(0)); // get random seed
    for (int i = 0; i < 64; i++) {
        iv[i] = rand() % 2;
    }
    return iv;
}

// if the plaintext length is not divisible by 64 
//add space to the end of the last block
string padPlaintext(string plaintext) {
    int paddingSize = 64 - (plaintext.length() % 64);
    if (paddingSize < 64) {
        for (int i = 0; i < paddingSize; i++) {
            plaintext += '0';
        }
    }
    return plaintext;
}

//split plaintext into 64-bit blocks
vector<bitset<64>> splitPlaintext(string plaintext) {
    vector<bitset<64>> blocks;
    for (int i = 0; i < plaintext.length(); i += 64) {
        string blockStr = plaintext.substr(i, 64);
        //cout << blockStr << endl;
        bitset<64> blockBits(blockStr);
        blocks.push_back(blockBits);
    }
    return blocks;
}

vector<bitset<64>> encryptCFB(vector<bitset<64>> plaintext, bitset<64> originalKey, bitset<64> IV) {
    vector<bitset<64>> cyphertext;
    bitset<64> previousCipherText = IV;
    
    for (size_t i = 0; i < plaintext.size(); i++) {
        // Encrypt the previous ciphertext
        bitset<64> encryptedCipherText = encryptDES(previousCipherText, originalKey);
        
        // XOR the ciphertext with the plaintext to get the encrypted plaintext
        bitset<64> encryptedText = plaintext[i] ^ encryptedCipherText;
        
        // Update the previous ciphertext for the next block
        previousCipherText = encryptedText;
        
        cyphertext.push_back(encryptedText);
    }

    return cyphertext;
}

int main() {
    // Plaintext: "Vũ Đức An" (UTF-8) 
    // To binary: 01010110 11000101 10101001 00100000 11000100 10010000 11100001 10111011 10101001 01100011 00100000 01000001 01101110 (104 bits)
    string plaintext = "01010110110001011010100100100000110001001001000011100001101110111010100101100011001000000100000101101110";
    //Original Key: "paSswoRD" 01110000 01100001 01010011 01110011 01110111 01101111 01010010 01000100
    bitset<64> originalKey(string("0111000001100001010100110111001101110111011011110101001001000100")); // 64-bit original key
    //generate Initial Vector
    bitset<64> initialVector = generateRandomIV();
    // split 104 bits of plaintext to 2 blocks
    plaintext = padPlaintext(plaintext);
    vector<bitset<64>> data = splitPlaintext(plaintext);
    // Perform DES encryption
    vector<bitset<64>> encryptedData = encryptCFB(data, originalKey, initialVector);

    cout << "Key: \t\t" << hex << originalKey.to_ullong() << "\t\t" << originalKey << endl;
    cout << "IV: \t\t" << hex << initialVector.to_ullong() << "\t\t" << initialVector << endl;
    int i=0;
    for (const bitset<64>& block:encryptedData){

        cout << "Block " << ++i << ": \t" << block << endl;
    }
    

    return 0;
}