// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_PLAYER_STATE_H
#define ULTI_LIBULTI_PLAYER_STATE_H

#include <libulti/macros.h>

namespace ulti {

class PlayerState final {
public:
  PlayerState();

  void Reset();

private:
  DISALLOW_COPY_AND_ASSIGN(PlayerState);
};

}  // namespace ulti

#endif // ULTI_LIBULTI__PLAYER_STATE_H
