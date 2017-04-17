// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_TESTBED_TESTBED_H
#define ULTI_TESTBED_TESTBED_H

#include <libulti/cards.h>
#include <libulti/macros.h>
#include <libulti/player.h>
#include <libulti/bids.h>

namespace ulti {
namespace testbed {

class Testbed final {
public:
  Testbed(Player* player_1, Player* player_2, Player* player_3);

  int RunOnce();

private:
  Player* players_[3];
  Cards talon_;
  Bids bid_;
  int bidding_player_;

  void StartGame();
  void Deal();
  void RunAuction();
  void RunGame();
  void FinishGame();

  DISALLOW_COPY_AND_ASSIGN(Testbed);
};

}  // namespace testbed
}  // namespace ulti

#endif  // ULTI_TESTBED_TESTBED_H
