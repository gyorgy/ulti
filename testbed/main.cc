// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#include <libkubler/kubler.h>
#include <testbed/testbed.h>

int main(int argc, char** argv) {
  ulti::kubler::Kubler engine_1;
  ulti::Player player_1(&engine_1);
  ulti::kubler::Kubler engine_2;
  ulti::Player player_2(&engine_2);
  ulti::kubler::Kubler engine_3;
  ulti::Player player_3(&engine_3);
  ulti::testbed::Testbed testbed(&player_1, &player_2, &player_3);
  return testbed.RunOnce();
}