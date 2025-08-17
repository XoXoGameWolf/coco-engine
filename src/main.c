char* title = "Coco Engine";
float bg_red = 0.3f;
float bg_green = 0.6f;
float bg_blue = 0.9f;

#include <coco/coco.c>

Object* object;

void start() {
    Mesh* sphere = loadMesh("resources/sphere.obj");

    object = createBasicShaded3D(sphere, 0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
}

void update() {
    object->pos_x = 2.5f * sin(3.0f * glfwGetTime());
    object->rot_y = 100.0f * glfwGetTime();
    setColorProperty(object, 
        sin(3.0f * glfwGetTime()) / 2.0f + 0.5f, 
        sin(3.0f * glfwGetTime() + 10.0f) / 2.0f + 0.5f, 
        sin(3.0f * glfwGetTime() + 20.0f) / 2.0f + 0.5f,
        "col"
    );
}