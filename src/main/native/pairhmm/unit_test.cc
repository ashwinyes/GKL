#include <stdint.h>
#include <stdio.h>
#include "pairhmm_common.h"
#include "Context.h"
#include "debug.h"

uint8_t testvec_g[16]  = {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf};
uint8_t testmask_g[16] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};

#if defined(AARCH64)
#define SIMD_ENGINE neon
#define SIMD_ENGINE_NEON
#else
#define SIMD_ENGINE sse
#define SIMD_ENGINE_SSE
#endif


#include "template.h"

#define FMT "0x%016lx"
#if defined(AARCH64)
#define LOAD vld1q_f64
#include "define-neon-double.h"
#else
#define LOAD _mm_load_pd
#include "define-sse-double.h"
#endif
#include "shift_template.c"
#include "pairhmm-template-kernel.cc"
#include "unit_test.h"

static void test_double(void)
{
    TEST_INTRINSICS();
    TEST_APIS();
}

#undef TEST
#undef LOAD
#undef FMT
#define FMT "0x%08x"
#if defined(AARCH64)
#define LOAD vld1q_f32
#include "define-neon-float.h"
#else
#define LOAD _mm_load_ps
#include "define-sse-float.h"
#endif
#include "shift_template.c"
#include "pairhmm-template-kernel.cc"
#include "unit_test.h"

static void test_float(void)
{
    TEST_INTRINSICS();
    TEST_APIS();
}

int main()
{
    test_float();
    test_double();
}

