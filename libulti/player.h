// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_PLAYER_H
#define ULTI_LIBULTI_PLAYER_H

#include <libulti/macros.h>
#include <libulti/cards.h>

namespace ulti {

class Engine;
class GameState;

class Player final {
public:
  Player(Engine* engine);
  ~Player();

  void StartGame(int self_id);
  void Deal(const Cards& cards);

private:
  Engine* engine_;
  GameState* state_;

  DISALLOW_COPY_AND_ASSIGN(Player);
};

}  // namespace ulti

#endif  // ULTI_LIBULTI_PLAYER_H
