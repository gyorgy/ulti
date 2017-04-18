// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_COMMON_H
#define ULTI_LIBULTI_COMMON_H

#include <cstdint>

#define DISALLOW_COPY_AND_ASSIGN(clazz) \
  clazz(const clazz&) = delete; \
  clazz& operator =(const clazz&) = delete

namespace ulti {

typedef uint_fast32_t uint32;

}
#endif // ULTI_LIBULTI_COMMON_H
