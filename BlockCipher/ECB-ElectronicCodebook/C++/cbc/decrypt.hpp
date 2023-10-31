#ifndef DECRYPT_HPP
#define DECRYPT_HPP

#include <bitset>

std::bitset<64> decryptDES(std::bitset<64> data, std::bitset<64> originalKey);

#endif
