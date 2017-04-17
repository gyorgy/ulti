// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBKUBLER_KUBLER_H
#define ULTI_LIBKUBLER_KUBLER_H

#include <libulti/engine.h>
#include <libulti/macros.h>

namespace ulti {
namespace kubler {

class Kubler : public Engine {
public:
  Kubler();
  virtual ~Kubler();

  virtual void Start();
  virtual bool WouldBid(const GameState& state);
  virtual void GetBidAndTalon(const GameState& state, Bids* bid, Cards* talon);

private:
  DISALLOW_COPY_AND_ASSIGN(Kubler);
};

}  // namespace kubler
}  // namespace ulti

#endif  // ULTI_LIBKUBLER_KUBLER_H
