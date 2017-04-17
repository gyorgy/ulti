// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_CARDS_H
#define ULTI_LIBULTI_CARDS_H

#include <cstdint>

#include "bits.h"

namespace ulti {

typedef uint_fast32_t Card;

class Cards final {
public:
  enum Suit {
    TRUMPLESS = -1,
    ACCORNS   = 0,
    LEAVES    = 8,
    HEARTS    = 16,
    BALLS     = 24,
  };
  enum Rank {
    VII   = (1UL << 0),
    VIII  = (1UL << 1),
    IX    = (1UL << 2),
    UNDER = (1UL << 3),
    OVER  = (1UL << 4),
    KING  = (1UL << 5),
    X     = (1UL << 6),
    ACE   = (1UL << 7),
  };

  Cards() : cards_(0UL) {}
  Cards(Card cards) : cards_(cards) {}

  Cards::Suit GetSuit() const { return static_cast<Suit>(CountTrailingZeros(cards_) / 8 * 8); }
  int GetRank() const { return cards_ >> GetSuit() & 0xff; }
  int Count() const { return PopCount(cards_); }
  Cards GetRandomCard() const;
  bool IsTaking(const Cards& other) const { return cards_ > other.cards_; }
  bool IsTrumplesTaking(const Cards& other) const;

  void Clear() { cards_ = 0UL; }
  void Add(const Cards& cards) { cards_ |= cards.cards_; }
  void Remove(const Cards& cards) { cards_ &= ~cards.cards_; }

private:
  Card cards_;
};

}  // namespace ulti

#endif // ULTI_LIBULTI_CARDS_H
