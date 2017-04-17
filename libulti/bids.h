// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_BIDS_H
#define ULTI_LIBULTI_BIDS_H

#include <cstdint>

namespace ulti {

typedef uint_fast8_t Bid;

class Bids {
public:
  enum {
    PASS            = 0U,
    PARTI           = (1U << 0),
    ULTI            = (1U << 1),
    FORTY_HUNDRED   = (1U << 2),
    BETLI           = (1U << 3),
    DURCHMARS       = (1U << 4),
    TWENTY_HUNDRED  = (1U << 5),
    HEARTS          = (1U << 6),
    OPEN            = (1U << 7),
  };
  Bids() : bids_(PASS) {}
  Bids(Bid bids) : bids_(bids) {}

  bool IsPass() const { return bids_ == PASS; }
  bool IsParti() const { return bids_ &  PARTI; }
  bool IsUlti() const { return bids_ &  ULTI; }
  bool IsFortyHundred() const { return bids_ & FORTY_HUNDRED; }
  bool IsBetli() const { return bids_ & BETLI; }
  bool IsDurchmars() const { return bids_ & DURCHMARS; }
  bool IsTwentyHundred() const { return bids_ & TWENTY_HUNDRED; }
  bool IsHearts() const { return bids_ & HEARTS; }
  bool IsOpen() const { return bids_ & OPEN; }

private:
  Bid bids_;
};

}  // namespace ulti

#endif  // ULTI_LIBULTI_BIDS_H
