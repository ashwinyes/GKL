package com.intel.gkl.smithwaterman;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import com.intel.gkl.IntelGKLUtils;
import com.intel.gkl.NativeLibraryLoader;

import org.broadinstitute.gatk.nativebindings.smithwaterman.SWParameters;
import org.broadinstitute.gatk.nativebindings.smithwaterman.SWOverhangStrategy;
import org.broadinstitute.gatk.nativebindings.smithwaterman.SWAlignerNativeBinding;

import htsjdk.samtools.Cigar;
import htsjdk.samtools.CigarElement;
import htsjdk.samtools.CigarOperator;
import org.broadinstitute.gatk.nativebindings.smithwaterman.SWNativeAlignerResult;

import java.io.File;
import java.lang.Object;
import java.nio.charset.Charset;
import java.util.Arrays;

/**
 * Provides a native SmithWaterman implementation accelerated for the Intel Architecture.
 */

public class IntelSmithWaterman implements SWAlignerNativeBinding {

    public IntelSmithWaterman() {
    }


    /**
            * Loads the native library, if it is supported on this platform. <p>
    * Returns false if AVX is not supported. <br>
    * Returns false if the native library cannot be loaded for any reason. <br>
    *
            * @param tempDir  directory where the native library is extracted or null to use the system temp directory
    * @return  true if the native library is supported and loaded, false otherwise
    */

    @Override
    public synchronized boolean load(File tempDir) {
        return false;
    }


    /**
     *Implements the native implementation of SmithWaterman, and returns the Cigar String and alignment_offset
     *
     * @param refArray array of reference data
     * @param altArray array of alternate data
     *
     */

    @Override
    public SWNativeAlignerResult align(byte[] refArray, byte[] altArray, SWParameters parameters, SWOverhangStrategy overhangStrategy)
    {
        return null;
    }


}

