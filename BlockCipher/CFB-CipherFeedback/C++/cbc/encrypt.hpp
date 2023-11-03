#ifndef ENCRYPT_HPP
#define ENCRYPT_HPP

#include <bitset>

std::bitset<64> encryptDES(std::bitset<64> data, std::bitset<64> originalKey);

#endif
