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

#include <mach/mach_time.h>
#include "timer.h"

/*----------------------------------------------------------------- FUNCTIONS */

u64
htGetTicks(void) {
  return mach_absolute_time();
}

u64
htGetTicksPerSecond(void) {
  mach_timebase_info_data_t info = {0};
  mach_timebase_info(&info);
  /* mach_timebase_info_data_t scales mach_absolute_time() to nanoseconds */
  return 1000000000UL * info.numer / info.denom;
}