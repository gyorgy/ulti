// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_PLAYER_H
#define ULTI_LIBULTI_PLAYER_H

#include <vector>

#include <libulti/bids.h>
#include <libulti/cards.h>
#include <libulti/common.h>

namespace ulti {

class Engine;
class GameState;

class Player final {
public:
  Player(Engine* engine);
  ~Player();

  void StartGame(int self_id);
  void Deal(const Cards& cards);
  bool WouldBid();
  Bids GetBid();
  Cards GetTalon();
  void NotifyBid(int bidding_player, const Bids& bid);
  Cards::Suit GetTrump();
  void StartPlay(int bidding_player, const Bids& bid, Cards::Suit trump);
  Cards GetCall(int calling_player, const std::vector<Cards>& calls);
  int GetNumForties();
  int GetNumTwenties();
  void NotifyAnnouncements(int player, int forties, int twenties);
  int GetKontras(std::vector<Bids>* kontras);
  void NotifyKontras(int player, const std::vector<Bids>& kontras);
  int GetRekontras(const std::vector<Bids>& kontras, std::vector<Bids>* rekontras);
  void NotifyRekontras(int player, const std::vector<Bids>& rekontras);
  void NotifyCall(int current_player, const Cards& call);
  void NotifyTrick(int taking_player, const std::vector<Cards>& calls);
  void NotifyResult(const std::vector<Bids>& won_bids, const std::vector<Bids>& lost_bids);

private:
  Engine* engine_;
  GameState* state_;

  DISALLOW_COPY_AND_ASSIGN(Player);
};

}  // namespace ulti

#endif  // ULTI_LIBULTI_PLAYER_H
