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


#ifndef TEMPLATES_H_
#define TEMPLATES_H_

#include <arm_neon.h>

#include "headers.h"

#define ALIGNED __attribute__((aligned(32)))

typedef union __attribute__((aligned(32))) {
        ALIGNED float32x4_t ALIGNED d;
        ALIGNED float  ALIGNED f[4];
        ALIGNED int32x4_t ALIGNED i;
} ALIGNED mix_F128 ALIGNED;

typedef union ALIGNED {
  int32x4_t vec ;
  float32x4_t vecf ;
  uint32_t masks[4] ;
} MaskVec_F ;

typedef union ALIGNED
{
        ALIGNED int    ALIGNED i;
        ALIGNED float  ALIGNED f;
} ALIGNED IF_32 ALIGNED;


typedef union __attribute__((aligned(32))) {
        ALIGNED float64x2_t ALIGNED d;
        ALIGNED double  ALIGNED f[2];
        ALIGNED int64x2_t ALIGNED i;
} ALIGNED mix_D128 ALIGNED;

typedef union ALIGNED {
  int64x2_t vec ;
  float64x2_t vecf ;
  uint64_t masks[2] ;
} MaskVec_D ;

typedef union ALIGNED
{
        ALIGNED int64_t ALIGNED i;
        ALIGNED double  ALIGNED f;
} ALIGNED IF_64 ALIGNED;

#endif


