// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBKUBLER_KUBLER_H
#define ULTI_LIBKUBLER_KUBLER_H

#include <libulti/common.h>
#include <libulti/engine.h>

namespace ulti {
namespace kubler {

class Kubler : public Engine {
public:
  Kubler();
  virtual ~Kubler();

  virtual void Start();
  virtual bool WouldBid(const GameState& state);
  virtual Bids GetBid(const GameState& state);
  virtual Cards GetTalon(const GameState& state);
  virtual Cards::Suit GetTrump();
  virtual Cards GetCall(const GameState& state, int calling_player,
                        const std::vector<Cards>& calls);

private:
  DISALLOW_COPY_AND_ASSIGN(Kubler);
};

}  // namespace kubler
}  // namespace ulti

#endif  // ULTI_LIBKUBLER_KUBLER_H
