#include "market/quote.hpp"

bool valid_quote(long long bid_ticks, long long ask_ticks) {
    return bid_ticks > 0 && ask_ticks >= bid_ticks;
}

long long spread_ticks(long long bid_ticks, long long ask_ticks) {
    if (!valid_quote(bid_ticks, ask_ticks)) {
        return -1;
    }
    return ask_ticks - bid_ticks;
}

