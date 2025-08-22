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
    object->pos_x = sin(3.0f * glfwGetTime());
    setColorProperty(object, 
        sin(3.0f * glfwGetTime()) / 2.0f + 0.5f, 
        sin(3.0f * glfwGetTime() + 10.0f) / 2.0f + 0.5f, 
        sin(3.0f * glfwGetTime() + 20.0f) / 2.0f + 0.5f,
        "col"
    );

    if(glfwGetKey(window, GLFW_KEY_W)) {
        cam_pos_z += 0.1f;
    }
    if(glfwGetKey(window, GLFW_KEY_A)) {
        cam_pos_x -= 0.1f;
    }
    if(glfwGetKey(window, GLFW_KEY_S)) {
        cam_pos_z -= 0.1f;
    }
    if(glfwGetKey(window, GLFW_KEY_D)) {
        cam_pos_x += 0.1f;
    }
    if(glfwGetKey(window, GLFW_KEY_E)) {
        cam_pos_y += 0.1f;
    }
    if(glfwGetKey(window, GLFW_KEY_Q)) {
        cam_pos_y -= 0.1f;
    }

    if(glfwGetKey(window, GLFW_KEY_LEFT)) {
        cam_rot_y -= 0.5f;
    }
    if(glfwGetKey(window, GLFW_KEY_RIGHT)) {
        cam_rot_y += 0.5f;
    }
    if(glfwGetKey(window, GLFW_KEY_DOWN)) {
        cam_rot_x += 0.5f;
    }
    if(glfwGetKey(window, GLFW_KEY_UP)) {
        cam_rot_x -= 0.5f;
    }
}