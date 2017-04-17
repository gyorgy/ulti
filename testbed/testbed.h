// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_TESTBED_TESTBED_H
#define ULTI_TESTBED_TESTBED_H

#include <libulti/macros.h>
#include <libulti/player.h>

namespace ulti {
namespace testbed {

class Testbed final {
public:
  Testbed(Player* player_1, Player* player_2, Player* player_3);

  int RunOnce();

private:
  DISALLOW_COPY_AND_ASSIGN(Testbed);

  Player* players_[3];

  void StartGame();
  void Deal();
  void RunAuction();
  void RunGame();
  void FinishGame();
};

}  // namespace testbed
}  // namespace ulti

#endif  // ULTI_TESTBED_TESTBED_H
