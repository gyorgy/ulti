// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#include <libkubler/kubler.h>

#include <libulti/game_state.h>

namespace ulti {
namespace kubler {

Kubler::Kubler() {}

Kubler::~Kubler() {}

void Kubler::Start() {}

bool Kubler::WouldBid(const GameState& state) {
  // TODO(gyorgy): Implement it.
  return false;
}

void Kubler::GetBidAndTalon(const GameState& state, Bids* bid, Cards* talon) {
  // TODO(gyorgy): Implement it.
  Cards hand(state.GetHand());
  Cards new_talon(hand.GetRandomCard());
  hand.Remove(new_talon);
  new_talon.Add(hand.GetRandomCard());
  *bid = Bids(Bids::PARTI);
  *talon = new_talon;
}

}  // namespace kubler
}  // namespace ulti
