// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#include <libulti/player.h>

#include <libulti/game_state.h>
#include <libulti/engine.h>

namespace ulti {

Player::Player(Engine *engine)
  : engine_(engine),
    state_(new GameState()) {}

Player::~Player() {
  delete state_;
}

void Player::StartGame(int self_id) {
  state_->Reset(self_id);
  engine_->Start();
}

void Player::Deal(const Cards& cards) {
  state_->Deal(cards);
}

bool Player::WouldBid() {
  return engine_->WouldBid(*state_);
}

void Player::GetBidAndTalon(Bids* bid, Cards* talon) {
  Bids new_bid;
  Cards new_talon;
  engine_->GetBidAndTalon(*state_, &new_bid, &new_talon);
  state_->SetBidAndTalon(state_->GetSelfId(), new_bid, new_talon);
  *bid = new_bid;
  *talon = new_talon;
}

void Player::NotifyBid(int bidding_player, const Bids& bid) {
  state_->SetBidAndTalon(bidding_player, bid, Cards(0UL));
}

}  // namespace ulti
