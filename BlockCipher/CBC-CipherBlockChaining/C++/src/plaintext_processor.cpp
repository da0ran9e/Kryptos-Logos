#include <bitset>
#include <vector>
#include "../cbc/plaintext_processor.hpp"

// if the plaintext length is not divisible by 64 
std::string padPlaintext(std::string plaintext) {
    int paddingSize = 64 - (plaintext.length() % 64);
    if (paddingSize < 64) {
        for (int i = 0; i < paddingSize; i++) {
            plaintext += ' ';
        }
    }
    return plaintext;
}

//split plaintext into 64-bit blocks
std::vector<std::bitset<64>> splitPlaintext(std::string plaintext) {
    std::vector<std::bitset<64>> blocks;
    for (int i = 0; i < plaintext.length(); i += 64) {
        std::string blockStr = plaintext.substr(i, 64);
        std::bitset<64> blockBits(blockStr);
        blocks.push_back(blockBits);
    }
    return blocks;
}