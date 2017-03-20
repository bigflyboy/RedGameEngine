package com.redknot.redgameengine;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.Log;
import android.view.Window;
import android.view.WindowManager;

public class MainActivity extends Activity {

    private GLSurfaceView main_glsurfaceview;
    private final int CONTEXT_CLIENT_VERSION = 3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        setContentView(R.layout.activity_main);

        main_glsurfaceview = (GLSurfaceView) findViewById(R.id.main_glsurfaceview);

        //直接上3.0吧
        if (detectOpenGLES30()) {
            main_glsurfaceview.setEGLContextClientVersion(CONTEXT_CLIENT_VERSION);
            main_glsurfaceview.setRenderer(new DrawRenderer(this));
        } else {
            Log.e("opengles30", "OpenGL ES 3.0 not supported on device.  Exiting...");
            finish();
        }
    }

    private boolean detectOpenGLES30() {
        ActivityManager am = (ActivityManager)getSystemService(Context.ACTIVITY_SERVICE);
        ConfigurationInfo info = am.getDeviceConfigurationInfo();

        return (info.reqGlEsVersion >= 0x30000);
    }

}
