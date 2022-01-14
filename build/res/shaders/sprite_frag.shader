#version 330 core

uniform sampler2D sampler[32];

in vec4 f_col;
in vec2 f_tex;
in float f_tex_index;

out vec4 color;

void main()
{
    vec4 texel = texture(sampler[int(f_tex_index)], f_tex) * f_col;

    if(texel.w < 0.1)
        discard;

    color = texel;
}