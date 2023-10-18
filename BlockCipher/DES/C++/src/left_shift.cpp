#include <bits/stdc++.h>
#include "../des/left_shift.hpp"
using namespace std;

bitset<28> leftShift(const std::bitset<28>& key, int shift) {
    return (key << shift) | (key >> (28 - shift));
}