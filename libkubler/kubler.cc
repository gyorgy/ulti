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

Bids Kubler::GetBid(const GameState& state) {
  // TODO(gyorgy): Implement it.
  return Bids(Bids::PARTI);
}

Cards Kubler::GetTalon(const GameState& state) {
  // TODO(gyorgy): Implement it.
  Cards hand(state.GetSelfState().GetHand());
  Cards talon(hand.GetRandomCard());
  hand.Remove(talon);
  talon.Add(hand.GetRandomCard());
  return talon;
}

Cards::Suit Kubler::GetTrump() {
  // TODO(gyorgy): Implement it.
  return Cards::ACCORNS;
}

Cards Kubler::GetCall(const GameState& state, int calling_player, const std::vector<Cards>& calls) {
  // TODO(gyorgy): Implement it.
  return(state.GetSelfState().GetHand().GetRandomCard());
}

}  // namespace kubler
}  // namespace ulti
