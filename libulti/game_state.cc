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

}  // namespace ulti
