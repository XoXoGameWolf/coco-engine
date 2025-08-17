char* title = "Coco Engine";
float bg_red = 0.3f;
float bg_green = 0.6f;
float bg_blue = 0.9f;

#include <coco/coco.c>

Object* object1;
Object* object2;
Object* object3;

void start() {
    Mesh* sphere = loadMesh("resources/sphere.obj");

    object1 = createBasicShaded3D(sphere, -2.5f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
    setColorProperty(object1, 0.8f, 0.2f, 0.2f, "col");

    object2 = createBasicShaded3D(sphere, 0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
    setColorProperty(object2, 0.2f, 0.8f, 0.2f, "col");

    object3 = createBasicShaded3D(sphere, 2.5f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
    setColorProperty(object3, 0.2f, 0.2f, 0.8f, "col");
}

void update() {
    //object->rot_x = glfwGetTime() * 100.0f;
    //object->rot_y = glfwGetTime() * 100.0f + 10.0f;
    //object->rot_z = glfwGetTime() * 100.0f + 20.0f;
}