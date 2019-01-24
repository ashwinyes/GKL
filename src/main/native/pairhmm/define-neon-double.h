/*Copyright (c) 2012 The Broad Institute

*Permission is hereby granted, free of charge, to any person
*obtaining a copy of this software and associated documentation
*files (the "Software"), to deal in the Software without
*restriction, including without limitation the rights to use,
*copy, modify, merge, publish, distribute, sublicense, and/or sell
*copies of the Software, and to permit persons to whom the
*Software is furnished to do so, subject to the following
*conditions:

*The above copyright notice and this permission notice shall be
*included in all copies or substantial portions of the Software.

*THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
*EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
*OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
*NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
*HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
*WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
*THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <arm_neon.h>

#ifdef PRECISION
#undef PRECISION
#undef MAIN_TYPE
#undef MAIN_TYPE_SIZE
#undef UNION_TYPE
#undef IF_MAIN_TYPE
#undef SHIFT_CONST1
#undef SHIFT_CONST2
#undef SHIFT_CONST3
#undef SIMD_TYPE
#undef NEON_LENGTH
#undef HAP_TYPE
#undef MASK_TYPE
#undef MASK_ALL_ONES

#undef VEC_EXTRACT_UNIT
#undef VEC_INSERT_UNIT
#undef VEC_ADD
#undef VEC_SUB
#undef VEC_MUL
#undef VEC_DIV
#undef VEC_BLENDV
#undef VEC_SET1_VAL
#undef VEC_POPCVT_CHAR
#undef VEC_SET_LSE
#undef MASK_VEC
#undef VEC_SHIFT_LEFT_1BIT
#undef MASK_ALL_ONES
#undef BITMASK_VEC
#undef VEC_128_SHIFT_LEFT
#endif

#define NEON
#define PRECISION d

#define MAIN_TYPE double
#define MAIN_TYPE_SIZE 64
#define UNION_TYPE mix_D128
#define IF_MAIN_TYPE IF_64
#define SHIFT_CONST1 1
#define SHIFT_CONST2 8
#define SHIFT_CONST3 0
#define SIMD_TYPE float64x2_t
#define NEON_LENGTH 2
#define HAP_TYPE UNION_TYPE
#define MASK_TYPE uint64_t
#define MASK_ALL_ONES 0xFFFFFFFFFFFFFFFFL
#define MASK_VEC MaskVec_D

#define VEC_EXTRACT_UNIT(__v1, __im)            \
    vgetq_lane_s64(__v1, __im)

#define VEC_INSERT_UNIT(__v1,__ins,__im)        \
    vsetq_lane_s64(__ins, __v1,__im)

#define VEC_ADD(__v1, __v2)                     \
    vaddq_f64(__v1, __v2)

#define VEC_SUB(__v1, __v2)                     \
    vsubq_f64(__v1, __v2)

#define VEC_MUL(__v1, __v2)                     \
    vmulq_f64(__v1, __v2)

#define VEC_DIV(__v1, __v2)                     \
    vdivq_f64(__v1, __v2)

#define VEC_BLENDV(__v1, __v2, __maskV)         \
    vreinterpretq_f64_s64(vbslq_s64(vcgeq_u64(vreinterpretq_u64_f64(__maskV), vdupq_n_u64(0x8000000000000000)),  \
                          vreinterpretq_s64_f64(__v2), vreinterpretq_s64_f64(__v1)))

#define VEC_SET1_VAL(__val)                     \
    vdupq_n_f64(__val)

#define VEC_POPCVT_CHAR(__ch)                   \
    vcvtq_f64_s64(vdupq_n_s64(__ch))

#define VEC_SET_LSE(__val)                      \
    vsetq_lane_f64(__val, vdupq_n_f64(zero), 0)

#define VEC_SHIFT_LEFT_1BIT(__vs)               \
    __vs = vshlq_n_s64(__vs, 1)

#define VEC_128_SHIFT_LEFT(__vs, __im)               \
    vreinterpretq_s64_s8(vextq_s8(vdupq_n_s8(0), vreinterpretq_s8_s64(__vs), 16 - (__im)))


class BitMaskVec_sse_double {

    MASK_VEC combined_ ;
    public:
    inline MASK_TYPE& getLowEntry(int index) {
        return combined_.masks[index] ;
    }
    inline MASK_TYPE& getHighEntry(int index) {
        return combined_.masks[NEON_LENGTH/2+index] ;
    }

    inline const SIMD_TYPE& getCombinedMask() {
        return combined_.vecf ;
    }

    inline void shift_left_1bit() {
        VEC_SHIFT_LEFT_1BIT(combined_.vec) ;
    }

} ;

#define BITMASK_VEC BitMaskVec_sse_double

