package com.redknot.tool;

import android.content.res.AssetManager;

/**
 * Created by yuqiaomiao on 20/03/2017.
 */

public class NativeMethod {
    static{
        System.loadLibrary("redgameengine");
    }
    public native static void start(AssetManager mgr);
    public native static void update();
}
