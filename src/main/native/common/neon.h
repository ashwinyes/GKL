#ifndef _NEON_H_
#define _NEON_H_

#include <stdint.h>

#define	FLUSH_TO_ZERO_SHIFT		(24)
#define	FLUSH_TO_ZERO_MASK		(1U << 24)

static inline int get_ftz(void)
{
    uint32_t fpcr;

    __asm__ __volatile__("mrs %0,fpcr" : "=r" (fpcr));

    if (fpcr & FLUSH_TO_ZERO_MASK)
        return 1;
    else
        return 0;
}

static inline void set_ftz(void)
{
    uint32_t fpcr;

    __asm__ __volatile__("mrs %0,fpcr" : "=r" (fpcr));
    fpcr |= FLUSH_TO_ZERO_MASK;
    __asm__ __volatile__("msr fpcr,%0" : :"ri" (fpcr));
}
#endif
