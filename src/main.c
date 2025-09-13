char* title = "Coco Engine";
float bg_red = 0.3f;
float bg_green = 0.6f;
float bg_blue = 0.9f;

#include <coco/coco.c>

Object* object;
Object* cursor;

Audio* audio;
AudioSource* source;

void start() {
    Mesh* sphere = loadMesh("resources/sphere.obj");

    object = createBasicShaded3D(sphere, 0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
    cursor = createTextured2D(quad, 0.0f, 0.0f, 0.0f, 0.03f, 0.03f);
    setTextureProperty(cursor, createTexture("resources/cursor.png", true), "tex", 0);

    cam_pos_z = 0.0001f;

    audio = loadAudio("resources/test.wav");
    source = createAudioSource(audio, 0.0f, 0.0f, 1.0f, true);
}

void update() {
    object->pos_x = sin(3.0f * getTime());
    setColorProperty(object, 
        sin(3.0f * getTime()) / 2.0f + 0.5f, 
        sin(3.0f * getTime() + 10.0f) / 2.0f + 0.5f, 
        sin(3.0f * getTime() + 20.0f) / 2.0f + 0.5f,
        "col"
    );

    if(getKey(KEY_W)) {
        cam_pos_z += 0.1f;
    }
    if(getKey(KEY_A)) {
        cam_pos_x -= 0.1f;
    }
    if(getKey(KEY_S)) {
        cam_pos_z -= 0.1f;
    }
    if(getKey(KEY_D)) {
        cam_pos_x += 0.1f;
    }
    if(getKey(KEY_E)) {
        cam_pos_y += 0.1f;
    }
    if(getKey(KEY_Q)) {
        cam_pos_y -= 0.1f;
    }

    cursor->pos_x = cam_pos_x;
    cursor->pos_y = cam_pos_y;
    cursor->scl_x = 0.03f / cam_pos_z;
    cursor->scl_y = 0.03f / cam_pos_z;

    cam_rot_y = getMouseX() * 45.0f;
    cam_rot_x = getMouseY() * 45.0f;

    setAudioSourcePos(source, cam_pos_x, cam_pos_y, cam_pos_z);
}