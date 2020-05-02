#version 330 core

in vec2 vertex_position;
in vec4 vertex_color;

uniform mat4 transformation;

out vec4 interpolated_color;

void main()
{
    vec4 vertex_position_transformed = transformation * vec4(vertex_position.xy, 1.0, 1.0);

    gl_Position        = vertex_position_transformed;
    interpolated_color = vertex_color;
}