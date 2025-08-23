#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include <jni.h>
#include <android/log.h>
#include <GLES3/gl32.h>

void start();
void update();

int width = 1280;
int height = 720;

bool lastFullscreen = false;
bool fullscreen = false;
bool open = true;

JNIEnv* env;
jobject res;

#include <coco/renderer.c>
#include <coco/objects.c>
#include <coco/window.c>