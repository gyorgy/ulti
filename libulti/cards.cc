// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#include <libulti/cards.h>

#include <cstdlib>
#include <vector>

namespace ulti {

Cards Cards::GetRandomCard() const {
  std::vector<Cards> cards;
  for (Card mask = 1UL; mask; mask <<= 1) {
    if (cards_ & mask) {
      cards.push_back(Cards(mask));
    }
  }
  return cards[rand() % cards.size()];
}

bool Cards::IsTrumplesTaking(const Cards& other) const {
  const uint_fast32_t bits = (cards_ & 0x87878787UL) |
                             ((cards_ & 0x38383838UL) << 1) |
                             ((cards_ & 0x40404040UL) >> 3);
  const uint_fast32_t other_bits = (cards_ & 0x87878787UL) |
                                   ((cards_ & 0x38383838UL) << 1) |
                                   ((cards_ & 0x40404040UL) >> 3);
  return other_bits > bits;
}

}  // namespace ulti


