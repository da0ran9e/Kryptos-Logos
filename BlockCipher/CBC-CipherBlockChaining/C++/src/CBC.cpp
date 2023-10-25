#include <bitset>
#include <vector>
#include "../cbc/CBC.hpp"
#include "../des/encrypt.hpp"


std::vector<std::bitset<64>> encryptCBC(std::vector<std::bitset<64>> plaintext, std::bitset<64> IV, std::bitset<64> originalKey) {
    
    std::vector<std::bitset<64>> ciphertext;
    std::bitset<64> previousBlock = IV;

    for (const std::bitset<64>& block : plaintext) {
        // XOR the current block with the previous block
        std::bitset<64> xorResult = block ^ previousBlock;

        // encrypt
        std::bitset<64> encryptedBlock = encryptDES(xorResult, originalKey);

        // add the encrypted block to the ciphertext
        ciphertext.push_back(encryptedBlock);
        
        // Update the previous block
        previousBlock = encryptedBlock;
    }

    return ciphertext;
}