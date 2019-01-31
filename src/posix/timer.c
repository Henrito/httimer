/* MIT License
 * 
 * Copyright (c) 2019 Henry To
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*------------------------------------------------------------------- HEADERS */

#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include "timer.h"

/*-------------------------------------------------------------------- MACROS */

#ifdef CLOCK_MONOTONIC_RAW
  #define CLOCK_MODE CLOCK_MONOTONIC_RAW
#elif defined CLOCK_MONOTONIC_PRECISE
  #define CLOCK_MODE CLOCK_MONOTONIC_PRECISE
#elif defined CLOCK_HIGHRES
  #define CLOCK_MODE CLOCK_HIGHRES
#elif defined CLOCK_MONOTONIC
  #define CLOCK_MODE CLOCK_MONOTONIC
#else
  #define CLOCK_MODE CLOCK_REALTIME
#endif

/*----------------------------------------------------------------- FUNCTIONS */

u64
htGetTicks(void) {
  struct timespec spec = {0};
  struct timespec ticks = {0};
  clock_getres(CLOCK_MODE, &spec);
  clock_gettime(CLOCK_MODE, &ticks);
  return (u64) ((1000000000L * ticks.tv_sec + ticks.tv_nsec) / spec.tv_nsec);
}

u64
htGetTicksPerSecond(void) {
  struct timespec ticks = {0};
  clock_getres(CLOCK_MODE, &ticks);
  return (u64) (1000000000L / ticks.tv_nsec);
}
