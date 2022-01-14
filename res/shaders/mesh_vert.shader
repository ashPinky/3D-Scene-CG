#version 330 core

layout(location = 0) in vec3 a_pos;
layout(location = 1) in vec2 a_tex;
layout(location = 2) in vec3 a_norm;

uniform mat4 u_view;
uniform mat4 u_proj;
uniform mat4 u_model;

out vec2 f_tex;
out vec3 f_norm;

void main()
{
    f_tex = a_tex;
    f_norm = a_norm;

    vec4 transformed_vertex = vec4(a_pos.x, a_pos.y, a_pos.z, 1.0);

    transformed_vertex = transformed_vertex * u_model;
    transformed_vertex = transformed_vertex * u_view;
    transformed_vertex = transformed_vertex * u_proj;

    gl_Position = transformed_vertex;
}