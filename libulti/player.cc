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
  state_->GetSelfState()->Deal(cards);
}

bool Player::WouldBid() {
  return engine_->WouldBid(*state_);
}

Bids Player::GetBid() {
  const Bids bid = engine_->GetBid(*state_);
  state_->SetBid(state_->GetSelfId(), bid);
  return bid;
}

Cards Player::GetTalon() {
  const Cards talon = engine_->GetTalon(*state_);
  state_->SetTalon(state_->GetSelfId(), talon);
  return talon;
}

void Player::NotifyBid(int bidding_player, const Bids& bid) {
  state_->SetBid(bidding_player, bid);
  if (bidding_player != state_->GetSelfId()) {
    state_->SetTalon(bidding_player, Cards(0U));
  }
}

Cards::Suit Player::GetTrump() {
  return engine_->GetTrump();
}

void Player::StartPlay(int bidding_player, const Bids& bid, Cards::Suit trump) {
  state_->SetBid(bidding_player, bid);
  if (bidding_player != state_->GetSelfId()) {
    state_->SetTalon(bidding_player, Cards(0U));
  }
  state_->SetTrump(trump);
}

Cards Player::GetCall(int calling_player, const std::vector<Cards>& calls) {
  Cards call(engine_->GetCall(*state_, calling_player, calls));
  state_->GetSelfState()->RemoveFromHand(call);
  return call;
}

int Player::GetNumForties() {
  // TODO(gyorgy): Implement it.
  return 0;
}

int Player::GetNumTwenties() {
  // TODO(gyorgy): Implement it.
  return 0;
}

void Player::NotifyAnnouncements(int player, int forties, int twenties) {
  // TODO(gyorgy): Implement it.
}

int Player::GetKontras(std::vector<Bids>* kontras) {
  kontras->clear();
  // TODO(gyorgy): Implement it.
  return kontras->size();
}

void Player::NotifyKontras(int player, const std::vector<Bids>& kontras) {
  // TODO(gyorgy): Implement it.
}

int Player::GetRekontras(const std::vector<Bids>& kontras, std::vector<Bids>* rekontras) {
  rekontras->clear();
  // TODO(gyorgy): Implement it.
  return rekontras->size();
}

void Player::NotifyRekontras(int player, const std::vector<Bids>& rekontras) {
  // TODO(gyorgy): Implement it.
}

void Player::NotifyCall(int current_player, const Cards& call) {
  // TODO(gyorgy): Implement it.
}

void Player::NotifyTrick(int taking_player, const std::vector<Cards>& calls) {
  // TODO(gyorgy): Implement it.
}

void Player::NotifyResult(const std::vector<Bids>& won_bids, const std::vector<Bids>& lost_bids) {
  // TODO(gyorgy): Implement it.
}

}  // namespace ulti
