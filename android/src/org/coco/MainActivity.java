package org.coco;

import android.app.Activity;
import android.app.ActionBar;
import android.os.Bundle;
import android.opengl.GLSurfaceView;
import android.opengl.GLSurfaceView.Renderer;
import android.content.Context;
import android.content.res.Resources;

import javax.microedition.khronos.opengles.GL10;
import javax.microedition.khronos.opengles.GL11;
import javax.microedition.khronos.egl.EGLConfig;

public class MainActivity extends Activity {
    public static native void start(Resources res);
    public static native void update(Resources res);
    public static native void render(Resources res);

    public static native void size(Resources res, int width, int height);

    public class RendererImpl implements Renderer {
        public void onSurfaceCreated(GL10 gl, EGLConfig config) {
            start(getResources());
        }

        public void onSurfaceChanged(GL10 gl, int width, int height) {
            size(getResources(), width, height);
        }

        public void onDrawFrame(GL10 gl) {
            update(getResources());
            render(getResources());
        }
    }

    public class ViewImpl extends GLSurfaceView {
        public RendererImpl renderer;

        public ViewImpl(Context context) {
            super(context);

            setEGLConfigChooser(8, 8, 8, 8, 24, 8);
            setEGLContextClientVersion(3);

            renderer = new RendererImpl();
            setRenderer(renderer);
        }
    }

    public ViewImpl view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        System.loadLibrary("coco");

        view = new ViewImpl(this);
        setContentView(view);

        ActionBar actionBar = getActionBar();
        if(actionBar != null) {
            actionBar.hide();
        }
    }
}