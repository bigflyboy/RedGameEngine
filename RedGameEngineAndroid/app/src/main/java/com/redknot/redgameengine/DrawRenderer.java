package com.redknot.redgameengine;

import android.content.Context;
import android.content.res.AssetManager;
import android.opengl.GLSurfaceView;

import com.redknot.tool.NativeMethod;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by yuqiaomiao on 20/03/2017.
 */

public class DrawRenderer implements GLSurfaceView.Renderer {

    private Context context;
    private AssetManager mgr;

    public DrawRenderer(Context context) {
        this.context = context;
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {

    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        mgr = context.getResources().getAssets();
        NativeMethod.start(mgr);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        NativeMethod.update();
    }
}
