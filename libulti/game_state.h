// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_GAME_STATE_H
#define ULTI_LIBULTI_GAME_STATE_H

#include <libulti/macros.h>

namespace ulti {

class PlayerState;

class GameState final {
public:
  GameState();
  ~GameState();

  void Reset(int self_id);

private:
  PlayerState* players_[3];
  int self_id_;

  DISALLOW_COPY_AND_ASSIGN(GameState);
};

}  // namespace ulti

#endif // ULTI_LIBULTI_GAME_STATE_H
