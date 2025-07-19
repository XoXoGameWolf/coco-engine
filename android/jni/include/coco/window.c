#pragma once

typedef struct {
    
} GLFWwindow;

GLFWwindow* window_window;

JNIEnv* env;
jobject res;

int window_width = 1280;
int window_height = 720;

void Java_org_coco_MainActivity_start(JNIEnv* _env, jclass cls, jobject _res) {
    env = _env;
    res = _res;
    start();
}

void Java_org_coco_MainActivity_update(JNIEnv* _env, jclass cls, jobject _res) {
    env = _env;
    res = _res;
    update();
}

void Java_org_coco_MainActivity_render(JNIEnv* _env, jclass cls, jobject _res) {
    env = _env;
    res = _res;
    render();
}

void Java_org_coco_MainActivity_size(JNIEnv* _env, jclass cls, jobject _res, jint width, jint height) {
    env = _env;
    res = _res;
    window_width = width;
    window_height = height;
    glViewport(0, 0, (int)width, (int)height);
}