// Copyright (c) 2017 Gyorgy Abonyi. All rights reserved.

#ifndef ULTI_LIBULTI_MACROS_H
#define ULTI_LIBULTI_MACROS_H

#define DISALLOW_COPY_AND_ASSIGN(clazz) \
  clazz(const clazz&) = delete; \
  clazz& operator =(const clazz&) = delete

#endif // ULTI_LIBULTI_MACROS_H
