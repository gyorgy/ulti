// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_BITS_H
#define ULTI_LIBULTI_BITS_H

#include <cstdint>

namespace ulti {

inline int PopCount(uint_fast32_t bits) { return __builtin_popcountl(bits); }

inline int CountTrailingZeros(uint_fast32_t bits) { return __builtin_ctzl(bits); }

}  // namespace ulti

#endif // ULTI_LIBULTI_BITS_H
