// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#include <libulti/rules.h>

#include <libulti/bids.h>

namespace ulti {

Rules::Rules()
  : bids_(Bids::PASS),
    trump_(Cards::Suit::TRUMPLESS) {}

void Rules::SetBid(const Bids& bids, Cards::Suit trump) {
  bids_ = bids;
  trump_ = trump;
}

int Rules::GetTaker(int calling_player, const std::vector<Cards>& calls) const {
  const Cards::Suit called_suit = calls[0].GetSuit();
  int taker = 0;
  Cards taking_card = calls[0];
  for (int i = 1; i < 3; ++i) {
    if (IsTaking(called_suit, taking_card, calls[i])) {
      taker = i;
      taking_card = calls[i];
    }
  }
  return (calling_player + taker) % 3;
}

Cards Rules::GetValidCalls(const Cards& hand, const std::vector<Cards>& calls) const {

}

bool Rules::IsTaking(Cards::Suit called_suit, const Cards& current_best, const Cards& card) const {
  const Cards::Suit suit = card.GetSuit();
  if (suit != called_suit && suit != trump_) {
    return false;
  }
  const Cards::Suit best_suit = current_best.GetSuit();
  if (best_suit == trump_ && suit != trump_) {
    return false;
  }
  if (called_suit != trump_ && suit == trump_) {
    return true;
  }
  return HasTrump() ? card.IsTaking(current_best) : card.IsTrumplesTaking(current_best);
}

}  // namespace ulti

