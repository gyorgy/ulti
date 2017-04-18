// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_BITS_H
#define ULTI_LIBULTI_BITS_H

#include <libulti/common.h>

namespace ulti {

inline int PopCount(uint32 bits) { return __builtin_popcountl(bits); }

inline int CountTrailingZeros(uint32 bits) { return __builtin_ctzl(bits); }

}  // namespace ulti

#endif // ULTI_LIBULTI_BITS_H
