// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_TESTBED_TESTBED_H
#define ULTI_TESTBED_TESTBED_H

#include <libulti/player.h>

namespace ulti {
namespace testbed {

class Testbed final {
public:
  Testbed(Player* player_1, Player* player_2, Player* player_3);

  int RunOnce();

private:
};

}  // namespace testbed
}  // namespace ulti

#endif  // ULTI_TESTBED_TESTBED_H
