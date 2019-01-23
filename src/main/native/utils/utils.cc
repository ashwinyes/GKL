#ifdef linux
  #include <omp.h>
#endif
#include <neon.h>
#include "utils.h"


/*
 * Class:     com_intel_gkl_IntelGKLUtils
 * Method:    getFlushToZeroNative
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_intel_gkl_IntelGKLUtils_getFlushToZeroNative
  (JNIEnv *env, jobject obj)
{
    bool ret;

    if (get_ftz())
        ret = true;
    else
        ret = false;

    return ret;
}

/*
 * Class:     com_intel_gkl_IntelGKLUtils
 * Method:    setFlushToZeroNative
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_intel_gkl_IntelGKLUtils_setFlushToZeroNative
  (JNIEnv *env, jobject obj, jboolean value)
{
    set_ftz();
}

/*
 * Class:     com_intel_gkl_IntelGKLUtils
 * Method:    getAvailableOmpThreadsNative
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_intel_gkl_IntelGKLUtils_getAvailableOmpThreadsNative
  (JNIEnv *env, jobject obj)
{
#ifdef _OPENMP
    int avail_threads = omp_get_max_threads();
#else
    int avail_threads = 0;
#endif

    return avail_threads;
}
