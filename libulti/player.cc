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

}  // namespace ulti
