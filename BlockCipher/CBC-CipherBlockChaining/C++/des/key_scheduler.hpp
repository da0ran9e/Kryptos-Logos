#ifndef KEY_SCHEDULER_HPP
#define KEY_SCHEDULER_HPP

#include <bitset>
#include <vector>

void generate_subkeys(const std::bitset<64>& key, std::bitset<48> subKeys[16]);

#endif
