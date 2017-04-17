// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#include <libulti/rules.h>

#include <libulti/bids.h>

namespace ulti {

static bool IsTaking(const Bids& bid, Cards::Suit called_suit, Cards::Suit trump,
                     const Cards& current_best, const Cards& card) {
  const Cards::Suit suit = card.GetSuit();
  if (suit != called_suit && suit != trump) {
    return false;
  }
  const Cards::Suit best_suit = current_best.GetSuit();
  if (best_suit == trump && suit != trump) {
    return false;
  }
  if (called_suit != trump && suit == trump) {
    return true;
  }
  return HasTrump(bid) ? card.IsTaking(current_best) : card.IsTrumplesTaking(current_best);
}

bool HasTrump(const Bids& bids) {
  return !bids.IsBetli();
}

int GetTaker(const Bids& bid, Cards::Suit trump, int calling_player,
             std::vector<Cards>& calls) {
  const Cards::Suit called_suit = calls[0].GetSuit();
  int taker = 0;
  Cards taking_card = calls[0];
  for (int i = 1; i < 3; ++i) {
    if (IsTaking(bid, called_suit, trump, taking_card, calls[i])) {
      taker = i;
      taking_card = calls[i];
    }
  }
  return (calling_player + taker) % 3;
}

Cards GetValidCalls(const Bids& bid, Cards::Suit trump, const Cards& hand,
                    const std::vector<Cards>& calls) {
  // TODO(gyorgy): Implement it.
  return hand;
}

}  // namespace ulti

