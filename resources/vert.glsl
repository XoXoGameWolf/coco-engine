#version 310 es

uniform mat4 mat;

in vec3 pos;
in vec2 coord;
out vec2 coord_int;

void main() {
    coord_int = coord;
    gl_Position = mat * vec4(pos, 1.0f);
}