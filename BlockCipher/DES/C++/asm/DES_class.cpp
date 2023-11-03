#include <iostream>
#include <bitset>
#include <vector>
#include <random>

const int initial_key_permutaion[] = {57, 49,  41, 33,  25,  17,  9,
                                 1, 58,  50, 42,  34,  26, 18,
                                10,  2,  59, 51,  43,  35, 27,
                                19, 11,   3, 60,  52,  44, 36,
                                63, 55,  47, 39,  31,  23, 15,
                                 7, 62,  54, 46,  38,  30, 22,
                                14,  6,  61, 53,  45,  37, 29,
                                21, 13,   5, 28,  20,  12,  4};

const int initial_message_permutation[] =    {58, 50, 42, 34, 26, 18, 10, 2,
                                        60, 52, 44, 36, 28, 20, 12, 4,
                                        62, 54, 46, 38, 30, 22, 14, 6,
                                        64, 56, 48, 40, 32, 24, 16, 8,
                                        57, 49, 41, 33, 25, 17,  9, 1,
                                        59, 51, 43, 35, 27, 19, 11, 3,
                                        61, 53, 45, 37, 29, 21, 13, 5,
                                        63, 55, 47, 39, 31, 23, 15, 7};

const int key_shift_sizes[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

const int sub_key_permutation[] =    {14, 17, 11, 24,  1,  5,
                                 3, 28, 15,  6, 21, 10,
                                23, 19, 12,  4, 26,  8,
                                16,  7, 27, 20, 13,  2,
                                41, 52, 31, 37, 47, 55,
                                30, 40, 51, 45, 33, 48,
                                44, 49, 39, 56, 34, 53,
                                46, 42, 50, 36, 29, 32};

const int message_expansion[] =  {32,  1,  2,  3,  4,  5,
                             4,  5,  6,  7,  8,  9,
                             8,  9, 10, 11, 12, 13,
                            12, 13, 14, 15, 16, 17,
                            16, 17, 18, 19, 20, 21,
                            20, 21, 22, 23, 24, 25,
                            24, 25, 26, 27, 28, 29,
                            28, 29, 30, 31, 32,  1};

const int S1[] = {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
             0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
             4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
            15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13};

const int S2[] = {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
             3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
             0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
            13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9};

const int S3[] = {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
            13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
            13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
             1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12};

const int S4[] = { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
            13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
            10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
             3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14};

const int S5[] = { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
            14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
             4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
            11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3};

const int S6[] = {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
            10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
             9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
             4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13};

const int S7[] = { 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
            13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
             1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
             6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12};

const int S8[] = {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
             1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
             7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
             2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11};

const int right_sub_message_permutation[] =    {16,  7, 20, 21,
                                    29, 12, 28, 17,
                                     1, 15, 23, 26,
                                     5, 18, 31, 10,
                                     2,  8, 24, 14,
                                    32, 27,  3,  9,
                                    19, 13, 30,  6,
                                    22, 11,  4, 25};

const int final_message_permutation[] =  {40,  8, 48, 16, 56, 24, 64, 32,
                                    39,  7, 47, 15, 55, 23, 63, 31,
                                    38,  6, 46, 14, 54, 22, 62, 30,
                                    37,  5, 45, 13, 53, 21, 61, 29,
                                    36,  4, 44, 12, 52, 20, 60, 28,
                                    35,  3, 43, 11, 51, 19, 59, 27,
                                    34,  2, 42, 10, 50, 18, 58, 26,
                                    33,  1, 41,  9, 49, 17, 57, 25};

class DES {
public:
    std::bitset<64> mainKey;
    std::vector<std::bitset<48>> subKeys;

    DES();
    DES(std::bitset<64> mainKey);
    void generateKey();
    void printKeySet();
    void generateSubKeys();
    void processMessage(std::bitset<64>& message, std::bitset<64>& processedMessage, bool encryptionMode);
    std::bitset<32> feistelFunction(const std::bitset<32>& rightHalf, const std::bitset<48>& roundKey);
    void printBinary(const std::bitset<64>& bits);
    void printKey(const std::bitset<48>& bits);
};

DES::DES() {
    // Constructor to initialize DES with a random main key.
    generateKey();
}

DES::DES(std::bitset<64> key) {
    // Constructor to initialize DES with a random main key.
    mainKey = key;
}

void DES::generateKey() {
    std::bitset<64> key;

    // Use a random number generator to generate a 64-bit key.
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<std::uint64_t> dis(0, UINT64_MAX);

    key = std::bitset<64>(dis(gen));

    mainKey = key;
}

void DES::printBinary(const std::bitset<64>& bits) {
    // Helper function to print a std::bitset as a binary string.
    std::cout << bits;
}

void DES::printKey(const std::bitset<48>& bits) {
    std::cout << bits;
}

void DES::printKeySet() {
    std::cout << "Main Key: ";
    printBinary(mainKey);
    std::cout << "\nSubkeys:\n";
    for (const auto& key : subKeys) {
        printKey(key);
        std::cout << '\n';
    }
}

void DES::generateSubKeys() {
    // Initialize the subKeys vector with 16 empty 48-bit bitsets.
    subKeys.clear();
    subKeys.resize(16, std::bitset<48>());

    std::bitset<28> c, d, temp;

    // Initial permutation and split into C and D.
    for (int i = 0; i < 28; i++) {
        c[i] = mainKey[initial_key_permutaion[i] - 1];
        d[i] = mainKey[initial_key_permutaion[i + 28] - 1];
    }

    for (int round = 0; round < 16; round++) {
        // Perform circular left shift on C and D.
        c <<= key_shift_sizes[round];
        d <<= key_shift_sizes[round];

        // Create a 56-bit key by merging C and D.
        for (int i = 0; i < 28; i++) {
            temp[i] = c[i];
            temp[i + 28] = d[i];
        }

        // Apply the sub_key_permutation to get the 48-bit subkey.
        for (int i = 0; i < 48; i++) {
            subKeys[round][i] = temp[sub_key_permutation[i] - 1];
        }
    }
}


void DES::processMessage(std::bitset<64>& message, std::bitset<64>& processedMessage, bool encryptionMode) {
    std::bitset<64> initialPermutation;
    std::bitset<32> l, r, temp;

    // Initial permutation
    for (int i = 0; i < 64; i++) {
        initialPermutation[i] = message[initial_message_permutation[i] - 1];
    }

    // Split into L and R
    for (int i = 0; i < 32; i++) {
        l[i] = initialPermutation[i];
        r[i] = initialPermutation[i + 32];
    }

    for (int round = 0; round < 16; round++) {
        temp = r;
        r = l ^ feistelFunction(r, subKeys[encryptionMode ? round : 15 - round]);
        l = temp;
    }

    // Merge L and R
    for (int i = 0; i < 32; i++) {
        initialPermutation[i] = r[i];
        initialPermutation[i + 32] = l[i];
    }

    // Final permutation
    for (int i = 0; i < 64; i++) {
        processedMessage[i] = initialPermutation[final_message_permutation[i] - 1];
    }
}

std::bitset<32> DES::feistelFunction(const std::bitset<32>& rightHalf, const std::bitset<48>& roundKey) {
    // Expand the 32-bit right half to 48 bits using E-bit selection.
    std::bitset<48> expandedRightHalf;
    for (int i = 0; i < 48; i++) {
        expandedRightHalf[i] = rightHalf[message_expansion[i] - 1];
    }

    // XOR the expanded right half with the round key.
    expandedRightHalf ^= roundKey;

    // Apply S-box substitutions to the 48-bit data.
    std::bitset<32> substitutedData;
    for (int i = 0; i < 8; i++) {
        // Select 6 bits from the expanded data.
        std::bitset<6> sixBits;
        for (int j = 0; j < 6; j++) {
            sixBits[j] = expandedRightHalf[i * 6 + j];
        }

        // Calculate the S-box index.
        int sBoxIndex = i * 4;
        sBoxIndex += sixBits[0] ? 1 : 0;
        sBoxIndex += sixBits[5] ? 2 : 0;
        sBoxIndex += sixBits[1] ? 4 : 0;
        sBoxIndex += sixBits[2] ? 8 : 0;

        // Retrieve the value from the corresponding S-box.
        std::bitset<4> sBoxValue;
        switch (i) {
            case 0: sBoxValue = S1[sBoxIndex]; break;
            case 1: sBoxValue = S2[sBoxIndex]; break;
            case 2: sBoxValue = S3[sBoxIndex]; break;
            case 3: sBoxValue = S4[sBoxIndex]; break;
            case 4: sBoxValue = S5[sBoxIndex]; break;
            case 5: sBoxValue = S6[sBoxIndex]; break;
            case 6: sBoxValue = S7[sBoxIndex]; break;
            case 7: sBoxValue = S8[sBoxIndex]; break;
        }

        // Append the 4-bit S-box value to the result.
        for (int j = 0; j < 4; j++) {
            substitutedData[i * 4 + j] = sBoxValue[j];
        }
    }

    // Permute the substituted data using the P permutation.
    std::bitset<32> permutedData;
    for (int i = 0; i < 32; i++) {
        permutedData[i] = substitutedData[right_sub_message_permutation[i] - 1];
    }

    return permutedData;
}


int main() {
    DES des;
    des.printKeySet();

    std::bitset<64> message = std::bitset<64>(0x0123456789ABCDEF);  // Replace with your plaintext message.
    std::bitset<64> ciphertext;

    des.processMessage(message, ciphertext, true);

    std::cout << "Ciphertext: ";
    des.printBinary(ciphertext);
    std::cout << '\n';

    return 0;
}
