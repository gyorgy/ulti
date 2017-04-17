// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_RULES_H
#define ULTI_LIBULTI_RULES_H

#include <vector>

#include <libulti/cards.h>

namespace ulti {

class Bids;

bool HasTrump(const Bids& bids);

int GetTaker(const Bids& bid, Cards::Suit trump, int calling_player,
                    std::vector<Cards>& calls);

Cards GetValidCalls(const Bids& bid, Cards::Suit trump, const Cards& hand,
                    const std::vector<Cards>& calls);

}  // namespace ulti

#endif // ULTI_LIBULTI_RULES_H
