#version 310 es
precision mediump float;

uniform sampler2D tex;

in vec2 coord_int;
out vec4 color;

void main() {
    color = texture(tex, coord_int);
}