#ifndef DEBUG_PAIRHMM
#define DEBUG_PAIRHMM

static inline void print_vec(void *vec)
{
    uint32_t *veci = (uint32_t *)vec;
    printf("0x%08x %08x %08x %08x\n", veci[3], veci[2], veci[1], veci[0]);
}

#if (MAIN_TYPE == float)
#define PRINT_FMT "0x%08x"
#define INT_TYPE uint32_t
#else
#define PRINT_FMT "0x%016lx"
#define INT_TYPE uint64_t
#endif

static inline void print_int(INT_TYPE num)
{
    printf(PRINT_FMT"\n", num);
}


#endif
