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

#ifndef HT_TIMER_H
#define HT_TIMER_H

/*------------------------------------------------------------------ TYPEDEFS */

#ifndef u64
  #ifdef __GNUC__
    #define u64 unsigned long long
  #elif defined _MSC_VER || defined __WATCOM__
    #define u64 unsigned __int64
  #else
    #define u64 unsigned long
  #endif
#endif
typedef int HTTimerStaticAssert_u64[sizeof (u64) == 8 ? 1 : -1];

/*----------------------------------------------------------------- FUNCTIONS */

#ifdef __cplusplus
extern "C" {
#endif

u64 htGetTicks(void);
u64 htGetTicksPerSecond(void);

#ifdef __cplusplus
}
#endif

#endif
