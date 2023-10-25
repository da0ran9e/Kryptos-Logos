#ifndef CBC_HPP
#define CBC_HPP


std::vector<std::bitset<64>> encryptCBC(std::vector<std::bitset<64>> plaintext, std::bitset<64> IV, std::bitset<64> originalKey);

#endif