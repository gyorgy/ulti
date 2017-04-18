// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_PLAYER_H
#define ULTI_LIBULTI_PLAYER_H

#include <vector>

#include <libulti/bids.h>
#include <libulti/cards.h>
#include <libulti/common.h>

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
  Cards::Suit GetTrump();
  void StartPlay(int bidding_player, const Bids& bid, Cards::Suit trump);
  Cards GetCall(int calling_player, const std::vector<Cards>& calls);
  void NotifyCall(int current_player, const Cards& call);
  void NotifyTrick(int taking_player, const std::vector<Cards>& calls);

private:
  Engine* engine_;
  GameState* state_;

  DISALLOW_COPY_AND_ASSIGN(Player);
};

}  // namespace ulti

#endif  // ULTI_LIBULTI_PLAYER_H
