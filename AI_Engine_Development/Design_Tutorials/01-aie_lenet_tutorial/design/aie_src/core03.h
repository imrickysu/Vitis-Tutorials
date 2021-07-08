/* (c) Copyright 2021 Xilinx, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#ifndef CORE_03_H_
#define CORE_03_H_

#include <stdint.h>
#include <adf.h>

#ifndef ROW_A_3 
#define ROW_A_3 8
#endif

#ifndef COL_A_3
#define COL_A_3 264
#endif

#ifndef COL_B_3
#define COL_B_3 64
#endif 

#ifndef COL_C_3
#define COL_C_3 128
#endif 



#ifndef INLINE
#ifndef INLINE_DECL
#define INLINE_DECL
#endif

void core03(
        const int RowA_tile,
        const int ColA_tile,
        const int ColB_tile,
        const int tileX_A,
        const int tileY_A,
        const int tileX_C,
        const int tileY_C,
        int8_t* A_in,
        //int8_t* B_in,
        int8_t* C_out,
        int shift
);

void core03_top(input_window_int32 *in1, 
                //input_window_int32 *in2,
                output_window_int32 *out);

#else
#  ifndef INLINE_DECL
#  ifdef __llvm__
#    define INLINE_DECL inline __attribute__((always_inline)) 
#  else
#  define INLINE_DECL inline
#  endif
#  endif
#  undef INLINE 
#  include "core03.cc"
#  define INLINE
# endif


#endif 
