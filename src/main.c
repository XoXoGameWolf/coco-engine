char* title = "Coco Engine";

#include <coco/coco.c>

Mesh* mesh;
Shader* shader;
Texture* tex;

float mat[16];

void start() {
    renderer_init(0.2f, 0.4f, 0.6f);

    tex = renderer_createTexture("resources/test.bmp", false);
    mesh = renderer_createMeshFast(
        QUAD_VERTICES, sizeof(QUAD_VERTICES),
        QUAD_COORDS, sizeof(QUAD_COORDS),
        QUAD_INDICES, sizeof(QUAD_INDICES)
    );
    shader = renderer_createShader("resources/vert.glsl", "resources/frag.glsl");
}

void update() {
    
}

void render() {
    renderer_createMat4Scale(mat, 1.0f, (float)window_width / (float)window_height, 1.0f);

    renderer_setUniformTexture(shader, "tex", tex, 0);
    renderer_setUniformMat4(shader, "mat", mat);

    renderer_update();
    renderer_renderMesh(mesh, shader);
}