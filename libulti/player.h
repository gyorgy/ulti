// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_PLAYER_H
#define ULTI_LIBULTI_PLAYER_H

#include <libulti/bids.h>
#include <libulti/cards.h>
#include <libulti/macros.h>

namespace ulti {

class Engine;
class GameState;

class Player final {
public:
  Player(Engine* engine);
  ~Player();

  void StartGame(int self_id);
  void Deal(const Cards& cards);
  bool WouldBid();
  void GetBidAndTalon(Bids* bids, Cards* cards);
  void NotifyBid(int bidding_player, const Bids& bid);

private:
  Engine* engine_;
  GameState* state_;

  DISALLOW_COPY_AND_ASSIGN(Player);
};

}  // namespace ulti

#endif  // ULTI_LIBULTI_PLAYER_H
