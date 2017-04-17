// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_ENGINE_H
#define ULTI_LIBULTI_ENGINE_H

#include <libulti/macros.h>

namespace ulti {

class Bids;
class Cards;
class GameState;

class Engine {
public:
  Engine();
  virtual ~Engine();

  virtual void Start() = 0;
  virtual bool WouldBid(const GameState& state) = 0;
  virtual void GetBidAndTalon(const GameState& state, Bids* bid, Cards* talon) = 0;

private:
  DISALLOW_COPY_AND_ASSIGN(Engine);
};

}  // namespace ulti

#endif  // ULTI_LIBULTI_ENGINE_H
