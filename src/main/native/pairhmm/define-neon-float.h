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
#undef SET_VEC_ZERO
#undef VEC_ADD
#undef VEC_SUB
#undef VEC_MUL
#undef VEC_DIV
#undef VEC_BLENDV
#undef VEC_SET1_VAL
#undef VEC_POPCVT_CHAR
#undef VEC_SET_LSE
#undef SHIFT_HAP
#undef MASK_VEC
#undef VEC_SHIFT_LEFT_1BIT
#undef MASK_ALL_ONES
#undef BITMASK_VEC
#undef VEC_128_SHIFT_LEFT
#endif

#define NEON
#define PRECISION s

#define MAIN_TYPE float
#define MAIN_TYPE_SIZE 32
#define UNION_TYPE mix_F128
#define IF_MAIN_TYPE IF_32
#define SHIFT_CONST1 3
#define SHIFT_CONST2 4
#define SHIFT_CONST3 0
#define SIMD_TYPE float32x4_t
#define NEON_LENGTH 4
#define HAP_TYPE UNION_TYPE
#define MASK_TYPE uint32_t
#define MASK_ALL_ONES 0xFFFFFFFF
#define MASK_VEC MaskVec_F

#define VEC_EXTRACT_UNIT(__v1, __im)            \
    vgetq_lane_s32(__v1, __im)

#define VEC_INSERT_UNIT(__v1,__ins,__im)        \
    vsetq_lane_s32(__ins,__v1,__im)

#define VEC_ADD(__v1, __v2)                     \
    vaddq_f32(__v1, __v2)

#define VEC_SUB(__v1, __v2)                     \
    vsubq_f32(__v1, __v2)

#define VEC_MUL(__v1, __v2)                     \
    vmulq_f32(__v1, __v2)

#define VEC_DIV(__v1, __v2)                     \
    vdivq_f32(__v1, __v2)

#define VEC_BLENDV(__v1, __v2, __maskV)         \
    vreinterpretq_f32_s32(vbslq_s32(vcgeq_u32(vreinterpretq_u32_f32(__maskV), vdupq_n_u32(0x80000000)),  \
                          vreinterpretq_s32_f32(__v2), vreinterpretq_s32_f32(__v1)))

#define VEC_SET1_VAL(__val)                     \
    vdupq_n_f32(__val)

#define VEC_POPCVT_CHAR(__ch)                   \
    vcvtq_f32_s32(vdupq_n_s32(__ch))

#define VEC_SET_LSE(__val)                      \
    vsetq_lane_f32(__val, vdupq_n_f32(zero), 0)

#define VEC_SHIFT_LEFT_1BIT(__vs)               \
    __vs = vshlq_n_s32(__vs, 1)

#define VEC_128_SHIFT_LEFT(__vs, __im)          \
    vreinterpretq_s32_s8(vextq_s8(vdupq_n_s8(0), vreinterpretq_s8_s32(__vs), 16 - (__im)))

class BitMaskVec_neon_float {

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

#define BITMASK_VEC BitMaskVec_neon_float
