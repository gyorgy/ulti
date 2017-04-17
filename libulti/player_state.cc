// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#include <libulti/player_state.h>

namespace ulti {

PlayerState::PlayerState() {}

void PlayerState::Reset() {
  hand_.Clear();
}

void PlayerState::Deal(const Cards& cards) {
  hand_.Add(cards);
}

void PlayerState::RemoveFromHand(const Cards& cards) {
  hand_.Remove(cards);
}

}  // namespace ulti
