#ifndef PERMUTED_CHOICE_HPP
#define PERMUTED_CHOICE_HPP

#include <bitset>
#include <vector>

std::bitset<56> pc1(const std::bitset<64>& key);
std::bitset<48> pc2(const std::bitset<56>& key);

#endif
