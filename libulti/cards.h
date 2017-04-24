// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_CARDS_H
#define ULTI_LIBULTI_CARDS_H

#include <libulti/bits.h>
#include <libulti/common.h>

namespace ulti {

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

  Cards() : bits_(0UL) {}
  Cards(uint32 bits) : bits_(bits) {}

  Cards::Suit GetSuit() const { return static_cast<Suit>(CountTrailingZeros(bits_) / 8 * 8); }
  int GetRank() const { return bits_ >> GetSuit() & 0xff; }
  int Count() const { return PopCount(bits_); }
  Cards GetRandomCard() const;
  bool IsBeating(const Cards &other) const { return bits_ > other.bits_; }
  bool IsBeatingTrumpless(const Cards &other) const;

  void Clear() { bits_ = 0UL; }
  void Add(const Cards& cards) { bits_ |= cards.bits_; }
  void Remove(const Cards& cards) { bits_ &= ~cards.bits_; }

private:
  uint32 bits_;
};

}  // namespace ulti

#endif // ULTI_LIBULTI_CARDS_H
