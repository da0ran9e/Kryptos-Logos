#ifndef PLAINTEXT_PROCESSOR_HPP
#define PLAINTEXT_PROCESSOR_HPP

#include<bitset>
#include<vector>

std::string padPlaintext(std::string plaintext);
std::vector<std::bitset<64>> splitPlaintext(std::string plaintext);

#endif