char* title = "Coco Engine";
float bg_red = 0.0f;
float bg_green = 0.0f;
float bg_blue = 0.0f;

#include <coco/coco.c>

Texture* tex;
Object* object;

void start() {
    object = createTextured3D(getQuadMesh(), 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
    setTextureProperty(object, createTexture("resources/test.bmp", false), "tex");
}

void update() {
    object->rot_z = glfwGetTime() * 100.0f;
}