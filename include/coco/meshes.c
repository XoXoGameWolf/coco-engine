#pragma once

float QUAD_VERTICES[] = {
    0.5f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f, 0.5f, 0.0f
};

float QUAD_COORDS[] = {
    1.0f, 0.0f,
    1.0f, 1.0f,
    0.0f, 1.0f,
    0.0f, 0.0f
};

int QUAD_INDICES[] = {
    0, 1, 3,
    1, 2, 3
};

Mesh* quad;

Mesh* getQuadMesh() {
    if(quad == NULL) {
        quad = createMeshFast(
            QUAD_VERTICES, sizeof(QUAD_VERTICES),
            QUAD_COORDS, sizeof(QUAD_COORDS),
            QUAD_INDICES, sizeof(QUAD_INDICES)
        );
    }

    return quad;
}