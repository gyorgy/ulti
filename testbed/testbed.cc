// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#include <testbed/testbed.h>

#include <iostream>

namespace ulti {
namespace testbed {

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
  // TODO(gyorgy): Implement it.
  std::cout << "game started." << std::endl;
}

void Testbed::Deal() {
  std::cout << "dealing..." << std::endl;
  // TODO(gyorgy): Implement it.
  std::cout << "dealing done." << std::endl;
}

void Testbed::RunAuction() {
  std::cout << "running auction..." << std::endl;
  // TODO(gyorgy): Implement it.
  std::cout << "auction done." << std::endl;
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
