#ifndef PERMUTED_CHOICE_HPP
#define PERMUTED_CHOICE_HPP

#include <bitset>
#include <vector>

std::bitset<56> permuted_choice_1(const std::bitset<64>& key);
std::bitset<48> permuted_choice_2(const std::bitset<56>& key);

#endif
