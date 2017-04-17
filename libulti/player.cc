// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#include <libulti/player.h>

#include <libulti/game_state.h>

namespace ulti {

Player::Player(Engine *engine)
  : engine_(engine),
    state_(new GameState()) {}

Player::~Player() {
  delete state_;
}

void Player::StartGame(int self_id) {
  state_->Reset(self_id);
}

void Player::Deal(const Cards& cards) {
  // TODO(gyorgy): Implement it.
}

bool Player::WouldBid() {
  // TODO(gyorgy): Implement it.
  return false;
}

void Player::GetBidAndTalon(Bids* bids, Cards* cards) {
  // TODO(gyorgy): Implement it.
}

void Player::NotifyBid(int bidding_player, const Bids& bid) {
  // TODO(gyorgy): Implement it.
}

}  // namespace ulti
