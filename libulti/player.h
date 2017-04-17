// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_PLAYER_H
#define ULTI_LIBULTI_PLAYER_H

#include <libulti/macros.h>

namespace ulti {

class Engine;

class Player final {
public:
  Player(Engine* engine);

private:
  DISALLOW_COPY_AND_ASSIGN(Player);

  Engine* engine_;
};

}  // namespace ulti

#endif  // ULTI_LIBULTI_PLAYER_H
