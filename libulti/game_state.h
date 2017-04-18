// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_GAME_STATE_H
#define ULTI_LIBULTI_GAME_STATE_H

#include <libulti/bids.h>
#include <libulti/cards.h>
#include <libulti/common.h>
#include <libulti/player_state.h>

namespace ulti {

class GameState final {
public:
  GameState();
  ~GameState();

  int GetSelfId() const { return self_id_; }
  Cards GetHand() const { return players_[self_id_]->GetHand(); }

  void Reset(int self_id);
  void Deal(const Cards& cards);
  void RemoveFromHand(const Cards& cards);
  void SetBidAndTalon(int bidding_player, const Bids& bid, const Cards& talon);
  void SetTrump(Cards::Suit trump);

private:
  PlayerState* players_[3];
  int self_id_;
  int bidding_player_;
  Bids bid_;
  Cards talon_;
  Cards::Suit trump_;

  DISALLOW_COPY_AND_ASSIGN(GameState);
};

}  // namespace ulti

#endif // ULTI_LIBULTI_GAME_STATE_H
