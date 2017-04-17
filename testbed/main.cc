// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#include <testbed/testbed.h>

int main(int argc, char** argv) {
  ulti::testbed::Testbed testbed;
  return testbed.RunOnce();
}