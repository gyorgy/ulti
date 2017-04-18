// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_RULES_H
#define ULTI_LIBULTI_RULES_H

#include <vector>

#include <libulti/bids.h>
#include <libulti/cards.h>

namespace ulti {

class Rules final {
public:
  Rules();

  void SetBid(const Bids& bids, Cards::Suit trump);

  bool HasTrump() const { return !bids_.IsTrumpless(); }
  int GetTaker(int calling_player, const std::vector<Cards>& calls) const;
  Cards GetValidCalls(const Cards& hand, const std::vector<Cards>& calls) const;

private:
  Bids bids_;
  Cards::Suit trump_;

  bool IsTaking(Cards::Suit called_suit, const Cards& current_best, const Cards& card) const;

  DISALLOW_COPY_AND_ASSIGN(Rules);
};

}  // namespace ulti

#endif // ULTI_LIBULTI_RULES_H
