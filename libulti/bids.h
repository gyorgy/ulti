// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_BIDS_H
#define ULTI_LIBULTI_BIDS_H

#include <libulti/common.h>

namespace ulti {

class Bids {
public:
  enum {
    PASS            = 0U,
    PARTI           = (1U << 0),
    FOUR_ACES       = (1U << 1),
    ULTI            = (1U << 2),
    FORTY_HUNDRED   = (1U << 3),
    BETLI           = (1U << 4),
    DURCHMARS       = (1U << 5),
    TWENTY_HUNDRED  = (1U << 6),
    HEARTS          = (1U << 7),
    OPEN            = (1U << 8),
    TRUMPLESS       = (1U << 9),
    KONTRA          = (1U << 10),
    REKONTRA        = (1U << 11)
  };

  Bids() : bits_(PASS) {}
  Bids(uint32 bits) : bits_(bits) {}

  bool IsPass() const { return bits_ == PASS; }
  bool IsParti() const { return bits_ &  PARTI; }
  bool IsFourAces() const { return bits_ & FOUR_ACES; }
  bool IsUlti() const { return bits_ &  ULTI; }
  bool IsFortyHundred() const { return bits_ & FORTY_HUNDRED; }
  bool IsBetli() const { return bits_ & BETLI; }
  bool IsDurchmars() const { return bits_ & DURCHMARS; }
  bool IsTwentyHundred() const { return bits_ & TWENTY_HUNDRED; }
  bool IsHearts() const { return bits_ & HEARTS; }
  bool IsOpen() const { return bits_ & OPEN; }
  bool IsTrumpless() const { return bits_ & TRUMPLESS; }
  bool IsKontra() const { return bits_ & KONTRA; }
  bool IsRekontra() const { return bits_ & REKONTRA; }

private:
  uint32 bits_;
};

}  // namespace ulti

#endif  // ULTI_LIBULTI_BIDS_H
