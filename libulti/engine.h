// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_ENGINE_H
#define ULTI_LIBULTI_ENGINE_H

#include <vector>

#include <libulti/common.h>
#include <libulti/cards.h>

namespace ulti {

class Bids;
class GameState;

class Engine {
public:
  Engine();
  virtual ~Engine();

  virtual void Start() = 0;
  virtual bool WouldBid(const GameState& state) = 0;
  virtual void GetBidAndTalon(const GameState& state, Bids* bid, Cards* talon) = 0;
  virtual Cards::Suit GetTrump() = 0;
  virtual Cards GetCall(const GameState& state, int calling_player,
                        const std::vector<Cards>& calls) = 0;
private:
  DISALLOW_COPY_AND_ASSIGN(Engine);
};

}  // namespace ulti

#endif  // ULTI_LIBULTI_ENGINE_H
