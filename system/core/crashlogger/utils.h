// Copyright 2016 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include <magenta/syscalls-types.h>

extern const char* cl_basename(const char* file);

extern void do_print_error(const char* file, int line, const char* fmt, ...);

extern void do_print_mx_error(const char* file, int line, const char* what, mx_status_t status);

#define print_error(fmt...) \
  do { \
    do_print_error(__FILE__, __LINE__, __func__, fmt); \
  } while (0)

#define print_mx_error(what, status) \
  do { \
    do_print_mx_error(__FILE__, __LINE__, \
                      (what), static_cast<mx_status_t>(status)); \
  } while (0)
