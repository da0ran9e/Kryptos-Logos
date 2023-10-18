#include <bits/stdc++.h>
#include "../des/left_shift.hpp"

std::bitset<28> left_shift(const std::bitset<24>& key, int shift) {
    std::bitset<28> data = key;
    for (int i = 0; i < 28; ++i) {
        int newPos = (i + shift) % 28;
        data[newPos] = key[i];
    }
    return data;
}