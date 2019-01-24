#include "pairhmm_common.h"
#define str(s) #s
#define xstr(s) str(s)

#define TEST_INTRINSICS()						\
{									\
    Context<MAIN_TYPE> ctx;						\
    UNION_TYPE in, mask, out;						\
    IF_MAIN_TYPE i1, i2, c1;						\
    MAIN_TYPE zero;							\
    zero = ctx._(0.0);							\
    i1.i = 0x88888888;							\
    c1.i = 'N';								\
    in.d = LOAD((MAIN_TYPE *)testvec_g);				\
    mask.d = LOAD((MAIN_TYPE *)testmask_g);				\
    printf("##### " xstr(MAIN_TYPE) " VEC_EXTRACT_UNIT #####\n");	\
    print_vec(&in.i);							\
    i2.i = VEC_EXTRACT_UNIT(in.i, SHIFT_CONST1);			\
    printf(FMT"\n", i2.i);						\
    print_vec(&in.i);							\
    printf("##### " xstr(MAIN_TYPE) " VEC_INSERT_UNIT #####\n");	\
    printf(FMT"\n", i1.i);						\
    print_vec(&in.i);							\
    out.i = VEC_INSERT_UNIT(in.i, i1.i, SHIFT_CONST3);			\
    print_vec(&out.i);							\
    print_vec(&in.i);							\
    printf("##### " xstr(MAIN_TYPE) " VEC_ADD #####\n");		\
    print_vec(&in.i);							\
    out.d = VEC_ADD(in.d, in.d);					\
    print_vec(&out.i);							\
    print_vec(&in.i);							\
    printf("##### " xstr(MAIN_TYPE) " VEC_SUB #####\n");		\
    print_vec(&in.i);							\
    out.d = VEC_SUB(in.d, in.d);					\
    print_vec(&out.i);							\
    print_vec(&in.i);							\
    printf("##### " xstr(MAIN_TYPE) " VEC_MUL #####\n");		\
    print_vec(&in.i);							\
    out.d = VEC_MUL(in.d, in.d);					\
    print_vec(&out.i);							\
    print_vec(&in.i);							\
    printf("##### " xstr(MAIN_TYPE) " VEC_DIV #####\n");		\
    print_vec(&in.i);							\
    out.d = VEC_DIV(in.d, in.d);					\
    print_vec(&out.i);							\
    print_vec(&in.i);							\
    printf("##### " xstr(MAIN_TYPE) " VEC_SET1_VAL #####\n");		\
    printf(FMT"\n", i1.i);						\
    out.d = VEC_SET1_VAL(i1.f);						\
    print_vec(&out.i);							\
    printf("##### " xstr(MAIN_TYPE) " VEC_BLENDV #####\n");		\
    printf(FMT"\n", i1.i);						\
    print_vec(&in.i);							\
    print_vec(&mask.i);							\
    out.d = VEC_BLENDV(in.d, VEC_SET1_VAL(i1.f), mask.d);		\
    print_vec(&out.i);							\
    print_vec(&in.i);							\
    printf("##### " xstr(MAIN_TYPE) " VEC_POPCVT_CHAR #####\n");	\
    printf(FMT"\n", c1.i);						\
    out.d = VEC_POPCVT_CHAR(c1.i);					\
    print_vec(&out.i);							\
    printf("##### " xstr(MAIN_TYPE) " VEC_SHIFT_LEFT_1BIT #####\n");	\
    print_vec(&in.i);							\
    VEC_SHIFT_LEFT_1BIT(in.i);						\
    print_vec(&in.i);							\
    printf("##### " xstr(MAIN_TYPE) " VEC_SET_LSE  #####\n");		\
    printf(FMT"\n", i1.i);						\
    out.d = VEC_SET_LSE(i1.f);						\
    print_vec(&out.i);							\
    printf("##### " xstr(MAIN_TYPE) " VEC_128_SHIFT_LEFT  #####\n");	\
    print_vec(&in.i);							\
    out.i = VEC_128_SHIFT_LEFT(in.i, SHIFT_CONST2);			\
    print_vec(&out.i);							\
    printf("###########################################\n");		\
}


#define TEST_APIS()							\
{									\
    Context<MAIN_TYPE> ctx;						\
    UNION_TYPE in, mask, out;						\
    IF_MAIN_TYPE i1, i2, c1;						\
    MAIN_TYPE zero;							\
    zero = ctx._(0.0);							\
    i1.i = 0x88888888;							\
    c1.i = 'N';								\
    in.d = LOAD((MAIN_TYPE *)testvec_g);				\
    mask.d = LOAD((MAIN_TYPE *)testmask_g);				\
    printf("##### " xstr(MAIN_TYPE) " _vector_shift  #####\n");		\
    print_vec(&in.i);							\
    printf(FMT"\n", i1.i);						\
    CONCAT(CONCAT(_vector_shift,SIMD_ENGINE), PRECISION)(in, i1.f, i2.f);		\
    printf(FMT"\n", i2.i);						\
    print_vec(&in.i);							\
    printf("##### " xstr(MAIN_TYPE) " _vector_shift_last  #####\n");	\
    printf(FMT"\n", i2.i);						\
    print_vec(&in.i);							\
    CONCAT(CONCAT(_vector_shift_last,SIMD_ENGINE), PRECISION)(in, i2.f);\
    print_vec(&in.i);							\
    printf("###########################################\n");		\
}

