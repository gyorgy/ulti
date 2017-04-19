// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#include <libulti/game_state.h>

#include <libulti/player_state.h>

namespace ulti {

GameState::GameState()
  : players_{new PlayerState(), new PlayerState(), new PlayerState()},
    self_id_(0) {}

GameState::~GameState() {
  for (auto player : players_) {
    delete player;
  }
}

void GameState::Reset(int self_id) {
  self_id_ = self_id;
  for (auto player : players_) {
    player->Reset();
  }
}

void GameState::SetBid(int bidding_player, const Bids& bid) {
  bidding_player_ = bidding_player;
  bid_ = bid;
}

void GameState::SetTalon(int bidding_player, const Cards& talon) {
  talon_ = talon;
  players_[bidding_player]->RemoveFromHand(talon);
}

void GameState::SetTrump(Cards::Suit trump) {
  trump_ = trump;
}

}  // namespace ulti
