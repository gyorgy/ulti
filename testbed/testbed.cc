// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#include <testbed/testbed.h>

#include <iostream>

#include <libulti/cards.h>

namespace ulti {
namespace testbed {

static const Cards kDeck[32] = {
  Cards(Cards::VII << Cards::ACCORNS),
  Cards(Cards::VIII << Cards::ACCORNS),
  Cards(Cards::IX << Cards::ACCORNS),
  Cards(Cards::UNDER << Cards::ACCORNS),
  Cards(Cards::OVER << Cards::ACCORNS),
  Cards(Cards::KING << Cards::ACCORNS),
  Cards(Cards::X << Cards::ACCORNS),
  Cards(Cards::ACE << Cards::ACCORNS),
  Cards(Cards::VII << Cards::LEAVES),
  Cards(Cards::VIII << Cards::LEAVES),
  Cards(Cards::IX << Cards::LEAVES),
  Cards(Cards::UNDER << Cards::LEAVES),
  Cards(Cards::OVER << Cards::LEAVES),
  Cards(Cards::KING << Cards::LEAVES),
  Cards(Cards::X << Cards::LEAVES),
  Cards(Cards::ACE << Cards::LEAVES),
  Cards(Cards::VII << Cards::HEARTS),
  Cards(Cards::VIII << Cards::HEARTS),
  Cards(Cards::IX << Cards::HEARTS),
  Cards(Cards::UNDER << Cards::HEARTS),
  Cards(Cards::OVER << Cards::HEARTS),
  Cards(Cards::KING << Cards::HEARTS),
  Cards(Cards::X << Cards::HEARTS),
  Cards(Cards::ACE << Cards::HEARTS),
  Cards(Cards::VII << Cards::BALLS),
  Cards(Cards::VIII << Cards::BALLS),
  Cards(Cards::IX << Cards::BALLS),
  Cards(Cards::UNDER << Cards::BALLS),
  Cards(Cards::OVER << Cards::BALLS),
  Cards(Cards::KING << Cards::BALLS),
  Cards(Cards::X << Cards::BALLS),
  Cards(Cards::ACE << Cards::BALLS)
};

static Cards AggregateCards(const Cards (&deck)[32], int offset, int size) {
  Cards cards;
  for (int i = offset; i < offset + size; ++i) {
    cards.Add(deck[i]);
  }
  return cards;
}

static std::string BidToString(const Bids& bids) {
  std::string result;
  if (bids.IsOpen()) {
    result.append("open ");
  }
  if (bids.IsHearts()) {
    result.append("hearts ");
  }
  if (bids.IsParti()) {
    result.append("parti ");
  }
  if (bids.IsUlti()) {
    result.append("ulti ");
  }
  if (bids.IsFortyHundred()) {
    result.append(" 40-100");
  }
  if (bids.IsBetli()) {
    result.append("betli ");
  }
  if (bids.IsDurchmars()) {
    result.append("durschmars ");
  }
  if (bids.IsTwentyHundred()) {
    result.append(" 20-100 ");
  }
  return result;
}

Testbed::Testbed(Player* player_1, Player* player_2, Player* player_3)
  : players_{player_1, player_2, player_3} {}

int Testbed::RunOnce() {
  StartGame();
  Deal();
  RunAuction();
  RunGame();
  FinishGame();
  return 0;
}

void Testbed::StartGame() {
  std::cout << "starting game..." << std::endl;
  for (int player = 0; player < 3; ++player) {
    players_[player]->StartGame(player);
  }
  std::cout << "game started." << std::endl;
}

void Testbed::Deal() {
  std::cout << "dealing..." << std::endl;
  Cards shuffled_deck[32];
  for (int i = 0; i < 32; ++i) {
    int j = rand() % (i + 1);
    if (i != j) {
      shuffled_deck[i] = shuffled_deck[j];
    }
    shuffled_deck[j] = kDeck[i];
  }
  players_[0]->Deal(AggregateCards(shuffled_deck, 0, 7));
  players_[1]->Deal(AggregateCards(shuffled_deck, 7, 5));
  players_[2]->Deal(AggregateCards(shuffled_deck, 12, 5));
  players_[0]->Deal(AggregateCards(shuffled_deck, 17, 5));
  players_[1]->Deal(AggregateCards(shuffled_deck, 22, 5));
  players_[2]->Deal(AggregateCards(shuffled_deck, 27, 5));
  std::cout << "dealing done." << std::endl;
}

void Testbed::RunAuction() {
  std::cout << "running auction..." << std::endl;
  int current_player = 0;
  int pass_count = 0;
  while (pass_count < 3) {
    if (talon_.Count() == 2) {
      if (players_[current_player]->WouldBid()) {
        pass_count = 0;
        players_[current_player]->Deal(talon_);
        talon_.Clear();
        continue;
      } else {
        std::cout << current_player << " passes" << std::endl;
        pass_count += 1;
      }
    } else {
      players_[current_player]->GetBidAndTalon(&bid_, &talon_);
      bidding_player_ = current_player;
      for (auto player : players_) {
        player->NotifyBid(bidding_player_, bid_);
      }
      std::cout << bidding_player_ << " bids " << BidToString(bid_) << std::endl;
    }
    current_player = (current_player + 1) % 3;
  }
  std::cout << "auction done." << std::endl;
  std::cout << bidding_player_ << " plays " << BidToString(bid_) << std::endl;
}

void Testbed::RunGame() {
  std::cout << "running game..." << std::endl;
  // TODO(gyorgy): Implement it.
  std::cout << "game done." << std::endl;
}

void Testbed::FinishGame() {
  std::cout << "finishing game..." << std::endl;
  // TODO(gyorgy): Implement it.
  std::cout << "game finished." << std::endl;
}

}  // namespace testbed
}  // namespace ulti
