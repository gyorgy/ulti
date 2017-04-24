// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#include <libulti/cards.h>

#include <cstdlib>
#include <vector>

namespace ulti {

Cards Cards::GetRandomCard() const {
  std::vector<Cards> cards;
  for (uint32 mask = 1U; mask; mask <<= 1) {
    if (bits_ & mask) {
      cards.push_back(Cards(mask));
    }
  }
  return cards[rand() % cards.size()];
}

bool Cards::IsBeatingTrumpless(const Cards &other) const {
  const uint_fast32_t bits = (bits_ & 0x87878787U) |
                             ((bits_ & 0x38383838U) << 1) |
                             ((bits_ & 0x40404040U) >> 3);
  const uint_fast32_t other_bits = (bits_ & 0x87878787U) |
                                   ((bits_ & 0x38383838U) << 1) |
                                   ((bits_ & 0x40404040U) >> 3);
  return other_bits > bits;
}

}  // namespace ulti


