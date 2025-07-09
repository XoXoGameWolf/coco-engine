#include <coco/coco.h>

int main() {
    window_init("Coco Engine", 1600, 900);
    renderer_init(0.2f, 0.4f, 0.6f);

    window_fullscreen = true;

    Texture* tex = renderer_createTexture("resources/test.png");
    Mesh* mesh = renderer_createMeshFast(
        QUAD_VERTICES, sizeof(QUAD_VERTICES), 
        QUAD_COORDS, sizeof(QUAD_COORDS), 
        QUAD_INDICES, sizeof(QUAD_INDICES)
    );
    Shader* shader = renderer_createShader("resources/vert.glsl", "resources/frag.glsl");

    float mat[16];

    while(window_open) {
        renderer_createMat4Scale(mat, 1.0f, (float)window_width / (float)window_height, 1.0f);

        renderer_setUniformTexture(shader, "tex", tex, 0);
        renderer_setUniformMat4(shader, "mat", mat);
        
        renderer_update();
        renderer_renderMesh(mesh, shader);
        window_update();
    }

    //renderer_destroy();
    window_destroy();
    return 0;
}