#ifndef MARKET_REPLAY_QUOTE_HPP
#define MARKET_REPLAY_QUOTE_HPP

bool valid_quote(long long bid_ticks, long long ask_ticks);
long long spread_ticks(long long bid_tickes, long long ask_ticks);

#endif
