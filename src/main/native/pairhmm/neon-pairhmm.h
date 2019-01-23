#include <stdint.h>
#include "pairhmm_common.h"
#include "Context.h"

#define SIMD_ENGINE neon
#define SIMD_ENGINE_NEON

#include "template.h"

#include "define-neon-double.h"
#include "shift_template.c"
#include "pairhmm-template-kernel.cc"

#include "define-neon-float.h"
#include "shift_template.c"
#include "pairhmm-template-kernel.cc"


template double compute_full_prob_neond<double>(testcase* tc);
template float compute_full_prob_neons<float>(testcase* tc);

