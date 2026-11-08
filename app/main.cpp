#include <iostream>
#include "market/quote.hpp"

int main() {
    long long bid_ticks{};
    long long ask_ticks{};

    if (!(std::cin >> bid_ticks >> ask_ticks)) {
        std::cerr << "input_error\n";
        return 2;
    }

    const long long spread = spread_ticks(bid_ticks, ask_ticks);
    if (spread < 0) {
        std::cerr << "invalid_quote\n";
        return 2;
    }

    std::cout << "spread_ticks=" << spread << '\n';
}
