#ifndef KEY_SCHEDULER_HPP
#define KEY_SCHEDULER_HPP

#include <bitset>
#include <vector>

std::bitset<48> generate_subkeys(const std::bitset<64>& key);

#endif
