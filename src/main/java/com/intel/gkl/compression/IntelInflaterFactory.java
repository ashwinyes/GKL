package com.intel.gkl.compression;

import htsjdk.samtools.util.zip.InflaterFactory;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.File;
import java.util.zip.Inflater;

/**
 * Created by pnvaidya on 2/1/17.
 */
public class IntelInflaterFactory extends InflaterFactory {
    private final static Logger logger = LogManager.getLogger(IntelDeflaterFactory.class);
    private boolean intelInflaterSupported;

    public IntelInflaterFactory(File tmpDir) {
        intelInflaterSupported = false;
    }

    public IntelInflaterFactory() {
        this(null);
    }

    public Inflater makeInflater(final boolean nowrap) {
        logger.warn("IntelInflater is not supported, using Java.util.zip.Inflater");
        return new IntelInflater(nowrap);
    }

    public boolean usingIntelInflater() {
        return intelInflaterSupported;
    }
}
