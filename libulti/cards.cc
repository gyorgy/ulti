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

}  // namespace ulti


