// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_ENGINE_H
#define ULTI_LIBULTI_ENGINE_H

#include <libulti/macros.h>

namespace ulti {

class Engine {
public:
  Engine();
  virtual ~Engine();

private:
  DISALLOW_COPY_AND_ASSIGN(Engine);
};

}  // namespace ulti

#endif  // ULTI_LIBULTI_ENGINE_H
