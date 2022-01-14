#version 330 core

layout(location = 0) in vec4 a_pos;
layout(location = 1) in vec4 a_col;

uniform mat4 u_view;
uniform mat4 u_proj;

out vec4 f_col;

void main()
{
    f_col = a_col;

    vec4 transformed_vertex = a_pos;

    transformed_vertex = transformed_vertex * u_view;
    transformed_vertex = transformed_vertex * u_proj;

    gl_Position = transformed_vertex;
}