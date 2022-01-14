#version 330 core

layout(location = 0) in vec4 a_pos;
layout(location = 1) in vec4 a_col;
layout(location = 2) in vec2 a_tex;
layout(location = 3) in float a_tex_index;

uniform mat4 u_view;
uniform mat4 u_proj;

out vec4 f_col;
out vec2 f_tex;
out float f_tex_index;

void main()
{
    f_col = a_col;
    f_tex = a_tex;
    f_tex_index = a_tex_index;

    vec4 transformed_vertex = a_pos;

    transformed_vertex = transformed_vertex * u_view;
    transformed_vertex = transformed_vertex * u_proj;

    gl_Position = transformed_vertex;
}