#include <iostream>
#include <limits>
#include "market/quote.hpp"

int main() {
    int failures = 0;
    if (spread_ticks(10000, 10005) !=5) { ++failures; }
    if (spread_ticks(10000, 10000) !=0) { ++failures; }
    if (spread_ticks(10005, 10000) !=-1) { ++failures; }
    if (spread_ticks(0, 10000) !=-1) { ++failures; }
    if (spread_ticks(-1, 10000) !=-1) { ++failures; }
    const long long maximum = std::numeric_limits<long long>::max();
    if (spread_ticks(1, maximum) != maximum - 1) { ++failures; }
    std::cout << "failures=" << failures << '\n';
    return failures == 0 ? 0 : 1;

}

