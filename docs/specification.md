# Specification

a bid is a displayed buy price, an ask is a displayed sell price, and a spread is ask minus bid. The initial exercise takes positive prices in integer ticks. The exercise accepts a locked quote with equal bid and ask, and rejects a crossed quote with ask below bid. Its fixture uses one tick per cent. Later feed adapters declare their own exact scale.
